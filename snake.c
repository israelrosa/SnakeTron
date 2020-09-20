#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "snake.h"
#include "apple.h"
#include "direction.h"
#include "console.h"
#include "printer.h"

struct snake {
    Position* head;
    Position* tail;
    Direction* direction;
    int player;
};

Position* getTail(Snake* snake) {
    return snake->tail;
}

Position* getHead(Snake* snake) {
    return snake->head;
}

Snake* createSnake(int xPos, int yPos, int player) {
    Snake* snake = (Snake*) malloc(sizeof(Snake));
    snake->direction = createDirection();
    snake->head = createPosition(xPos * OFFSETX, yPos);
    snake->tail = snake->head;
    snake->player = player;

    return snake;
}

void printSnake(Snake* snake) {
    int i = 0;

    while(i <= 1) {
        gotoxy(getXPos(snake->head) + i, getYPos(snake->head));
        if(snake->player == 1) {
                setBackgroundColor(COLOR_RED);
        }else {
            setBackgroundColor(COLOR_GREEN);
        }

        printf(" ");

        i++;
    }

    i = 0;

    while(i <= 1) {
        gotoxy(getXPos(getTail(snake)) + i, getYPos(getTail(snake)));
        if(snake->player == 1) {
                setBackgroundColor(COLOR_RED);
        }else {
            setBackgroundColor(COLOR_GREEN);
        }

        printf(" ");

        i++;
    }


}

void releaseSnake(Snake* snake) {
    gotoxy(getXPos(snake->tail), getYPos(snake->tail));
    setBackgroundColor(COLOR_BLACK);
    printf(" ");
    gotoxy(getXPos(snake->tail)+1, getYPos(snake->tail));
    setBackgroundColor(COLOR_BLACK);
    printf(" ");

}

void deleteSnake(Snake* snake) {
    Position* pos = getTail(snake);
    Position* prev;

    while(pos != NULL) {
        prev = pos;
        pos = getNextPos(pos);
        free(pos);
    }
}

bool checkColision(Snake* snake, int width, int height, int opt) {
    if (getXPos(snake->head) + getXDir(snake->direction) >= (width * OFFSETX) - 1 || getXPos(snake->head) + getXDir(snake->direction) < 2) {
        if(snake->player == 1){
            printMessage(width, height, "Player 1 colidiu contra a parede.", COLOR_BLUE);
            if(opt != 1) {
                printWins(width * 2 + 28, 15);
            }

        } else {
            printMessage(width, height, "Player 2 colidiu contra a parede.", COLOR_BLUE);
            printWins(width * 2 + 26, 5);
        }

        return true;
    } else if (getYPos(snake->head) + getYDir(snake->direction) == height || getYPos(snake->head) + getYDir(snake->direction) == 0) {
        if(snake->player == 1){
            printMessage(width, height, "Player 1 colidiu contra a parede.", COLOR_BLUE);
            if(opt != 1) {
                printWins(width * 2 + 28, 15);
            }
        } else {
            printMessage(width, height, "Player 2 colidiu contra a parede.", COLOR_BLUE);
            printWins(width * 2 + 26, 5);
        }

        return true;
    } else if (getXDir(snake->direction) == 0 && getYDir(snake->direction) == 0) {
        return false;
    } else {
        for (Position* tail = snake->tail; getNextPos(tail) != NULL; tail = getNextPos(tail)) {
            if (getXPos(snake->head) == getXPos(tail) && getYPos(snake->head) == getYPos(tail)) {
                if(snake->player == 1){
                    printMessage(width, height, "Player 1 colidiu consigo mesmo.", COLOR_BLUE);
                    if(opt != 1) {
                        printWins(width * 2 + 28, 15);
                    }
                } else {
                    printMessage(width, height, "Player 2 colidiu consigo mesmo.", COLOR_BLUE);
                    printWins(width * 2 + 26, 5);
                }

                return true;
            }
        }
    }
    return false;
}

bool checkPlayersColision(Snake* player1, Snake* player2, int width, int height, int applesP1, int applesP2) {
    for(Position* tail = player1->tail; getNextPos(tail) != NULL; tail = getNextPos(tail)) {
        if(getXPos(player2->head) == getXPos(tail) && getYPos(player2->head) == getYPos(tail)) {

            printMessage(width, height, "Player 2 morreu!", COLOR_BLUE);
            printWins(width * 2 + 26, 5);


            return true;
        }
    }
    for(Position* tail = player2->tail; getNextPos(tail) != NULL; tail = getNextPos(tail)) {
        if(getXPos(player1->head) == getXPos(tail) && getYPos(player1->head) == getYPos(tail)) {
                printMessage(width, height, "Player 1 morreu!", COLOR_BLUE);
                printWins(width * 2 + 28, 15);
            return true;
        }
    }
    if(getXPos(player2->head) == getXPos(player1->head) && getYPos(player2->head) == getYPos(player1->head)) {
                if(applesP1 > applesP2) {
                    printMessage(width, height, "Player 2 morreu!", COLOR_BLUE);
                    printWins(width * 2 + 26, 5);
                } else if(applesP1 < applesP2) {
                    printMessage(width, height, "Player 1 morreu!", COLOR_BLUE);
                    printWins(width * 2 + 28, 15);
                } else {
                    printMessage(width, height, "Player 1 e Player 2 morreram.", COLOR_BLUE);
                }

        return true;
    }
    return false;
}

void updateBody(Snake* snake) {
    for (Position* tail = snake->tail; getNextPos(tail) != NULL; tail = getNextPos(tail)) {
        insertXPos(tail, getXPos(getNextPos(tail)));
        insertYPos(tail, getYPos(getNextPos(tail)));
    }

    int resultX = getXPos(snake->head) + (getXDir(snake->direction)*2);
    int resultY = getYPos(snake->head) + getYDir(snake->direction);

    insertXPos(snake->head, resultX);
    insertYPos(snake->head, resultY);
}

 void updateDirection(Snake* snake, int key) {
    if (snake->player == 1) {
        switch(key){
            case TECLA_CIMA:
                if(getYDir(snake->direction) > 0){
                    return;
                } else {
                    insertXDir(snake->direction, 0);
                    insertYDir(snake->direction, -1);
                }
                break;
            case TECLA_BAIXO:
                if(getYDir(snake->direction) < 0){
                    return;
                } else {
                    insertXDir(snake->direction, 0);
                    insertYDir(snake->direction, 1);
                }
                break;
            case TECLA_DIREITA:
                if(getXDir(snake->direction) < 0){
                    return;
                } else {
                    insertXDir(snake->direction, 1);
                    insertYDir(snake->direction, 0);
                }
                break;
            case TECLA_ESQUERDA:
                if(getXDir(snake->direction) > 0){
                    return;
                } else {
                    insertXDir(snake->direction, -1);
                    insertYDir(snake->direction, 0);
                }
                break;
        }
    } else if(snake->player == 2) {
        switch(key){
            case TECLA_W:
                if(getYDir(snake->direction) > 0){
                    return;
                } else {
                    insertXDir(snake->direction, 0);
                    insertYDir(snake->direction, -1);
                }
                break;
            case TECLA_S:
                if(getYDir(snake->direction) < 0){
                    return;
                } else {
                    insertXDir(snake->direction, 0);
                    insertYDir(snake->direction, 1);
                }
                break;
            case TECLA_D:
                if(getXDir(snake->direction) < 0){
                    return;
                } else {
                    insertXDir(snake->direction, 1);
                    insertYDir(snake->direction, 0);
                }
                break;
            case TECLA_A:
                if(getXDir(snake->direction) > 0){
                    return;
                } else {
                    insertXDir(snake->direction, -1);
                    insertYDir(snake->direction, 0);
                }
                break;
        }
    }
}

void snakeFeed(Snake* snake) {
    int resultX = getXPos(snake->tail) - (getXDir(snake->direction) * OFFSETX);
    int resultY = getYPos(snake->tail) - getYDir(snake->direction);

    Position* newTail = createPosition(resultX, resultY);

    insertNextPos(newTail, snake->tail);
    snake->tail = newTail;
}


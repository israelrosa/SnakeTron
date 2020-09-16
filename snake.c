#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "snake.h"
#include "direction.h"
#include "position.h"
#include "console.h"

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
    for(Position* tail = snake->tail; getProxPos(tail) != NULL; tail = getProxPos(tail)) {
        gotoxy(getXPos(tail), getYPos(tail));

        if(snake->player == 1) {
            setBackgroundColor(COLOR_RED);
        }else {
            setBackgroundColor(COLOR_GREEN);
        }
        printf(" ");

        gotoxy(getXPos(tail) + 1, getYPos(tail));

        if(snake->player == 1) {
            setBackgroundColor(COLOR_RED);
        }else {
            setBackgroundColor(COLOR_GREEN);
        }
        printf(" ");
    }
        gotoxy(getXPos(snake->head), getYPos(snake->head));
        if(snake->player == 1) {
            setBackgroundColor(COLOR_RED);
        }else {
            setBackgroundColor(COLOR_GREEN);
        }
        printf(" ");

        gotoxy(getXPos(snake->head) + 1, getYPos(snake->head));
        if(snake->player == 1) {
            setBackgroundColor(COLOR_RED);
        }else {
            setBackgroundColor(COLOR_GREEN);
        }
        printf(" ");
}

void releaseSnake(Snake* snake) {
    gotoxy(getXPos(snake->tail), getYPos(snake->tail));
    setBackgroundColor(COLOR_BLACK);
    printf(" ");
    gotoxy(getXPos(snake->tail)+1, getYPos(snake->tail));
    setBackgroundColor(COLOR_BLACK);
    printf(" ");

}

bool checkColision(Snake* snake, int width, int height) {
        if (getXPos(snake->head) + getXDir(snake->direction) >= (width * OFFSETX) -1 || getXPos(snake->head) + getXDir(snake->direction) < 2) {
        gotoxy(20, 20);
        printf("aqui 1");
        return true;
    } else if (getYPos(snake->head) + getYDir(snake->direction) == height || getYPos(snake->head) + getYDir(snake->direction) == 0) {
        gotoxy(20, 20);
        printf("aqui 2");
        return true;
    } else if (getXDir(snake->direction) == 0 && getYDir(snake->direction) == 0) {
        return false;
    } else {
        for (Position* tail = snake->tail; getProxPos(tail) != NULL; tail = getProxPos(tail)) {
            if (getXPos(snake->head) == getXPos(tail) && getYPos(snake->head) == getYPos(tail)) {
                gotoxy(20, 20);
                printf("aqui 3");
                return true;
            }
        }
    }
    return false;
}

bool checkPlayersColision(Snake* player1, Snake* player2) {
    for(Position* tail = player1->tail; getProxPos(tail) != NULL; tail = getProxPos(tail)) {
        if(getXPos(player2->head) == getXPos(tail) && getYPos(player2->head) == getYPos(tail)) {
            return true;
        }
    }
    for(Position* tail = player2->tail; getProxPos(tail) != NULL; tail = getProxPos(tail)) {
        if(getXPos(player1->head) == getXPos(tail) && getYPos(player1->head) == getYPos(tail)) {
            return true;
        }
    }
    if(getXPos(player2->head) == getXPos(player1->head) && getYPos(player2->head) == getYPos(player1->head)) {
        return true;
    }
    return false;
}

void updateBody(Snake* snake) {
    for (Position* tail = snake->tail; getProxPos(tail) != NULL; tail = getProxPos(tail)) {
        insertXPos(tail, getXPos(getProxPos(tail)));
        insertYPos(tail, getYPos(getProxPos(tail)));
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

    insertProxPos(newTail, snake->tail);
    snake->tail = newTail;
}

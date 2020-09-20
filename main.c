#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <windows.h>
#include "console.h"
#include "map.h"
#include "snake.h"
#include "apple.h"
#include "printer.h"

int borderx;
int bordery;

int sizeX, sizeY;

void printPointsPlayer1(int apples) {
    gotoxy(borderx * 2 + 10, 11);
    setBackgroundColor(COLOR_BLACK);
    setColor(COLOR_WHITE);
    printf("Apples: %d", apples);
}

void printPointsPlayer2(int apples) {
    gotoxy(borderx * 2 + 10, 21);
    setBackgroundColor(COLOR_BLACK);
    setColor(COLOR_WHITE);
    printf("Apples: %d", apples);
}

void appleGenerate(Apple* apple, Snake* player1, Snake* player2) {
    bool isEmpty = false;
    bool isEmptyP1 = false;
    bool isEmptyP2 = false;

    while (!isEmpty)
    {
        drawApple(apple, borderx, bordery);
        isEmptyP1 = checkPosition(apple, player1, borderx, bordery);
        isEmptyP2 = checkPosition(apple, player2, borderx, bordery);

        if(!isEmptyP1 || !isEmptyP2) {
            isEmpty = false;
        } else {
            isEmpty = true;
        }
    }
}

void init() {
    runCursor(borderx, bordery);
    setBackgroundColor(COLOR_BLACK);
    system("cls");
}

void controller() {
    bool opt = true;
    while(opt) {
        int key = getch();

        switch(key) {
            case TECLA_ESC:
                gotoxy(0, sizeY);
                exit(0);
            case TECLA_ENTER:
                opt = false;
                break;
            case TECLA_n:
                opt = false;
                break;
        }
    }
}

void play(int opt) {
    bool alive = true;
    Snake* player1 = createSnake(2, 10, 1);
    Snake* player2 = createSnake(10, 10, 2);
    system("cls");
    init();

    int applesP1 = 0;
    int applesP2 = 0;

    if(opt == 2) {
        printSnake(player1);
        printSnake(player2);

        printP1(borderx * 2 + 10, 5);
        printP2(borderx * 2 + 10, 15);

        printPointsPlayer1(applesP1);
        printPointsPlayer2(applesP2);
    } else {
        printSnake(player1);

        printP1(borderx * 2 + 10, 5);
        printPointsPlayer1(applesP1);
    }
    Apple* apple = createApple();
    printMap(borderx, bordery);

    int key = getch();
    int key2 = true;
    appleGenerate(apple, player1, player2);
    printApple(apple);
    do {
        hideCursor(true);

        if(opt == 2) {
            updateDirection(player2, key);
        }

        if (key2) {
            key = getch();
            updateDirection(player1, key);
            key2 = false;
        }

        if(opt == 2) {
            releaseSnake(player2);
        }

        releaseSnake(player1);

        if (checkColision(player1, borderx, bordery, opt)) {
            alive = false;
        } else if(opt == 2) {
            if(checkColision(player2, borderx, bordery, opt) || checkPlayersColision(player1, player2, borderx, bordery, applesP1, applesP2)){
                alive = false;
            }
        }

        if (alive) {
            updateBody(player1);
            printSnake(player1);
            if(opt == 2) {
                updateBody(player2);
                printSnake(player2);
            }
        }

        if (checkIfAteApple(apple, player1)) {
            snakeFeed(player1);
            appleGenerate(apple, player1, player2);
            printApple(apple);
            applesP1++;
            printPointsPlayer1(applesP1);
        } else if(opt == 2 && checkIfAteApple(apple,player2)) {
            snakeFeed(player2);
            appleGenerate(apple, player1, player2);
            printApple(apple);
            applesP2++;
            printPointsPlayer2(applesP2);
        }

        usleep(60000);

        if(kbhit()) {
            key = getch();
            if (key == TECLA_SETAS) {
                key2 = true;
            }
        }

    } while (alive);
    deleteSnake(player1);
    deleteSnake(player2);
    deleteApple(apple);

    printGameOver(borderx - 34, bordery / 2 - 10);
    controller();

}

void menu() {
    bool playing = true;
    while(playing) {
        setBackgroundColor(COLOR_BLACK);
        system("cls");

        int opt = 0;
        int select = 1;
       do {
            printHorizontalLine(0, sizeY/4 - 10, sizeX -1, 0, COLOR_BLUE );
            gotoxy(sizeX / 2 - 11, sizeY/4 - 8);
            setBackgroundColor(COLOR_BLACK);
            setColor(COLOR_BLUE);
            printf("Bem-vindo ao SnakeTron!");
            printHorizontalLine(0, sizeY/4 - 6, sizeX -1, 0, COLOR_BLUE );
            printSingle((sizeX / 2) - 21, sizeY/4 + 8, select);
            printCoop((sizeX / 2) - 15, sizeY/4 + 15, select);
            gotoxy(1, 1);
            int key;
            hideCursor(true);
            key = getch();

            if(key == TECLA_SETAS) {
                key = getch();
                switch(key) {
                    case TECLA_CIMA:
                        select = 1;
                        break;
                    case TECLA_BAIXO:
                        select = 2;
                        break;
                }
            } else if(key == TECLA_ENTER) {
                opt = select;
            }
        } while (opt == 0);
        play(opt);
    }
}

int main() {
    SetConsoleTitle("SnakeTron");
    maximizeWindow();
    getSizeWindow(&sizeX, &sizeY);
    borderx = (sizeX/3) -1;
    bordery = sizeY - 1;
    menu();
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "console.h"
#include "map.h"
#include "snake.h"
#include "apple.h"

int borderx = 90;
int bordery= 47;

void appleGenerate(Apple* apple, Snake* player1, Snake* player2) {
    bool isEmpty = false;

    while (!isEmpty)
    {
        drawApple(apple, borderx, bordery);
        isEmpty = checkPosition(apple, player1, borderx, bordery);
        isEmpty = checkPosition(apple, player2, borderx, bordery);
    }

}

void init() {
    runCursor(borderx, bordery);
    setWindow(100, 100);
    maximizeWindow();
}

int main() {
    bool onGame = true;

    do {
        bool alive = true;
        Snake* player1 = createSnake(2, 10, 1);
        Snake* player2 = createSnake(10, 10, 2);
        Apple* apple = createApple();
        system("cls");
        init();
        printMap(borderx, bordery);
        printSnake(player1);
        printSnake(player2);
        int key = getch();
        int key2 = true;
        appleGenerate(apple, player1, player2);

        do {
            hideCursor(true);

            updateDirection(player2, key);

            if (key2) {
                key = getch();
                updateDirection(player1, key);
                key2 = false;
            }

            releaseSnake(player1);
            releaseSnake(player2);

            if (checkColision(player2, borderx, bordery) || checkColision(player1, borderx, bordery) || checkPlayersColision(player1, player2)) {
                alive = false;
            }

            if (alive) {
                updateBody(player1);
                printSnake(player1);
                updateBody(player2);
                printSnake(player2);
                printApple(apple);
            }

            if (checkIfAteApple(apple, player1)) {
                snakeFeed(player1);
                releaseApple(apple);
                appleGenerate(apple, player1, player2);
            } else if(checkIfAteApple(apple,player2)) {
                snakeFeed(player2);
                releaseApple(apple);
                appleGenerate(apple, player1, player2);
            }

            usleep(50000);

            if(kbhit())
                key = getch();
                if (key == TECLA_SETAS) {
                    key2 = true;
                }
        } while (alive);

        system("pause");

        releaseSnake(player1);
        releaseSnake(player2);
    } while(onGame);
}



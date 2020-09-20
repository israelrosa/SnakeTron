#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "printer.h"
#include "console.h"

void printSingle(int initialXPos, int initialYPos, int opt) {
    int color;
    color = COLOR_LIGHTMAGENTA;
    if(opt == 1) {
        color = COLOR_WHITE;
    }

    //Letra S
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 0, color);
    printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 5, 0, color);
    printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 0, color);
    printVerticalLine(initialXPos, initialYPos, initialYPos + 2, color);
    printVerticalLine(initialXPos + 4, initialYPos + 2, initialYPos + 4, color);

    //Letra I
    printVerticalLine(initialXPos + 8, initialYPos, initialYPos + 4, color);

    //Letra N
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 12 , color);
    printVerticalLine(initialXPos + 12, initialYPos, initialYPos + 4, color);
    printVerticalLine(initialXPos + 16, initialYPos, initialYPos + 4, color);

    //Letra G
    printVerticalLine(initialXPos + 20, initialYPos, initialYPos + 4, color);
    printVerticalLine(initialXPos + 24, initialYPos + 2, initialYPos + 4, color);
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 20 , color);
    printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 20 , color);

    //Letra L
    printVerticalLine(initialXPos + 28, initialYPos, initialYPos + 4, color);
    printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 28, color);

    //Letra E
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 36, color);
    printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 1, 40, color);
    printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 36, color);
    printVerticalLine(initialXPos + 36, initialYPos, initialYPos + 4, color);

}

void printCoop(int initialXPos, int initialYPos, int opt){
    int color = COLOR_LIGHTMAGENTA;
    if(opt == 2) {
        color = COLOR_WHITE;
    }

    //Letra C
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 0, color);
    printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 0, color);
    printVerticalLine(initialXPos, initialYPos, initialYPos + 4, color);

    //Letra O
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 8, color);
    printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 8, color);
    printVerticalLine(initialXPos + 8, initialYPos, initialYPos + 4, color);
    printVerticalLine(initialXPos + 12, initialYPos, initialYPos + 4, color);

    //Letra O
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 16, color);
    printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 16, color);
    printVerticalLine(initialXPos + 16, initialYPos, initialYPos + 4, color);
    printVerticalLine(initialXPos + 20, initialYPos, initialYPos + 4, color);

    //Letra P
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 3, 24, color);
    printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 5, 24, color);
    printVerticalLine(initialXPos + 24, initialYPos, initialYPos + 4, color);
    printVerticalLine(initialXPos + 28, initialYPos, initialYPos + 1, color);
}

void printGameOver(int initialXPos, int initialYPos) {
    int color = COLOR_LIGHTMAGENTA;
    PlaySound(TEXT("game-over.wav"), NULL, SND_ASYNC);
    Sleep(10);
    //Letra G
        printVerticalLine(initialXPos, initialYPos, initialYPos + 4, color);
        printVerticalLine(initialXPos + 4, initialYPos + 2, initialYPos + 4, color);
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 0 , color);
        printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 0 , color);

    //Letra A
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 8 , color);
        printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 5, 8 , color);
        printVerticalLine(initialXPos + 8, initialYPos, initialYPos + 4, color);
        printVerticalLine(initialXPos + 12, initialYPos, initialYPos + 4, color);

    //Letra M
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 16 , color);
        printVerticalLine(initialXPos + 16, initialYPos, initialYPos + 4, color);
        printVerticalLine(initialXPos + 20, initialYPos, initialYPos + 4, color);
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 20 , color);
        printVerticalLine(initialXPos + 24, initialYPos, initialYPos + 4, color);

    //Letra E
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 28, color);
        printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 1, 32, color);
        printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 28, color);
        printVerticalLine(initialXPos + 28, initialYPos, initialYPos + 4, color);

    //Letra O
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 40 , color);
        printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 40 , color);
        printVerticalLine(initialXPos + 40, initialYPos, initialYPos + 4, color);
        printVerticalLine(initialXPos + 44, initialYPos, initialYPos + 4, color);

    //Letra V
        printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 1, 50 , color);
        printVerticalLine(initialXPos + 48, initialYPos, initialYPos + 3, color);
        printVerticalLine(initialXPos + 52, initialYPos, initialYPos + 3, color);

    //Letra E
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 56, color);
        printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 1, 60, color);
        printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 56, color);
        printVerticalLine(initialXPos + 56, initialYPos, initialYPos + 4, color);

    //Letra R
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 64 , color);
        printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 5, 64 , color);
        printVerticalLine(initialXPos + 64, initialYPos, initialYPos + 4, color);
        printVerticalLine(initialXPos + 68, initialYPos, initialYPos + 3, color);
}

void printP1(int initialXPos, int initialYPos) {
    int color = COLOR_RED;

    //Letra P
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 3, 0, color);
    printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 5, 0, color);
    printVerticalLine(initialXPos, initialYPos, initialYPos + 4, color);
    printVerticalLine(initialXPos + 4, initialYPos, initialYPos + 1, color);

    //Número 1
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 2, 8, color);
    printVerticalLine(initialXPos + 10, initialYPos, initialYPos + 4, color);



}

void printP2(int initialXPos, int initialYPos) {
    int color = COLOR_GREEN;

    //Letra P
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 3, 0, color);
    printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 5, 0, color);
    printVerticalLine(initialXPos, initialYPos, initialYPos + 4, color);
    printVerticalLine(initialXPos + 4, initialYPos, initialYPos + 1, color);

    //Número 2
    printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 8, color);
    printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 5, 8, color);
    printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 8, color);
    printVerticalLine(initialXPos + 12, initialYPos, initialYPos + 2, color);
    printVerticalLine(initialXPos + 8, initialYPos + 2, initialYPos + 4, color);
}

void printWins(int initialXPos, int initialYPos) {
    int color = COLOR_WHITE;

    //Letra W
        printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 9, 0 , color);
        printVerticalLine(initialXPos, initialYPos, initialYPos + 4, color);
        printVerticalLine(initialXPos + 4, initialYPos, initialYPos + 4, color);
        printVerticalLine(initialXPos + 8, initialYPos, initialYPos + 4, color);
    //Letra I
        printVerticalLine(initialXPos + 12, initialYPos, initialYPos + 4, color);
    //Letra N
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 16 , color);
        printVerticalLine(initialXPos + 16, initialYPos, initialYPos + 4, color);
        printVerticalLine(initialXPos + 20, initialYPos, initialYPos + 4, color);
    //Letra S
        printHorizontalLine(initialXPos, initialYPos, initialXPos + 5, 24, color);
        printHorizontalLine(initialXPos, initialYPos + 2, initialXPos + 5, 24, color);
        printHorizontalLine(initialXPos, initialYPos + 4, initialXPos + 5, 24, color);
        printVerticalLine(initialXPos + 24, initialYPos, initialYPos + 2, color);
        printVerticalLine(initialXPos + 28, initialYPos + 2, initialYPos + 4, color);
}

void printMessage(int width, int height, char message[32], int color) {
    int length = strlen(message);
    printHorizontalLine(0, height / 2 -4, width * OFFSETX + 1, 0, color);
    gotoxy(width - (length / 2) , height / 2 - 2);
    setBackgroundColor(COLOR_BLACK);
    printf("%s", message);
    printHorizontalLine(0, height / 2 , width * OFFSETX + 1, 0, color);

}

void printHorizontalLine(int xPos, int yPos, int finalXPos, int space, int color) {
    for(int i = xPos; i <= finalXPos; i++) {
        gotoxy(i + space, yPos);
        setBackgroundColor(color);
        printf(" ");
    }
}

void printVerticalLine(int xPos, int yPos, int finalYPos, int color) {
    for(int i = yPos; i <= finalYPos; i++) {
        gotoxy(xPos, i);
        setBackgroundColor(color);
        printf(" ");

        gotoxy(xPos + 1, i);
        setBackgroundColor(color);
        printf(" ");
    }
}

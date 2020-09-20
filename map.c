#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "console.h"

void printMap(int width, int height) {
    width *= 2;
    for (int i=0; i<= width; i++) {
        gotoxy(i, 0);
        setBackgroundColor(COLOR_BLUE);
        printf(" ");
        gotoxy(i, height);
        setBackgroundColor(COLOR_BLUE);
        printf(" ");
        if(i == 0 || i == width){
            for (int ii = 0; ii<=height; ii++) {
                gotoxy(i, ii);
                setBackgroundColor(COLOR_BLUE);
                printf(" ");
                gotoxy(i + 1, ii);
                setBackgroundColor(COLOR_BLUE);
                printf(" ");
                if(ii % 2 == 0){
                    usleep(5000);
                }
            }
        }
        usleep(5000);
    }
}

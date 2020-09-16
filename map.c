#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "console.h"

void printMap(int width, int height) {
    width = (width * OFFSETX) + 1;
    for (int i=0; i<=width; i++) {
        gotoxy(i, 0);
        setBackgroundColor(COLOR_BLUE);
        printf(" ");
        gotoxy(i, height);
        setBackgroundColor(COLOR_BLUE);
        printf(" ");
        if(i == 0 || i == 1 || i == width || i == width -1){
            for (int ii = 0; ii<=height; ii++) {
                gotoxy(i, ii);
                setBackgroundColor(COLOR_BLUE);
                printf(" ");
            }
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "direction.h"
#include "console.h"

typedef struct direction{
    int xDir, yDir;
} Direction;

Direction* createDirection() {
    Direction* d = (Direction*) malloc(sizeof(Direction));
    d->xDir = 0;
    d->yDir = 0;
    return d;
}

void insertXDir(Direction* dir, int xDir) {
    dir->xDir = xDir;
}

void insertYDir(Direction* dir, int yDir) {
    dir->yDir = yDir;
}

int getXDir(Direction* dir) {
    return dir->xDir;
}

int getYDir(Direction* dir) {
    return dir->yDir;
}

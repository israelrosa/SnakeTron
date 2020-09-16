#include <stdio.h>
#include <stdlib.h>
#include "position.h"
#include "console.h"

struct position {
  int xPos, yPos;
  struct position* prox;
};

Position* createPosition(int xPos, int yPos) {
  Position* pos = (Position*) malloc(sizeof(Position));
  pos->xPos = xPos;
  pos->yPos = yPos;
  pos->prox = (Position*) malloc(sizeof(Position));
  pos->prox = NULL;
  return pos;
}

void insertXPos(Position* pos, int xPos) {
    pos->xPos = xPos;
}

void insertYPos(Position* pos, int yPos) {
    pos->yPos = yPos;
}

void insertProxPos(Position* pos, Position* prox) {
    pos->prox = prox;
}

Position* getProxPos(Position* pos) {
    return pos->prox;
}

int getXPos(Position* pos) {
    return pos->xPos;
}

int getYPos(Position* pos) {
    return pos->yPos;
}

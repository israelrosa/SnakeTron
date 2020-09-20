#include <stdio.h>
#include <stdlib.h>
#include "position.h"
#include "console.h"

struct position {
  int xPos, yPos;
  struct position* next;
};

Position* createPosition(int xPos, int yPos) {
  Position* pos = (Position*) malloc(sizeof(Position));
  pos->xPos = xPos;
  pos->yPos = yPos;
  pos->next = (Position*) malloc(sizeof(Position));
  pos->next = NULL;
  return pos;
}

void insertXPos(Position* pos, int xPos) {
    pos->xPos = xPos;
}

void insertYPos(Position* pos, int yPos) {
    pos->yPos = yPos;
}

void insertNextPos(Position* pos, Position* next) {
    pos->next = next;
}

Position* getNextPos(Position* pos) {
    return pos->next;
}

int getXPos(Position* pos) {
    return pos->xPos;
}

int getYPos(Position* pos) {
    return pos->yPos;
}

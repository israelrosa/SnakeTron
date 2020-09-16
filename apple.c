#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "apple.h"
#include "position.h"
#include "console.h"
#include "snake.h"

struct apple {
  Position* pos;
};

Apple* createApple() {
  Apple* a = (Apple*) malloc(sizeof(Apple));
  a->pos = createPosition(0, 0);
  return a;
}

void printApple(Apple* apple) {
  gotoxy(getXPos(apple), getYPos(apple));
  setBackgroundColor(COLOR_WHITE);
  printf(" ");

  gotoxy(getXPos(apple) + 1, getYPos(apple));
  setBackgroundColor(COLOR_WHITE);
  printf(" ");
}

void releaseApple(Apple* apple) {
  gotoxy(getXPos(apple), getYPos(apple));
  setBackgroundColor(COLOR_BLACK);
  printf(" ");

  gotoxy(getXPos(apple) + 1, getYPos(apple));
  setBackgroundColor(COLOR_BLACK);
  printf(" ");
}

void drawApple(Apple* apple, int width, int heigth) {
  srand(time(NULL));
  int drawXPos = rand() % (width * OFFSETX);
  int drawYPos = rand() % (heigth);
  if(drawXPos % 2 != 0) {
    drawXPos--;
  }
  insertXPos(apple, drawXPos);
  insertYPos(apple, drawYPos);
}

bool checkPosition(Apple* apple, Snake* snake, int width, int heigth) {
  if (getXPos(apple) == 0 || getXPos(apple) >= width * OFFSETX) {
    return false;
  } else if (getYPos(apple) == 0 || getYPos(apple) >= heigth) {
    return false;
  } else if (getXPos(apple) == getXPos(getHead(snake)) && getYPos(apple) == getYPos(getHead(snake))) {
    return false;
  } else {
    for (Position* tail = getTail(snake); getProxPos(tail) != NULL; tail = getProxPos(tail)) {
      if (getXPos(apple) == getXPos(tail) && getYPos(apple) == getYPos(tail)) {
        return false;
      }
    }
    return true;
  }
}

bool checkIfAteApple(Apple* apple, Snake* snake) {
  if (getXPos(apple) == getXPos(getHead(snake)) && getYPos(apple) == getYPos(getHead(snake))) {
    return true;
  } else {
    return false;
  }
}

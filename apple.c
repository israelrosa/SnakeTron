#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
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
  gotoxy(getXPos(apple->pos), getYPos(apple->pos));
  setBackgroundColor(COLOR_WHITE);
  printf(" ");

  gotoxy(getXPos(apple->pos) + 1, getYPos(apple->pos));
  setBackgroundColor(COLOR_WHITE);
  printf(" ");
}

void releaseApple(Apple* apple) {
  gotoxy(getXPos(apple->pos), getYPos(apple->pos));
  setBackgroundColor(COLOR_BLACK);
  printf(" ");

  gotoxy(getXPos(apple->pos) + 1, getYPos(apple->pos));
  setBackgroundColor(COLOR_BLACK);
  printf(" ");
}

void drawApple(Apple* apple, int width, int heigth) {
  srand(time(NULL));
  int drawXPos = getXPos(apple->pos);
  int drawYPos = getYPos(apple->pos);
  do {
    drawXPos = rand() % (width * OFFSETX);
    drawYPos = rand() % (heigth);
  } while (getXPos(apple->pos) == drawXPos || getYPos(apple->pos) == drawYPos);



  if(drawXPos % 2 != 0) {
    drawXPos--;
  }
  insertXPos(apple->pos, drawXPos);
  insertYPos(apple->pos, drawYPos);
}

bool checkPosition(Apple* apple, Snake* snake, int width, int heigth) {
  if (getXPos(apple->pos) == 0 || getXPos(apple->pos) >= width * OFFSETX) {
    return false;
  } else if (getYPos(apple->pos) == 0 || getYPos(apple->pos) >= heigth) {
    return false;
  } else if (getXPos(apple->pos) == getXPos(getHead(snake)) && getYPos(apple->pos) == getYPos(getHead(snake))) {
    return false;
  } else {
    for (Position* tail = getTail(snake); getNextPos(tail) != NULL; tail = getNextPos(tail)) {
      if (getXPos(apple->pos) == getXPos(tail) && getYPos(apple->pos) == getYPos(tail)) {
        return false;
      }
    }
    return true;
  }
}

bool checkIfAteApple(Apple* apple, Snake* snake) {
  if (getXPos(apple->pos) == getXPos(getHead(snake)) && getYPos(apple->pos) == getYPos(getHead(snake))) {
    Beep(800, 50);
    return true;
  } else {
    return false;
  }
}

void deleteApple(Apple* apple) {
    free(apple);
}

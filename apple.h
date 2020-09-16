#include "snake.h"

typedef struct apple Apple;

Apple* createApple();

void drawApple(Apple* apple, int width, int heigth);

void printApple(Apple* apple);

void releaseApple();

bool checkPosition(Apple* apple, Snake* snake, int width, int height);

bool checkIfAteApple(Apple * apple, Snake* snake);

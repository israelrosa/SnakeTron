#include "position.h"

typedef struct snake Snake;

Snake* createSnake(int xPos, int yPos, int player);

void printSnake(Snake* snake);

bool checkColision(Snake* snake, int width, int height);

bool checkPlayersColision(Snake* player1, Snake* player2);

void releaseSnake(Snake* snake);

void updateBody(Snake* snake);

void updateDirection(Snake* snake, int key);

void snakeFeed(Snake* snake);

Position* getTail(Snake* snake);

Position* getHead(Snake* snake);

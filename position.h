typedef struct position Position;

Position* createPosition(int xPos, int yPos);

void insertXPos(Position* pos, int xPos);

void insertYPos(Position* pos, int yPos);

void insertNextPos(Position* pos, Position* next);

Position* getNextPos(Position* pos);

int getXPos(Position* pos);

int getYPos(Position* pos);

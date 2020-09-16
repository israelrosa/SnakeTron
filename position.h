typedef struct position Position;

Position* createPosition(int xPos, int yPos);

void insertXPos(Position* pos, int xPos);

void insertYPos(Position* pos, int yPos);

void insertProxPos(Position* pos, Position* prox);

Position* getProxPos(Position* pos);

int getXPos(Position* pos);

int getYPos(Position* pos);

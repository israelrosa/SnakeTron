typedef struct direction Direction;

Direction* createDirection();

void insertXDir(Direction* dir, int xDir);

void insertYDir(Direction* dir, int yDir);

int getXDir(Direction* dir);

int getYDir(Direction* dir);

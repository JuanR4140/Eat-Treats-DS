int onCollision(Sprite* sprite1, Sprite* sprite2);

int onCollisionOffset(Sprite* sprite1, Sprite* sprite2, int offsetX, int offsetY, int offsetW, int offsetH);

int onCollisionAll(Sprite* sprite1, Sprite* sprites[], int sprites_len);

int onCollisionRaw(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

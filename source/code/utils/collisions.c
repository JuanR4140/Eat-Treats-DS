#include "sprite_handling.h"

int onCollision(Sprite* sprite1, Sprite* sprite2){
    return ( sprite1->gfx->x < sprite2->gfx->x + sprite2->width && 
             sprite1->gfx->x + sprite1->width > sprite2->gfx->x &&
             sprite1->gfx->y < sprite2->gfx->y + sprite2->height &&
             sprite1->height + sprite1->gfx->y > sprite2->gfx->y );
}

int onCollisionOffset(Sprite* sprite1, Sprite* sprite2, int offsetX, int offsetY, int offsetW, int offsetH){
    return ( sprite1->gfx->x < sprite2->gfx->x+offsetX + sprite2->width+offsetW && 
             sprite1->gfx->x + sprite1->width+offsetW > sprite2->gfx->x+offsetX &&
             sprite1->gfx->y < sprite2->gfx->y+offsetY + sprite2->height+offsetH &&
             sprite1->height + sprite1->gfx->y > sprite2->gfx->y+offsetY );
}

int onCollisionAll(Sprite* sprite1, Sprite* sprites[], int sprites_len){
    for(int i = 0; i < sprites_len; i++){
        if(sprite1->gfx->x < sprites[i]->gfx->x + sprites[i]->width && 
             sprite1->gfx->x + sprite1->width > sprites[i]->gfx->x &&
             sprite1->gfx->y < sprites[i]->gfx->y + sprites[i]->height &&
             sprite1->height + sprite1->gfx->y > sprites[i]->gfx->y) return 1;
    }
    return 0;
}

int onCollisionRaw(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2){
    return ( x1 < x2 + w2 && 
             x1 + w1 > x2 &&
             y1 < y2 + h2 &&
             h1 + y1 > y2 );
}

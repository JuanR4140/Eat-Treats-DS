#ifndef SPRITE_HANDLING_H
#define SPRITE_HANDLING_H

#define MAIN 0
#define SUB 1

#include <nds/arm9/sprite.h>

typedef struct Sprite {
    SpriteEntry* gfx;
    u16 x;
    u16 y;
    u8 width;
    u8 height;
} Sprite;

Sprite* create_sprite(int id, OamState* oam, SpriteSize size, SpriteColorFormat color, const void* spriteTiles, const unsigned int spriteTilesLen, int pallete_slot);

void set_sprite_opts(Sprite* sprite, u8 width, u8 height);

void load_pallete(int disp, int slot, const unsigned short source[256]);

#endif
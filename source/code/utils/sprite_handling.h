#ifndef SPRITE_HANDLING_H
#define SPRITE_HANDLING_H

#define MAIN 0
#define SUB 1

#include <nds/arm9/sprite.h>

typedef struct Sprite {
    SpriteEntry* gfx;
    int id;
    u16 x;
    u16 y;
    u8 width;
    u8 height;
} Sprite;

Sprite* create_sprite(int id, OamState* oam, SpriteSize size, SpriteColorFormat color, u16* spriteGFX, int pallete_slot);

u16* load_gfx(OamState* oam, SpriteSize size, SpriteColorFormat colorFormat, const unsigned int* spriteTiles, const unsigned int spriteTilesLen);
void unload_gfx(OamState* oam, const void* spriteGFX);

void set_sprite_opts(Sprite* sprite, u8 width, u8 height);

void load_pallete(int disp, int slot, const unsigned short source[256]);
void unload_pallete(int disp, int slot);

#endif
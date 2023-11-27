#include <nds.h>
#include <nds/arm9/sprite.h>

#include "sprite_handling.h"

// Sprite* create_sprite(int id, OamState* oam, SpriteSize size, SpriteColorFormat color, const void* spriteGFX, int pallete_slot){
Sprite* create_sprite(int id, OamState* oam, SpriteSize size, SpriteColorFormat color, u16* spriteGFX ,int pallete_slot){
    Sprite* sprite = malloc(sizeof(Sprite));

    /*u16* spriteGFX = oamAllocateGfx(oam, size, color);
    dmaCopy(spriteTiles, spriteGFX, spriteTilesLen);*/

    oamSet(oam, id, 0, 0, 0, pallete_slot, size, color, spriteGFX, -1, false, false, false, false, false);
    sprite->gfx = &oam->oamMemory[id];
    sprite->x = sprite->gfx->x;
    sprite->id = id;
    sprite->y = sprite->gfx->y;
    sprite->width = 0;
    sprite->height = 0;
    
    return sprite;
}

u16* load_gfx(OamState* oam, SpriteSize size, SpriteColorFormat colorFormat, const unsigned int* spriteTiles, const unsigned int spriteTilesLen){
    u16* spriteGFX = oamAllocateGfx(oam, size, colorFormat);
    dmaCopy(spriteTiles, spriteGFX, spriteTilesLen);
    return spriteGFX;
}

void unload_gfx(OamState* oam, const void* spriteGFX){
    oamFreeGfx(oam, spriteGFX);
}

void set_sprite_opts(Sprite* sprite, u8 width, u8 height){
    sprite->width = width;
    sprite->height = height;
}

void load_pallete(int disp, int slot, const unsigned short source[256]){
    switch(disp){
        case MAIN:{
            vramSetBankF(VRAM_F_LCD);
            for(int i = 0; i < 256; i++){
                VRAM_F_EXT_SPR_PALETTE[slot][i] = source[i];
            }
            vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);
            break;
        }

        case SUB:{
            vramSetBankI(VRAM_I_LCD);
            for(int i = 0; i < 256; i++){
                VRAM_I_EXT_SPR_PALETTE[slot][i] = source[i];
            }
            vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);
            break;
        }

        default:{
            break;
        }
    }
}

void unload_pallete(int disp, int slot){
    switch(disp){
        case MAIN:{
            vramSetBankF(VRAM_F_LCD);
            for(int i = 0; i < 256; i++){
                VRAM_F_EXT_SPR_PALETTE[slot][i] = '\0';
            }
            vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);
            break;
        }

        case SUB:{
            vramSetBankI(VRAM_I_LCD);
            for(int i = 0; i < 256; i++){
                VRAM_I_EXT_SPR_PALETTE[slot][i] = '\0';
            }
            vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);
            break;
        }

        default:{
            break;
        }
    }
}
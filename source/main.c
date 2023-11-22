#include <stdio.h>
#include <nds.h>
#include <nds/arm9/video.h>
#include <nds/arm9/sound.h>
#include <nds/arm9/sprite.h>
#include <nds/arm9/console.h>

#include "assets/sprites/tuna.h"

void initialize_system(){
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_5_2D);

    vramSetBankA(VRAM_A_MAIN_SPRITE);
    vramSetBankD(VRAM_D_SUB_SPRITE);

    oamInit(&oamMain, SpriteMapping_1D_32, true);
    oamInit(&oamSub, SpriteMapping_1D_32, true);

    vramSetBankF(VRAM_F_LCD);
    vramSetBankI(VRAM_I_LCD);
    for(int i = 0; i < 256; i++){
        VRAM_F_EXT_SPR_PALETTE[0][i] = tunaPal[i];
        VRAM_I_EXT_SPR_PALETTE[0][i] = tunaPal[i];
    }

    vramSetBankF(VRAM_F_SPRITE_EXT_PALETTE);
    vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);
    u16* tunaGfx = oamAllocateGfx(&oamMain, SpriteSize_16x16, SpriteColorFormat_256Color);
    u16* tunaGfxSub = oamAllocateGfx(&oamSub, SpriteSize_16x16, SpriteColorFormat_256Color);

    dmaCopy(tunaTiles, tunaGfx, tunaTilesLen);
    dmaCopy(tunaTiles, tunaGfxSub, tunaTilesLen);

    oamSet(&oamMain, 0, 0, 0, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, tunaGfx, -1, false, false, false, false, false);
    oamSet(&oamSub, 0, 0, 0, 0, 0, SpriteSize_16x16, SpriteColorFormat_256Color, tunaGfxSub, -1, false, false, false, false, false);
}

int main(){
    initialize_system();

    // TODO: GET SPRITE TO RENDER ON SUB SCREEN. GOOD LUCK !
    SpriteEntry* tuna = &oamMain.oamMemory[0];
    SpriteEntry* tunaSub = &oamSub.oamMemory[0];
    tuna->x = 64;
    tuna->y = 64;
    tunaSub->x = 64;
    tunaSub->y = 64;

    
    for(;;){
        swiWaitForVBlank();
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
    }
}
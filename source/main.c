#include <stdio.h>
#include <nds.h>
#include <nds/arm9/video.h>
#include <nds/arm9/background.h>
#include <nds/arm9/sound.h>
#include <nds/arm9/sprite.h>
#include <nds/arm9/console.h>

#include "assets/sprites/tuna.h"
#include "assets/backgrounds/kitchen_top.h"
#include "assets/backgrounds/kitchen_bottom.h"

#include "code/utils/sprite_handling.h"
#include "code/utils/dynamic_array.h"

void initialize_system(){
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_5_2D);

    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankB(VRAM_B_MAIN_SPRITE);
    vramSetBankC(VRAM_C_SUB_BG);
    vramSetBankD(VRAM_D_SUB_SPRITE);

    int kitchen_top = bgInit(3, BgType_Bmp8, BgSize_B8_256x256, 1, 0);
    dmaCopy(kitchen_topBitmap, bgGetGfxPtr(kitchen_top), kitchen_topBitmapLen);
    dmaCopy(kitchen_topPal, BG_PALETTE, kitchen_topPalLen);

    int kitchen_bottom = bgInitSub(3, BgType_Bmp8, BgSize_B8_256x256, 1, 0);
    dmaCopy(kitchen_bottomBitmap, bgGetGfxPtr(kitchen_bottom), kitchen_bottomBitmapLen);
    dmaCopy(kitchen_bottomPal, BG_PALETTE_SUB, kitchen_bottomPalLen);

    oamInit(&oamMain, SpriteMapping_1D_32, true);
    oamInit(&oamSub, SpriteMapping_1D_32, true);
}

int main(){
    initialize_system();

    load_pallete(MAIN, 0, tunaPal);
    Sprite* tuna = create_sprite(0, &oamMain, SpriteSize_16x16, SpriteColorFormat_256Color, tunaTiles, tunaTilesLen, 0);
    tuna->gfx->x = 50;

    for(;;){
        swiWaitForVBlank();

        bgUpdate();
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
    }
}
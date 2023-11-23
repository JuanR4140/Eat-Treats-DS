#include <stdio.h>
#include <nds.h>
#include <nds/arm9/video.h>
#include <nds/arm9/sound.h>
#include <nds/arm9/sprite.h>
#include <nds/arm9/console.h>

#include "assets/sprites/tuna.h"

#include "code/utils/sprite_handling.h"
#include "code/utils/dynamic_array.h"

void initialize_system(){
    videoSetMode(MODE_5_2D);
    videoSetModeSub(MODE_5_2D);

    vramSetBankA(VRAM_A_MAIN_SPRITE);
    vramSetBankD(VRAM_D_SUB_SPRITE);

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
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
    }
}
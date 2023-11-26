#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <nds.h>
#include <nds/arm9/video.h>
#include <nds/arm9/sound.h>
#include <nds/arm9/background.h>
#include <nds/arm9/sprite.h>
#include <nds/arm9/input.h>
#include <nds/input.h>

#include "assets/sprites/tuna.h"
#include "assets/sprites/dead_tuna.h"
#include "assets/sprites/kitten.h"

#include "assets/backgrounds/kitchen_top.h"
#include "assets/backgrounds/kitchen_bottom.h"

#include "munch_bin.h"

#include "code/utils/sprite_handling.h"
#include "code/utils/dynamic_array.h"
#include "code/utils/collisions.h"

#define MAX_TUNA_SIZE 25

void initialize_system(){
    soundEnable();
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
    srand(time(NULL));
    initialize_system();

    load_pallete(MAIN, 0, tunaPal);

    load_pallete(SUB, 0, tunaPal);
    load_pallete(SUB, 1, kittenPal);

    Sprite* kitten = create_sprite(100, &oamSub, SpriteSize_32x32, SpriteColorFormat_256Color, kittenTiles, kittenTilesLen, 1);
    kitten->gfx->y = 150;
    set_sprite_opts(kitten, 32, 32);

    int current_tuna_size = 1;
    Sprite* spritesMain[MAX_TUNA_SIZE];
    Sprite* spritesSub[MAX_TUNA_SIZE];

    for(int i = 0; i < current_tuna_size; i++){
        spritesMain[i] = create_sprite(i, &oamMain, SpriteSize_16x16, SpriteColorFormat_256Color, tunaTiles, tunaTilesLen, 0);
        set_sprite_opts(spritesMain[i], 16, 16);
        spritesMain[i]->gfx->x = rand() % 240;
        spritesMain[i]->gfx->y = rand() % 25;
    }

    for(int i = 1; i < MAX_TUNA_SIZE; i++){
        spritesMain[i] = NULL;
    }

    for(int i = 0; i < MAX_TUNA_SIZE; i++){
        spritesSub[i] = NULL;
    }

    int score = 0;
    int dead_tunas = 0;
    bool tuna_speed = 1;

    int level_0 = 0;
    int level_1 = (rand() % 10) + 6 + level_0;
    int level_2 = (rand() % 10) + 6 + level_1;
    int level_3 = (rand() % 10) + 6 + level_2;
    int level_4 = (rand() % 10) + 6 + level_3;
    int level_5 = (rand() % 10) + 6 + level_4;

    touchPosition* touch = malloc(sizeof(touchPosition));

    for(;;){

        touchRead(touch);
        if(touch->px != 0 && touch->py != 0){
            kitten->gfx->x = touch->px;
        }

        for(int i = 0; i < current_tuna_size; i++){
            if(spritesMain[i] != NULL){
                spritesMain[i]->gfx->y += tuna_speed;

                if(spritesMain[i]->gfx->y > 240){
                    spritesSub[i] = create_sprite(i, &oamSub, SpriteSize_16x16, SpriteColorFormat_256Color, tunaTiles, tunaTilesLen, 0);
                    set_sprite_opts(spritesSub[i], 16, 16);
                    spritesSub[i]->gfx->x = spritesMain[i]->gfx->x;
                    spritesSub[i]->gfx->y = rand() % 25;

                    oamClearSprite(&oamMain, spritesMain[i]->id);
                    spritesMain[i] = NULL;
                }
            }else if(spritesSub[i] == NULL){
                spritesMain[i] = create_sprite(i, &oamMain, SpriteSize_16x16, SpriteColorFormat_256Color, tunaTiles, tunaTilesLen, 0);
                spritesMain[i]->gfx->x = rand() % 240;
                spritesMain[i]->gfx->y = rand() % 25;
            }
        }

        for(int i = 0; i < current_tuna_size; i++){
            if(spritesSub[i] != NULL){
                spritesSub[i]->gfx->y += tuna_speed;

                if(spritesSub[i]->gfx->y > 180){
                    spritesMain[i] = create_sprite(i, &oamMain, SpriteSize_16x16, SpriteColorFormat_256Color, tunaTiles, tunaTilesLen, 0);
                    set_sprite_opts(spritesMain[i], 16, 16);
                    spritesMain[i]->gfx->x = rand() % 240;
                    spritesMain[i]->gfx->y = rand() % 25;

                    Sprite* d = create_sprite(50 + dead_tunas, &oamSub, SpriteSize_16x16, SpriteColorFormat_256Color, dead_tunaTiles, dead_tunaTilesLen, 0);
                    d->gfx->x = spritesSub[i]->gfx->x;
                    d->gfx->y = 180;
                    dead_tunas++;

                    if(dead_tunas > 3){
                        for(;;){
                            swiWaitForVBlank();
                            oamUpdate(&oamMain);
                            oamUpdate(&oamSub);
                            bgUpdate();
                        }
                    }

                    oamClearSprite(&oamSub, spritesSub[i]->id);
                    spritesSub[i] = NULL;

                }

                if(onCollision(kitten, spritesSub[i])){
                    soundPlaySample(munch_bin, SoundFormat_16Bit, munch_bin_size, 65530, 127, 64, false, 0);

                    oamClearSprite(&oamSub, spritesSub[i]->id);
                    spritesSub[i] = NULL;
                    score++;
                    if(score == level_1){
                        current_tuna_size = 2;
                    }else if(score == level_2){
                        current_tuna_size = 3;
                        tuna_speed = 2;
                    }else if(score == level_3){
                        current_tuna_size = 4;
                    }else if(score == level_4){
                        current_tuna_size = 5;
                    }else if(score == level_5){
                        current_tuna_size = 6;
                        tuna_speed = 3;
                    }
                }
            }
        }

        swiWaitForVBlank();

        bgUpdate();
        oamUpdate(&oamMain);
        oamUpdate(&oamSub);
    }
}
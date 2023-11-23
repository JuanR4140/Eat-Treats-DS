#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <nds/arm9/sprite.h>
#include "sprite_handling.h"

typedef struct dynamic_array{
    Sprite* data;
    int size;
    int capacity;
}dynamic_array;

dynamic_array* dynamic_array_init();
void dynamic_array_free(dynamic_array* array);
void dynamic_array_push(dynamic_array* array, void* data);
Sprite* dynamic_array_get(dynamic_array* array, int index);
void dynamic_array_remove(dynamic_array* array, int index);

#endif
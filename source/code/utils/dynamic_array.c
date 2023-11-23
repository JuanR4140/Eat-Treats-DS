#include <stdlib.h>

#include "dynamic_array.h"

dynamic_array* dynamic_array_init(){
    dynamic_array* array = (dynamic_array*)malloc(sizeof(dynamic_array));
    array->data = (Sprite*)malloc(sizeof(Sprite) * 2);
    array->size = 0;
    array->capacity = 2;
    return array;
}

void dynamic_array_free(dynamic_array* array){
    free(array->data);
    free(array);
}

void dynamic_array_push(dynamic_array* array, void* data){
    if(array->size == array->capacity){
        array->capacity *= 2;
        array->data = (Sprite*)realloc(array->data, sizeof(Sprite) * array->capacity);
    }
    array->data[array->size++] = *(Sprite*)data;
}

Sprite* dynamic_array_get(dynamic_array* array, int index){
    return &array->data[index];
}

void dynamic_array_remove(dynamic_array* array, int index){
    for(int i = index; i < array->size - 1; i++){
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}

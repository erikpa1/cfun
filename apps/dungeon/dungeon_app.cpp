#include <stdio.h>

#include "dungeon_app.h"


struct DungeonApp dng_new_app() {
    struct DungeonApp result;
    result.value = 10;
    return result;
}


void dng_run(struct DungeonApp *number) {
    printf("Dungeon value: [%d] \n", number->value);

}

void dng_prepare() {
    printf("Preparing things for DNG \n");
}

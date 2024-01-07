#include <stdio.h>


#include "data/dungeon_app.h"


int main() {
    printf("Hello, World!\n");

    struct DungeonApp app = dng_new_app();

    dng_run(&app);

    return 0;
}

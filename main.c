#include <stdio.h>


#include "data/prelude.h"


int main() {
    printf("Hello, World!\n");

    struct DungeonApp app = dng_new_app();

    dng_run(&app);

    return 0;
}

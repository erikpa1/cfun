#include <stdio.h>

#include "apps/dungeon/prelude.h"
#include "apps/sims/singe_server_queuing_system.h"
#include "apps/vulkanfun/vulkan_entry.h"


const int SIM_RUN = 0;
const int DUNGEON_RUN = 1;
const int VULKAN_FUN = 2;

int main() {

    printf("Starting the app !\n");
    printf("----------- \n");

    int active = DUNGEON_RUN;

    if (active == SIM_RUN) {
//        printf("%d", CONST);
//        sims_run();
//        sims_run_single_server_queuing_system();
    } else if (active == DUNGEON_RUN) {
//        dng_prepare();
//        DungeonApp app = dng_new_app();
//        dng_run(&app);
        dng::Start();
    } else if (active == VULKAN_FUN) {
        vfun::start();
    }


    dng_new_app();

    printf("-----------\n");
    printf("Ending the app !\n");


    return 0;
}

#include <stdio.h>

#include "apps/dungeon/prelude.h"
#include "apps/sims/singe_server_queuing_system.h"


const int SIM_RUN = 0;
const int DUNGEON_RUN = 1;

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

    }

    dng_new_app();

    printf("-----------\n");
    printf("Ending the app !\n");


    return 0;
}

#pragma once


namespace dng {
    enum Diffculty {
        EASY = 0,
        NORMAL = 1,
        HARD = 1
    };


    class Player {
    public:

    };

    class World {
    public:
        Diffculty difficulty;
        Player player;
    };

    World NewWorld();

    Diffculty _AskForDifficulty();

    void Start();

    void _StartNew();

    void _ContinueExisting();

    void _Exit();


}


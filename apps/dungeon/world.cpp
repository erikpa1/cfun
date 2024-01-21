#include "./world.h"

#include <iostream>

#include "../../cmd/cmd.h"

using namespace std;

namespace dng {

    void Start() {
        cmd::Header("Welcome to dungeon");
        cmd::Seperator();
        //Picking from menu

        int option = -1;

        while (option == -1) {

            cmd::Header("Please choose from menu");
            cmd::Option(1, "New game");
            cmd::Option(2, "Continue");
            cmd::Option(3, "Exit");

            auto result = cmd::GetInt(1, 3);
            std::cout << "Result" << result.ok << std::endl;
            if (result.ok) {
                option = result.value;
            } else {
                cmd::Error("Wrong, choice!");
            }
        }

        if (option == 1) {
            _StartNew();
        } else if (option == 2) {
            _ContinueExisting();
        } else if (option == 3) {
            _Exit();
        }


    }

    World NewWorld() {
        struct World tmp = {};
        tmp.difficulty = _AskForDifficulty();
        return tmp;
    }

    Diffculty _AskForDifficulty() {
        bool isOk = false;

        cmd::Header("Enter difficulty:");
        while (isOk != true) {

            cmd::Option(1, "Easy");
            cmd::Option(2, "Normal");
            cmd::Option(3, "Medium");

            auto result = cmd::GetInt(1, 3);

            if (result.ok) {
                return Diffculty(result.value);
            } else {
                cmd::Error("Wrong!");
            }
        }

        return Diffculty::EASY;

    }

    void _StartNew() {
        auto world = dng::NewWorld();
    }

    void _ContinueExisting() {
        auto world = dng::NewWorld();
    }

    void _Exit() {

    }
}

//
// Created by erikp on 1/21/2024.
//
#include "cmd.h"

#include <windows.h>

#include <iostream>

namespace cmd {

    void Header(const char *text) {
        std::cout << text << std::endl;
    }

    void Option(int number, const char *text) {
        std::cout << number << " - " << text << std::endl;
    }

    Result<int> GetInt(int min, int max) {
        int option;
        std::cin >> option;

        if (option < min || option > max) {
            return MakeResult<int>();
        } else {
            return MakeResult(true, option);
        }

    }

    void Seperator() {
        std::cout << "===================" << std::endl;
    }

    void Error(const char *text = "Wrong!") {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout << text << std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);


    }

}


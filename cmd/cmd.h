//
// Created by erikp on 1/21/2024.
//


#include "../meta/meta.h"

namespace cmd {




    void Header(const char *text);
    void Error(const char *text);

    void Seperator();

    void Option(int number, const char *text);

    Result<int> GetInt(int min, int max);


}
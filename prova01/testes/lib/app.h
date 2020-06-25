#ifndef MACRO_APP
#define MACRO_APP
#include <string>
#include <iostream>
#include "../lib/Diary.h"
struct app{
    app();
    int run(int argc, const char** argv);
    void error(std::string nome);
};
#endif // !MACRO_APP


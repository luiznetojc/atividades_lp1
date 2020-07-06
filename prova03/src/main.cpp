#include "../include/App.h"

int main(int argc, char* argv[])
{

    App aplicativo("diary.config");
    return aplicativo.run(argc, argv);
}

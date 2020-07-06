#ifndef MACRO_CONFIG
#define MACRO_CONFIG
#include <string>
#include "../include/Message.h"
struct Config
{
    Config(std::string name);
    std::string path;
    std::string format;
    void load_config(std::string);
    void open_verify(std::string file);
    std::string format_string(Message& m);

};





#endif //MACRO_CONFIG
#ifndef MACRO_DIARY
#define MACRO_DIARY
#include "../lib/Messages.h"
struct Diary
{
    Diary();
    Messages* messages;
    int size;
    int capacity;
    void add_diary(const std::string m);
    void write_archive(const std::string filename);
    void print_archive();
};


#endif // !
#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "../include/Message.h"
#include "../include/Config.h"

#include <string>
#include <vector>

struct Diary
{
    Diary(const std::string& name);

    Config config;
    std::string file_diary;
    std::vector<Message> messages;
    std::vector<Message> search(std::string word);
    void realoc_messages();
    void load();
    void add(const std::string& message);
    void add(const Message& message);
    void write();
    void list();
};
#endif

#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "../include/Message.h"

#include <string>
#include <vector>

struct Diary
{
    Diary(const std::string& filename);


    std::string filename;
    std::vector<Message> messages;
    std::vector<Message> search(std::string word);
    void realoc_messages();
    int load();
    void add(const std::string& message);
    void add(const Message& message);
    void write();
};
#endif

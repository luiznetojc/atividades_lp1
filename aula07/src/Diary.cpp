#include <iostream>
#include "../include/Date.h"
#include "../include/Diary.h"

Diary::Diary(const std::string& filename): messages(nullptr), messages_capacity(10), messages_size(0)
{
    messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message)  // adicionar mensagem no array de mensagens
{
    if(messages_capacity == messages_size)
    {
        std::cout << "TA CHEI";
        return;
    }
    messages[messages_size].content = message;
    messages_size++;
}

void Diary::write()
{
    // gravar as mensagens no disco
}
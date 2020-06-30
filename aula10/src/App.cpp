#include "../include/App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search") 
    {
        if (argc == 2) {
            search();
        } 
        else {
            search(argv[2]);
        }
    } 
    else 
    {
        return show_usage(argv[0]);
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    diary.add(message);
    diary.write();
}
void App::search()
{
    std::string message;
    std::cout << "What do you want to search? " << std::endl;
    std::getline(std::cin, message);

    search(message);
}

void App::search(const std::string message)
{
    Message* finded = diary.search(message);
    if(finded != nullptr){
        std::cout << finded->content<< std::endl;
        return;
    }
        std::cout << "not found" << std::endl;
}

void App::list_messages()
{
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
    }
}

int App::show_usage(const std::string nome)
{
    std::cout << "Uso: " << nome << " search" << " <mensagem>" << std::endl;
    std::cout << "Uso: " << nome << " add" << " <mensagem>" << std::endl;
    std::cout << "Uso: " << nome << " list" << std::endl;
    return 1;
}

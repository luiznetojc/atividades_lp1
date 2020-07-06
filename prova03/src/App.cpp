#include "../include/App.h"
#include "../include/Config.h"
#include <iostream>
#include <string>


App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) 
    {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) 
        {
            add();
        } 
        else 
        {
            add(argv[2]);
        }
    } else if (action == "list") 
    {
        list_messages();
    } 
    else if (action == "search") 
    {
        if (argc == 2) 
        {
            search();
        } 
        else {
            search(argv[2]);
        }

    }
    else if(action == "interactive")
    {
        interactive();
    } 
    else 
    {
        return show_usage(argv[0]);
    }

    return 0;
}
void App::interactive()
{
    int hold(1);
    while (hold != 0)
    {
        std::cout << "Mega Diário 1.0" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "Selecione uma ação:" << std::endl;
        std::cout << "1) Listar mensagens" << std::endl;
        std::cout << "2) Adicionar nova mensagem" << std::endl;
        std::cout << "3) Procurar mensagem" << std::endl;
        std::cout << "0) Finalizar" << std::endl;
        std::cout << " " << std::endl;
        
        std::cin >> hold;
        if(hold == 1)
        {
            list_messages();
        }
        if(hold == 2)
        {
            std::string message;
            std::cout << "Enter your message:" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, message);
            
            add(message);
        }
        if(hold == 3)
        {
            std::string message;
            std::cout << "What do you want to search? " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, message);

            search(message);
        }
        std::cout << " " << std::endl;
        std::cout << " " << std::endl;
    }
    
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
    std::vector<Message> finded = diary.search(message);
   
    for(auto i :finded)
        std::cout << "- " << i.content << std::endl;
}

void App::list_messages()
{
   diary.list();
}

int App::show_usage(const std::string nome)
{
    std::cout << "Uso: " << nome << " search" << " <mensagem>" << std::endl;
    std::cout << "Uso: " << nome << " add" << " <mensagem>" << std::endl;
    std::cout << "Uso: " << nome << " list" << std::endl;
    std::cout << "Uso: " << nome << " interactive" << std::endl;
    return 1;
}

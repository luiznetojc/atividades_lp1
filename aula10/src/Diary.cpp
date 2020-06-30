#include "../include/Diary.h"
#include "../include/aux.h"
#include <fstream>
#include <iostream>
#include <sstream>

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
    load();
}
void Diary::realoc_messages()
{
    messages_capacity *= 2;
    Message* messages_temp = new Message[messages_capacity];
    for(size_t i = 0; i < messages_size; i++)
    {
        messages_temp[i] = messages[i];
    }
    delete[] messages;
    messages = messages_temp;
}


int Diary::load()// carrega do arquivo para o array
{
    std::ifstream arc;
    arc.open(filename);
    if(!arc.is_open())
    {
        std::cout << "arquivo não aberto no diary.load"<< std::endl;
        return 1;
    }
    std::string date;
    std::string time;
    std::string datetag = "#";
    std::string tag = "-";
    std::string readed;
    std::string content;
    int positag, posidate;
    char discard;
    
    while(!arc.eof())
    {
        std::getline(arc,readed);
        positag = readed.find(tag);
        posidate = readed.find(datetag);
        std::stringstream stream(readed);
        if(positag == 0)
            {
                if(messages_size >= messages_capacity)
                {
                    realoc_messages();
                }
                stream >> discard;
                stream >> time;

                messages[messages_size].time.set_from_string(time);
                content = stream.str().substr(11);
                messages[messages_size].content = content;
                messages[messages_size].date.set_from_string(date);
                messages_size++;
                 

                //inserir valores da mensagem
            }

        if(posidate == 0)
        {
            stream >> discard;
            stream >> date;
            //inserir valores da data
        }
    }
    return 0;
}
Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)// adiciona a o array de messages
{
    if (messages_size >= messages_capacity)
    {
        realoc_messages();
    }
    messages[messages_size].content = message;
    messages[messages_size].date.set_from_string(get_current_date());
    messages[messages_size].time.set_from_string(get_current_time());
    messages_size++;
}
Message* Diary::search(std::string word)
{
    for (size_t i = 0; i < messages_size; i++)
    {
        std::size_t pos = messages[i].content.find(word);
        if(pos != std::string::npos)
         {
             std::cout << messages[i].content.find(word) << std::endl;
             return &messages[i];
         } 
             
    }
    return nullptr;
}
void Diary::write() //escreve no arquivo
{
    std::ofstream arc;
    std::string data;
    arc.open(filename, std::ios::out | std::ios::out);
    if(arc.is_open())
    {   
        data = messages[0].date.to_string();
        arc << "# " << data << std::endl;
        arc << " "<< std::endl;
        for (size_t i = 0; i < messages_size; i++)
        {
            if(data.compare(messages[i].date.to_string()))//set a data caso não exista
            {
                data = messages[i].date.to_string();
                arc << " " << std::endl;
                arc << "# " << messages[i].date.to_string() << std::endl;
                arc << " " << std::endl;
            }

        arc << "- " << messages[i].time.to_string() <<" "<< messages[i].content << std::endl;
        }
        arc.close();
        return;
    }
    std::cerr << "Abertura do arquivo faiou :p" << std::endl;
    
}

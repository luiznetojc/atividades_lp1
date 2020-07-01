#include "../include/Diary.h"
#include "../include/aux.h"
#include <fstream>
#include <iostream>
#include <sstream>

Diary::Diary(const std::string& name) : filename(name)
{

    load();
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
        Message m;
        std::getline(arc,readed);
        positag = readed.find(tag);
        posidate = readed.find(datetag);
        std::stringstream stream(readed);
        if(positag == 0)
            {
                stream >> discard;
                stream >> time;

                m.time.set_from_string(time);
                content = stream.str().substr(11);
                m.content = content;
                m.date.set_from_string(date);
                messages.push_back(m);
                 

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

void Diary::add(const std::string& message)// adiciona a o array de messages
{
    Message m;
    m.content = message;
    m.date.set_from_string(get_current_date());
    m.time.set_from_string(get_current_time());
    messages.push_back(m);
}
std::vector<Message> Diary::search(std::string word)
{
    std::vector<Message> temp;
    for (auto i : messages)
    {
        std::size_t pos = i.content.find(word);
        if(pos != std::string::npos)
         {
             temp.push_back(i);
            
         } 
             
    }
    return temp;
}
void Diary::write() //escreve no arquivo
{
    std::ofstream arc;
    std::string data;
    arc.open(filename, std::ios::out);

    if(arc.is_open())
    {   
        data = messages[0].date.to_string();
        arc << "# " << data << std::endl;
        arc << " "<< std::endl;
        for (auto i : messages)
        {
            if(data.compare(i.date.to_string()))//set a data caso não exista
            {
                data = i.date.to_string();
                arc << " " << std::endl;
                arc << "# " << i.date.to_string() << std::endl;
                arc << " " << std::endl;
            }

        arc << "- " << i.time.to_string() <<" "<< i.content << std::endl;
        }
        arc.close();
        return;
    }
    std::cerr << "Abertura do arquivo faiou :p" << std::endl;
    
}

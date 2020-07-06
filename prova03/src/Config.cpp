#include "../include/Config.h"
#include "../include/Message.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Config::Config(std::string name) : path("diary.md"),format("[%d %t] %m")
{
    open_verify(name); 
    load_config(name);

}
void Config::open_verify(std::string file)//vrfica se o arquivo está aberto, se não cria um padrão 
{
     std::ifstream arc;
    arc.open(file);
    if(arc.is_open())
    {
        arc.close();
        return;
    }
    else
    {
        std::ofstream arc;
        arc.open(file);
         if(arc.is_open())
         {
            arc << "path=diary.md" << std::endl;
            arc << "default_format=[%d %t] %m" << std::endl;

         }
         arc.close();
    }
    return;
}

void Config::load_config(std::string file) //carrega configuração no arquivo
{
    std::ifstream arc;
    arc.open(file);
    if(arc.is_open())
    {
        while(!arc.eof())
        {
        
            int pos_path_tag,pos_format_tag;
            std::string readed;
            std::string path_tag = "path=";
            std::string format_tag = "default_format=";

            std::getline(arc,readed);

            pos_path_tag = readed.find(path_tag);
            pos_format_tag = readed.find(format_tag);

            std::stringstream stream(readed);
            if(pos_path_tag == 0)
            {
                path = stream.str().substr(5);
                pos_path_tag = -1;
            }
            if(pos_format_tag == 0)
            {
                format = stream.str().substr(15);
                pos_format_tag = -1;
            }   
        }

        arc.close();
        return;
    }
    std::cout << "no abriu" <<std::endl;
    return;
}
std::string Config::format_string(Message& m)//formata a string  para a configuração do .config
{
        std::string str;
        std::stringstream stream;
    for (int i = 0; i < int(format.size()); i++)
    {
        if(format[i]=='%'){
            if(format[i+1] == 'm')
            {
                stream << m.content;
                i++;
            }

            else if(format[i+1] == 'd')
            {
                stream << m.date.to_string();
                i++;
            }

            else if(format[i+1] == 't')
            {
                stream << m.time.to_string();
                i++;
            }
            else
            {
                stream << format[i];
            }
            
        }
        else
        {
            stream << format[i];
        }
        
    }
    str = stream.str();
    return str;    
}

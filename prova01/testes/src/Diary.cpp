#include "../lib/Diary.h"
#include "../lib/timeaux.h"
#include <fstream>
#include <iostream>
Diary::Diary():messages(nullptr), size(0),capacity(10)
{
    messages = new Messages[capacity];
}
void Diary::add_diary(const std::string m)
{
    if(capacity == size)
    {
        capacity += 10;
        Messages* messages2;
        messages2 = new Messages[capacity];
        messages2 = messages;
        delete[] messages;
        messages = new Messages[capacity];
        messages = messages2;
        delete[] messages2;


    }
    messages[size].content = m;
    messages[size].time.setTime(get_current_time());
    messages[size].date.setDate(get_current_date());
    size++;
}
void Diary::write_archive(const std::string filename)
{
   std::ofstream archive;

   archive.open(filename);
   if(archive.is_open())
   {
       for (int i = 0; i <= size; i++)
       {
           archive << " - " << messages[i].time.hours 
                   <<  ":"  << messages[i].time.minutes 
                   <<  ":"  << messages[i].time.seconds
                   <<  " "  << messages[i].content; 
           
       }
       
   }
}
void print_archive()// lista no console o documento
{
    std::ifstream arc;
    std::string d;
    std::string tag = "-";
    int posi;
    arc.open("dados.md");
     if(arc.is_open())
    {
        while(!arc.eof())
        {
            std::getline(arc,d);
            posi = d.find(tag); //ignore data do dia
            if(posi == 0) 
                {
                     std::cout << d << std::endl;
                }
        }
        arc.close();
        return;
    }
    std::cerr << "Abertura do arquivo faiou :p" << std::endl;

}

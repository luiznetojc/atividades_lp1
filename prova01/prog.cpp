#include <ctime>
#include <string>
#include <iostream>
#include <fstream>

std::string format_current_date(const std::string& format)
{
    std::time_t time = std::time(nullptr);
    char result[1024];
    std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));
    return std::string(result);
}

std::string get_current_date()
{
    return format_current_date("%d/%m/%Y");
}
std::string get_current_time()
{
    return format_current_date("%H:%M:%S");
}
int read(std::string data) //procura a data, se ja existe retorna 1
{
    std::ifstream arc;
    std::string d;
    int teste = 0;
    int posi = 0;

    arc.open("dados.md");
     if(arc.is_open())
    {
        while(!arc.eof())
        {
            std::getline(arc,d);
            posi = d.find(data);
            if(posi == 2) 
                {
                    teste = 1;
                }
        }
        arc.close();
        if(teste == 1){  return 1; }
        return teste = 0;
    }
    return 0;
}

void write(std::string a) //escreve no documento
{
    int resul = -1;
    std::ofstream arc;
    std::string data = get_current_date();
    resul = read(data);
    std::string hora = get_current_time();
    arc.open("dados.md", std::ios::app);
    if(arc.is_open())
    {   
        if(resul == 0)// caso não exista a data
        {
            arc << "# " << data << std::endl;
            arc <<" "<< std::endl;
        }
        arc << "- " << hora << " " << a << std::endl;
        arc.close();
        std::cout << "mensagem adicionada" << std::endl;
        return;
    }
    std::cerr << "Abertura do arquivo faiou :p" << std::endl;;
    
}
void print()// lista no console o documento
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
void error(std::string nome)//caso o usuario bugar  a entrada
{
    std::cout << "Uso: " << nome << " add" << " <mensagem>" << std::endl;
    std::cout << "Uso: " << nome << " list" << std::endl;
    return;
}
int main(int argc,char *argv[])
{
    std::string nome = argv[0];
    std::string m;
    std::string a = "add";
    std::string b = "list";

     if(argc == 1)
     {
        error(nome);
        return -1;
     }
     if(!a.compare(argv[1]))
     {
         if(argc == 2)
        {
        
            std::cout << "Digite uma mensagem: ";
            getline(std::cin, m);
            write(m); 
        }
        else
        {
            write(argv[2]);
        }
        return 0;
     }
     if(!b.compare(argv[1]))
    {
        print();
        return 0;
    }
    error(nome);
    return -1;

}
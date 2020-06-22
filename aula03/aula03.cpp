#include <iostream>
#include <fstream>

void write(std::string a)
{
    std::ofstream arc;
    arc.open("dados.txt", std::ios::app);
    if(arc.is_open())
    {
        arc << a << std::endl;
        arc.close();
        std::cout << "mensagem adicionada" << std::endl;
        return;
    }
    std::cerr << "Abertura do arquivo faiou :p" << std::endl;;
    
}
void read()
{
    std::ifstream arc;
    std::string d;
    arc.open("dados.txt");
     if(arc.is_open())
    {
        while(!arc.eof())
        {
            std::getline(arc,d);
            std::cout << d << std::endl;
        }
        return;
    }
    std::cerr << "Abertura do arquivo faiou :p" << std::endl;;

}
void error(std::string nome)
{
    std::cout << "Uso: " << nome << " add" << " <mensagem>" << std::endl;
    std::cout << "Uso: " << nome << " list" << std::endl;
    return;
}

int main(int argc,char *argv[]){
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
        
            std::cout << "Digite uma mensagem";
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
        read();
        return 0;
    }
    error(nome);
    return -1;

}

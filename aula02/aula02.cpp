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
    std::cout << "Abertura do arquivo faiou :p" << std::endl;;
    
}

int main(int argc,char *argv[]){

    std::string m;
    std::string a = "add";
     if(argc == 1 || a.compare( argv[1])) 
     {
        std::cout << "Uso: " << argv[0] << " add" << " <mensagem>" << std::endl;
        return -1;
     }
     if(argc == 2)
     {
        
         std::cout << "Digite uma mensagem";
         getline(std::cin, m);
         write(m);
         return 0; 
     }
     write(argv[2]);
    return 0;

}

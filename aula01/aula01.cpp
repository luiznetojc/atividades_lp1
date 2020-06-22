#include <iostream>

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
         std::cout << "mensagem = " << m << std::endl;
         return 0; 
     }
    std::cout << "mensagem = " << argv[2] << std::endl;
    return 0;

}

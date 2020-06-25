#include "../lib/app.h"
#include "../lib/Diary.h"
app::app()
{}
void error(std::string nome)//caso o usuario bugar  a entrada
{
    std::cout << "Uso: " << nome << " add" << " <mensagem>" << std::endl;
    std::cout << "Uso: " << nome << " list" << std::endl;
    return;
}
int run(int argc, const char** argv)
{   

    std::string filename = "dados.md";
    std::string nome = argv[0];
    std::string m;
    std::string a = "add";
    std::string b = "list";
    Diary diary;
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
            diary.add_diary(m);
            diary.write_archive(filename); 
        }
        else
        {
            diary.add_diary(argv[2]);
            diary.write_archive(filename); 
        }
        return 0;
     }
     if(!b.compare(argv[1]))
    {
        diary.print_archive();
        return 0;
    }
    error(nome);
    return -1;


}
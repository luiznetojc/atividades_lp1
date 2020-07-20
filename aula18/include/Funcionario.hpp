#include <string>
class Funcionario
{
  protected:
    std::string nome;
    int cpf;
    std::string data_de_entrada;

  public:
    std::string getnome();
    std::string getdata_de_entrada();
    int getcpf();
    void setnome( std::string n );
    void setdata( std::string d );
    void setcpf( int c );
};
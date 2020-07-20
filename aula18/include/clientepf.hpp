#include <string>
#include "Cliente.hpp"
class Clientepf : public cliente
{

  public:
    Clientepf();
    Clientepf( std::string nome, int cpf );
    int cpf;


};
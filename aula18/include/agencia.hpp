#include <string>
class Agencia
{
  public:
    Agencia();
    Agencia( std::string nome, int numero );
    std::string nome;
    int numero;
};
#include <string>
class Cliente
{
  public:
    Cliente();
    Cliente( std::string nome, int cpf );
    std::string nome;
    int cpf;
};
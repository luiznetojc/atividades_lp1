#include "Funcionario.hpp"
class Gerente : public Funcionario
{
  private:
    std::string agencia;

  public:
    std::string get_agencia();
    void set_agencia( std::string l );
    Gerente( /* args */ );
    ~Gerente();
};

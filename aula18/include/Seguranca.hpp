#include "Funcionario.hpp"
class Seguranca : public Funcionario
{
  private:
    std::string funcao;
    std::string horarios;

  public:
    std::string get_funcao();
    std::string get_horarios();
    void set_funcao( std::string l );
    void set_horario( std::string t );
    Seguranca( /* args */ );
    ~Seguranca();
};

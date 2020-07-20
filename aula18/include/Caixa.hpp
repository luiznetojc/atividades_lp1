#include "Funcionario.hpp"
class Caixa : public Funcionario
{
private:
    std::string local;
    std::string turno;

public:
    std::string get_local();
    std::string get_turno();
    void set_local(std::string l);
    void set_turno(std::string t);
    Caixa(/* args */);
    ~Caixa();
};


#include <string>

class Conta
{
 public:
    int numero;
    float saldo;
    std::string nome;
    void sacar(float valor);
    void depositar(float valor);
    void transferir(float valor, Conta& c); 

};
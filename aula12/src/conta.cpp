#include "conta.hpp"


    void Conta::sacar(float valor)
    {
        this->saldo -= valor;
    }
    void Conta::depositar(float valor)
    {
        this->saldo += valor;
    }
    void Conta::transferir(float valor, Conta& c)
    {
        this->saldo -= valor;
        c.saldo += valor; 
    }
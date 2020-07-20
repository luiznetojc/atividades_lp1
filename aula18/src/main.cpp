#include "../include/conta.hpp"
#include "../include/fila.hpp"
#include <iostream>

int main()
{
    Conta conta = Conta( "caixa", 8783, "marcus", 02354,"razao",1234 );
    fila<clientepj> filaj;
    fila<Cliente> fila;
    filaj.fila.push(conta.clientepj);
    fila.fila.push(conta.cliente);
    std::cout << conta.agencia.nome << std::endl;
    
}
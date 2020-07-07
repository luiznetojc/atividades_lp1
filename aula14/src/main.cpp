#include "conta.hpp"
#include <iostream>

int main()
{
    Conta conta = Conta("caixa",8783,"marcus",02354);
    std::cout << conta.agencia.nome << std::endl;
}
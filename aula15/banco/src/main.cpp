#include "../include/conta.hpp"
#include <iostream>

int main()
{
    Conta conta("caixa",8783,"marcus",02354);
    std::cout << conta.agencia.nome << std::endl;
}
#include "conta.hpp"
#include <iostream>

int main()
{

Conta c1,c2;
c1.saldo = 251.45;
c1.numero = 346;
c1.nome = "Jonas";

c2.saldo = 343.23;
c2.numero = 444;
c2.nome="Carlos";

c1.transferir(110,c2);
std::cout << "c1 Saldo: " << c1.saldo << std::endl;
std::cout <<"c2 Saldo: "<< c2.saldo << std::endl;
c1.depositar(600);
std::cout << "c1 deposito Saldo: "<< c1.saldo << std::endl;
c1.sacar(600);
std::cout <<"c1 sacar Saldo: "<< c1.saldo << std::endl;

}
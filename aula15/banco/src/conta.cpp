
#include "../include/conta.hpp"

Conta::Conta() { this->qtd_contas += 1; }
Conta::~Conta(){}
Conta::Conta(std::string ag_nome, int ag_numero, std::string cl_nome, int cpf) {
  this->cliente = Cliente(cl_nome, cpf);
  this->agencia = Agencia(ag_nome, ag_numero);
  this->qtd_contas += 1;
}

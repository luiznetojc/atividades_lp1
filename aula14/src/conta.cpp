
#include "conta.hpp"

Conta::Conta()
{}
Conta::Conta(std::string ag_nome, int ag_numero,std::string cl_nome,int cpf)
{
	this->cliente = Cliente(cl_nome,cpf);
	this->agencia = Agencia(ag_nome,ag_numero);
}

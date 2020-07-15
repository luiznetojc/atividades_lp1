
#include "../include/conta.hpp"

Conta::Conta() {}
Conta::Conta( std::string ag_nome, int ag_numero, std::string cl_nome, int cpf,std::string pj_razao,int pj_cnpj  )
{
    this->cliente = Cliente( cl_nome, cpf );
	this->clientepj.set_cnpj(pj_cnpj);
	this->clientepj.set_razaoSocial(pj_razao);
    this->agencia = Agencia( ag_nome, ag_numero );
}

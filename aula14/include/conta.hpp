
#include "agencia.hpp"
#include "cliente.hpp"
class Conta
{
public:
	Conta();
	Conta(std::string ag_nome, int ag_numero, std::string cl_nome, int cpf);
	Cliente cliente;
	Agencia agencia;
};
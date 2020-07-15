
#include "agencia.hpp"
#include "cliente.hpp"
#include "clientepj.hpp"
class Conta
{
  public:
    Conta();
    Conta( std::string ag_nome, int ag_numero, std::string cl_nome, int cpf,std::string pj_razao,int pj_cnpj );
    Cliente cliente;
    Agencia agencia;
	clientepj clientepj;
};
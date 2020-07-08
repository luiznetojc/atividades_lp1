
#include "agencia.hpp"
#include "cliente.hpp"
class Conta {
public:
  Conta();
  ~Conta();
  Conta(std::string ag_nome, int ag_numero, std::string cl_nome, int cpf);
  int static qtd_contas;
  Cliente cliente;
  Agencia agencia;
};
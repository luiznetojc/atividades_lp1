#include "../include/cliente.hpp"
Cliente::Cliente()
  : nome( " " )
  , cpf( 0 )
{}
Cliente::Cliente( std::string nome, int cpf )
{
    this->nome = nome;
    this->cpf = cpf;
}
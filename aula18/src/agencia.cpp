#include "../include/agencia.hpp"
Agencia::Agencia()
  : nome( " " )
  , numero( 0 )
{}
Agencia::Agencia( std::string nome, int numero )
{
    this->nome = nome;
    this->numero = numero;
}
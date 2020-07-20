#include "../include/clientepf.hpp"
Clientepf::Clientepf():cpf( 0 )
{}
Clientepf::Clientepf( std::string nome, int cpf )
{
    this->nome = nome;
    this->cpf = cpf;
}
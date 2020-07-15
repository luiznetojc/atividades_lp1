#include "../include/clientepj.hpp"

void clientepj::set_razaoSocial( std::string razaoSocial )
{
    this->razaoSocial = razaoSocial;
}
std::string clientepj::get_razaoSocial()
{
    return razaoSocial;
}
void clientepj::set_cnpj( int cnpj )
{
    this->cnpj = cnpj;
}
int clientepj::get_cnpj()
{
    return cnpj;
}
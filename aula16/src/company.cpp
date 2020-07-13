#include "company.hpp"

std::string company::get_name()
{
    return name;
}
void company::set_name( std::string name )
{
    this->name = name;
}
int company::get_cnpj()
{
    return cnpj;
}
void company::set_cnpj( int cnpj )
{
    this->cnpj = cnpj;
}
void company::set_cp_employee( employee& emp )
{
    cp_employee.push_back( emp );
}
float company::get_salary( int id )
{
    return cp_employee[ id ].get_salary();
}
void company::set_salary( int id, float salary )
{
    cp_employee[ id ].set_salary( salary );
}

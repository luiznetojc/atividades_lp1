#include "employee.hpp"

std::string employee::get_name()
{
    return name;
}
void employee::set_name( std::string name )
{
    this->name = name;
}
std::string employee::get_depart()
{
    return depart;
}
void employee::set_depart( std::string depart )
{
    this->depart = depart;
}
std::string employee::get_adm_date()
{
    return adm_date;
}
void employee::set_adm_date( std::string date )
{
    this->adm_date = date;
}
float employee::get_salary()
{
    return salary;
}
void employee::set_salary( float salary )
{
    this->salary = salary;
}
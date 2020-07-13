#include "company.hpp"
#include <iostream>
int main()
{
    int qtd_emp;
    std::cout << "quantidade de empregados: " << std::endl;
    std::cin >> qtd_emp;
    company company;
    company.set_name( "IMD" );
    company.set_cnpj( 1234 );
    for ( int i = 0; i < qtd_emp; i++ ) {
        employee emp;
        std::string n;
        float a;
        std::cout << i << " name: " << std::endl;
        std::cin >> n;
        emp.set_name( n );
        std::cout << i << " depart: " << std::endl;
        std::cin >> n;
        emp.set_depart( n );
        std::cout << i << " date: " << std::endl;
        std::cin >> n;
        emp.set_adm_date( n );
        std::cout << i << "salary: " << std::endl;
        std::cin >> a;
        emp.set_salary( a );
        company.set_cp_employee( emp );
    }
    for ( int i = 0; i < qtd_emp; i++ ) {
        float a;
        a = company.get_salary( i );
        a = a * 1.1;
        company.set_salary( i, a );
    }
}
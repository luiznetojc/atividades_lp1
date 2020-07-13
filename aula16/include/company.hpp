#include "employee.hpp"
#include <string>
#include <vector>
class company
{
  private:
    std::string name;
    int cnpj;
    std::vector<employee> cp_employee;

  public:
    void set_cp_employee( employee& emp );
    std::string get_name();
    void set_name( std::string name );
    int get_cnpj();
    void set_cnpj( int cnpj );
    float get_salary( int id );
    void set_salary( int id, float salary );
};
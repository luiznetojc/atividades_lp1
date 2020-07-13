#include <string>
class employee
{
  private:
    std::string name;
    std::string depart;
    std::string adm_date;
    float salary;

  public:
    std::string get_name();
    void set_name( std::string name );
    std::string get_depart();
    void set_depart( std::string depart );
    std::string get_adm_date();
    void set_adm_date( std::string date );
    float get_salary();
    void set_salary( float salary );
};

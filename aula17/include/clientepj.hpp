#include <string>

class clientepj
{
  private:
    std::string razaoSocial;
    int cnpj;

  public:
    void set_razaoSocial( std::string razaoSocial );
    std::string get_razaoSocial();
    void set_cnpj( int cnpj );
    int get_cnpj();
};
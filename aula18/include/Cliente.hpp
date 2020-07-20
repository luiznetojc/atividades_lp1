#include <string>
class cliente
{
  protected:
    std::string nome;
    int idade;

  public:
    std::string getnome();
    void setnome( std::string );
    int getidade();
    void setidade( int idad );
};
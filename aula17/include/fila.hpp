#include <iostream>
#include <queue>
template<class T>
class fila
{
  public:
    std::queue<T> fila;

    void set_clientes( T client ) { fila.push( client ); }
    T get_clientes( int pos );
};
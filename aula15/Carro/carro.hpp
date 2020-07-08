#include "motor.hpp"
#include <string>

using namespace std;

class Carro {
public:
  string tipo;
  string placa;
  int numPortas;
  int velocidade;
  string cor;
  Motor motor;
  int static qtd_carro;

  Carro(string cor);
  Carro();

  void acelera(int velocidade);
  void freia(int velocidade);
  void ligaCarro();
};
#include "carro.hpp"

Carro::Carro(string cor) {
  this->cor = cor;
  this->qtd_carro += 1;
}

Carro::Carro() {
  this->cor = "Branco";
  this->qtd_carro += 1;
}

void Carro::acelera(int velocidade) { this->velocidade += velocidade; }

void Carro::freia(int velocidade) { this->velocidade -= velocidade; }

void Carro::ligaCarro() { motor.partida(); }
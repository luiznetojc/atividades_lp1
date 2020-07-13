#include "../include/Client.hpp"
#include <fstream>
#include <iostream>

Client::Client(int t) {
  arc_name << "client_";
  arc_name << t << ".txt";
  wallet = 0;
}

int Client::buy(Products p) {
  int t = 0;
  if (wallet >= p.value) {
    wallet -= p.value;
    for (int i = 0; i < int(cart.size()); i++) {
      if (p.code == cart[i].code) {
        cart[i].qtd += 1;
        t = 1;
      }
    }
    if (t == 0) {
      p.qtd = 1;
      cart.push_back(p);
    }
    return 0;
  } else {
    std::cout << "Dinheiro insulficiente" << std::endl;
    return -1;
  }
}
void Client::see_cart() {
  for (auto i : cart) {
    std::cout << i.name << "qtd: " << i.qtd << std::endl;
  }
}

void Client::client_register() {

  std::ofstream archive;
  archive.open(arc_name.str());
  for (auto i : cart) {
    archive << i.name << " qtd: " << i.qtd << std::endl;
  }
}
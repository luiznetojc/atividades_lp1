#include "../include/Market.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
Market::Market() {
  cash_sum = 0;
  load();
}
void Market::load() {
  std::ifstream archive;
  std::string read;
  int cont = 0;
  char discard;
  std::stringstream temp;
  archive.open("estoque.csv");
  if (archive.is_open()) {
    std::getline(archive, read);
    Products prod;
    while (!archive.eof()) {
      std::getline(archive, read);
      std::stringstream line(read);
      line >> prod.code;
      line >> discard;
      for (size_t i = 0; i < sizeof(read) && cont < 3; i++) {
        line >> discard;
        if (discard != ',') {
          temp << discard;
        } else {
          if (cont == 0) {
            prod.name = temp.str();
          }
          if (cont == 1) {
            prod.unit_measure = temp.str();
          }
          if (cont == 2) {
            std::string val;
            temp << discard;
            line >> discard;
            temp << discard;
            line >> discard;
            temp << discard;
            val = temp.str();
            prod.value_string = val;
            prod.value = to_float(val);
            line >> discard;
            line >> discard;
            line >> prod.qtd;
            products.push_back(prod);
          }
          temp.str("");
          cont++;
        }
      }
      cont = 0;
    }
    products.erase(products.end() - 1);
  } else {
    std::cout << "erro abertura" << std::endl;
  }
}
float Market::to_float(std::string a) {
  float f;
  int i, d;
  std::stringstream m(a);
  char discard;
  m >> discard;
  m >> discard;
  m >> discard;
  m >> i;
  m >> discard;
  m >> d;

  f = i + (d / 100.0);
  return f;
}
void Market::sale(const int &id) {

  for (int i = 0; i < int(products.size()); i++) {

    if (id == products[i].code) {
      cash(products[i]);
      products[i].qtd -= 1;

      if (products[i].qtd == 0) {
        i--;
        products.erase(products.begin() + i);
        std::cout << "Empty" << std::endl;
      }
    }
  }
}
Products Market::consul(const int id) {
  Products cors;
  for (auto i : products) {
    if (id == i.code)
      return i;
  }

  return cors;
}

void Market::cash(Products p) {
  int t = 0;
  cash_sum += p.value;
  for(int i=0;i< int(prod_sold.size());i++ ) {
    if (p.code == prod_sold[i].code) {
      prod_sold[i].qtd += 1;
      t = 1;
    }
  }
  if (t == 0) {
    p.qtd = 1;
    prod_sold.push_back(p);
  }
}
void Market::write_archive_cash() {
  std::ofstream arc;
  arc.open("cash.txt");
  for (auto i : prod_sold) {
    arc << i.code << ", " << i.name << ", " << i.unit_measure << ", $"
        << i.value << ",  " << i.qtd << std::endl;
  }
  arc << "total: " << cash_sum << std::endl;
}
void Market::write_archive_stock() {
  std::ofstream arc;

  arc.open("estoque.csv");
  arc << "COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE" << std::endl;
  for (auto i : products) {
    arc << i.code << "," << i.name << "," << i.unit_measure << ","
        << "\"R$ ";
    for (int a = 3; a < i.value_string.size(); a++) {
      arc << i.value_string[a];
    }
    arc << "\"," << i.qtd << std::endl;
  }
}
void Market::list_products() {
  for (auto i : products) {
    std::cout << i.code << " name: " << i.name << " unit: " << i.unit_measure
              << " value: " << i.value << " qtd: " << i.qtd << std::endl;
  }
}
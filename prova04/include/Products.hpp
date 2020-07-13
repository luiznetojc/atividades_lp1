#ifndef MACRO_PRODUCTS
#define MACRO_PRODUCTS
#include <string>
class Products {
public:
  int code;
  std::string name;
  std::string unit_measure;
  std::string value_string;
  float value;
  int qtd;
};
#endif
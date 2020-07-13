#include "Products.hpp"
#include <sstream>
#include <string>
#include <vector>
class Client {
public:
  Client(int t);
  float wallet;
  std::stringstream arc_name;
  std::vector<Products> cart;
  int buy(Products p);
  void see_cart();
  void client_register();
};
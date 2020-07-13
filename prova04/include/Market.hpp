#include "Products.hpp"
#include <vector>
class Market {
private:
  float cash_sum;

public:
  Market();
  std::vector<Products> prod_sold;
  std::vector<Products> products;
  void list_products();
  void cash(Products p);
  void load();
  Products consul(const int id);
  void write_archive_cash();
  void write_archive_stock();
  float to_float(std::string a);
  void sale(const int &id);
};
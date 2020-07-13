#include "../include/Client.hpp"
#include "../include/Market.hpp"
#include <iostream>
int main() {
  Market market;
  int stop, qtd_clients = 0;
  stop = 0;
  while (stop == 0) {
    Client client(qtd_clients);
    while (1) {
      int option;

      std::cout << "Market 1.0" << std::endl << std::endl;
      std::cout << "1) Add cash to wallet" << std::endl;
      std::cout << "2) See all avaliables products  " << std::endl;
      std::cout << "3) buy products  " << std::endl;
      std::cout << "4) See the cart" << std::endl;
      std::cout << "5) Finish" << std::endl;
      std::cin >> option;

      if (option == 1) {
        float dol;
        std::cout << "How much?" << std::endl;
        std::cin >> dol;
        client.wallet += dol;
        std::cout << "Now you have: $" << client.wallet << std::endl;
      }
      if (option == 2) {
        market.list_products();
      } else if (option == 3) {
        Products m;
        int id, test;
        std::cout << "Write the Id product" << std::endl;
        std::cin >> id;
        m = market.consul(id);
        test = client.buy(m);
        if (test == 0) {
          market.sale(id);
          market.write_archive_stock();
          market.write_archive_cash();
          std::cout << "OK!" << std::endl;
        }
      } else if (option == 4) {
        client.see_cart();
      } else if (option == 5) {
        client.client_register();
        break;
      }
    }
    int opt;
    std::cout << "1)New client" << std::endl;
    std::cout << "2)Quit" << std::endl;
    std::cin >> opt;
    if (opt == 1) {
      qtd_clients++;
    } else if (opt == 2) {
      stop = 1;
    }
  }
}
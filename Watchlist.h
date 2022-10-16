#ifndef WATCHLIST_H
#define WATCHLIST_H

#include <string>
#include <vector>

#include "Stock.h"

class Watchlist {
 private:
  std::string name;
  std::vector<Stock *> stocks;

 public:
  Watchlist(){};
  Watchlist(std::string);
  void addStock(Stock*);
  void removeStock(Stock*);
  std::vector<Stock *> getStocks();
};

#endif
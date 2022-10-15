#ifndef WATCHLIST_H;
#define WATCHLIST_H ;
#include <string>
#include <vector>

#include "Stock.h"

class Watchlist {
 private:
  std::string name;
  std::vector<Stock *> stocks;

 public:
  bool addStock(Watchlist *Stock);
  bool removeStock(Watchlist *Stock);
  void displayWatchlist(std::string watchlistName);
};

#endif
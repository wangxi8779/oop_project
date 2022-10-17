#include "Watchlist.h"

Watchlist::Watchlist(std::string name) { this->name = name; }

void Watchlist::addStock(Stock* stock) { stocks.push_back(stock); }

void Watchlist::removeStock(Stock* stock) {
  for (int i = 0; i < stocks.size(); i++) {
    if (stocks.at(i) == stock) {
      stocks.erase(stocks.begin() + i);
    }
  }
}
std::vector<Stock*> Watchlist::getStocks() { return stocks; }

Watchlist::~Watchlist() {
  for (Stock* stock : stocks) {
    delete stock;
  }
  stocks.clear();
}

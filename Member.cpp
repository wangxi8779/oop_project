#include <iostream>
#include "Member.h"

Member::Member(std::string password, std::string name, std::string phone, std::string email, std::string status, std::string type) {
  this->password = password;
  this->name = name;
  this->phone = phone;
  this->email = email;
  this->status = status;
  this->type = type;
  watchlist = Watchlist(name + "'s watchlist");
}

Watchlist Member::getWatchlist() {
  return watchlist;
}

void Member::addStock(Stock* stock) {
  watchlist.addStock(stock);
}

void Member::removeStock(Stock* stock) {
  watchlist.removeStock(stock);
}

void Member::displayWatchlist() {
  std::cout << name << "'s watchlist" << std::endl;
  for(Stock* stock : watchlist.getStocks()) {
    stock->display();
  }
}

#include <string>
#include "Admin.h"

using namespace std;

Admin::Admin(string password, string name, string phone, string email, string status, string type, StockMarket* stockMarket) {
  this->password = password;
  this->name = name;
  this->phone = phone;
  this->email = email;
  this->status = status;
  this->stockMarket = stockMarket;
  this->type = type;
}

void Admin::block(Account* account) {
  account->setStatus("blocked");
}

void Admin::unblock(Account* account) {
  account->setStatus("active");
}

void Admin::upgrade(Account* account) {
  account->setType("trader");
}

void Admin::downgrade(Account* account) {
  account->setType("member");
}

void Admin::displayWatchlist(){}
void Admin::addStock(Stock* stock){}
void Admin::removeStock(Stock* stock){}

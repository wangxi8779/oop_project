#ifndef MEMBER_H;
#define MEMBER_H ;
#include <string>
#include <vector>

#include "Account.h"
#include "Watchlist.h"

class Member : public Account {
 protected:
  Watchlist watchlist;

 public:
  Member(std::string password, std::string name, std::string phone,
          std::string email, std::string status, std::string type);
  Watchlist getWatchlist();
  void addStock(Stock*);
  void removeStock(Stock*);
  void displayWatchlist();
};

#endif
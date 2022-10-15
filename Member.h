#ifndef MEMBER_H;
#define MEMBER_H ;
#include <string>
#include <vector>

#include "Account.h"
#include "Watchlist.h"

class Member : public Account {
 private:
  std::vector<Watchlist> watchlists;

 public:
  Member(std::string password, std::string name, std::string phone,
          std::string email, std::string status):Account(password, name, phone, email, status){};
  void removeWatchlist(std::string);
  bool createWatchlis(std::string);
  std::vector<Watchlist> getWatchlists();
};

#endif
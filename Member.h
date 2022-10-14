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
  void removeWatchlist(std::string);
  bool createWatchlis(std::string);
  std::vector<Watchlist> getWatchlists();
};

#endif
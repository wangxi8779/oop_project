#ifndef MEMBER_H;
#define MEMBER_H;
#include <string>
#include <vector>
#include "Watchlist.h"

class Member {
    private:
    std::vector<Watchlist> watchlist;
    std::string watchlistName;

    public:
    Member();
    Member();// parameter
    void removeWatchlist(Member watchlistName);
    bool createWatchlis(Member watchlistName);
    Watchlist getWatchlists();



};


#endif 
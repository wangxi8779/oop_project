#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Admin.h"
#include "Member.h"
#include "Trader.h"
#include "Stock.h"
#include "StockMarket.h"
using namespace std;

int main() {
  vector<Stock> stocks;
  Stock s1 = Stock("Tesla", 100.5);
  Stock s2 = Stock("Apple", 90);
  Stock s3 = Stock("Google", 1000.3);
  Stock s4 = Stock("Amazon", 133);
  Stock s5 = Stock("Meta", 122);
  StockMarket stockMarket = StockMarket(stocks);

  // Login
  Account* currentUser = NULL;
  while (!currentUser) {
    string email;
    string password;
    cout << "please input email" << endl;
    cin >> email;
    cout << "please input password" << endl;
    cin >> password;
    currentUser = stockMarket.login(email, password);
  }

  // Login as admin
  if(currentUser->getType() == "admin") {
    while(true) {
      int action = 0;
      cout << "Hi, " << currentUser->getName() << ". What do you want to do?" << endl;
      cout << "1. block an account" << endl;
      cout << "2. unblock an account" << endl;
      cout << "3. upgrade an account" << endl;
      cout << "4. downgrade an account" << endl;
      cout << "5. log out" << endl;
      while(action < 1 || action > 5) {
        cout << "Please enter a number (1-5)" << endl;
        cin >> action;
      }
      if (action == 5) {
        break;
      }

      string name;
      Account* account = NULL;
      while(!account) {
        cout << "Please choose a valid account by entering the name" << endl;
        cin >> name;
        account = stockMarket.findAccount(name);
      }
      switch(action) {
        case 1:
          static_cast<Admin*>(currentUser)->block(account);
          break;
        case 2:
          static_cast<Admin*>(currentUser)->unblock(account);
          break;
        case 3:
          static_cast<Admin*>(currentUser)->upgrade(account);
          break;
        case 4:
          static_cast<Admin*>(currentUser)->downgrade(account);
          break;
      }
      stockMarket.updateAccounts();
    }
  }

  // Login as member
  else if(currentUser->getType() == "member") {
    currentUser->addStock(&s1);
    currentUser->addStock(&s2);
    currentUser->displayWatchlist();
  }

  // Login as trader
  else if(currentUser->getType() == "trader") {
    currentUser->addStock(&s2);
    currentUser->addStock(&s3);
    currentUser->displayWatchlist();
  }
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Admin.h"
#include "Member.h"
#include "Trader.h"
#include "Stock.h"
#include "StockMarket.h"
#include "LimitOrder.h"
using namespace std;

int main() {
  Stock* s1 = new Stock("Tesla", 100.5);
  //queue buy orders
  s1->insertOrder(new LimitOrder(s1, 90, 10, true));
  s1->insertOrder(new LimitOrder(s1, 100, 10, true));
  //queue sell orders
  s1->insertOrder(new LimitOrder(s1, 105, 5, false));
  s1->insertOrder(new LimitOrder(s1, 108, 5, false));
  s1->insertOrder(new LimitOrder(s1, 120, 12, false));
  Stock* s2 = new Stock("Apple", 90);
  s2->insertOrder(new LimitOrder(s2, 70, 10, true));
  s2->insertOrder(new LimitOrder(s2, 80, 10, true));
  //queue sell orders
  s2->insertOrder(new LimitOrder(s2, 105, 5, false));
  s2->insertOrder(new LimitOrder(s2, 108, 5, false));
  s2->insertOrder(new LimitOrder(s2, 120, 12, false));
  Stock* s3 = new Stock("Google", 1000.3);
  Stock* s4 = new Stock("Amazon", 133);
  Stock* s5 = new Stock("Meta", 122);
  vector<Stock*> stocks = {s1, s2, s3, s4, s5};
  StockMarket stockMarket = StockMarket(stocks);

  // Login
  // Account* currentUser = stockMarket.findAccount("e"); //skip login for test
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

  // Test login as member
  else if(currentUser->getType() == "member") {
    currentUser->addStock(s1);
    currentUser->addStock(s2);
    currentUser->displayWatchlist();
  }

  // Test login as trader
  else if(currentUser->getType() == "trader") {
    currentUser->addStock(s1);
    currentUser->addStock(s2);
    // currentUser->addStock(s3);
    // currentUser->addStock(s4);
    // currentUser->addStock(s5);
    // currentUser->displayWatchlist();

    // test buy and sell limit order
    currentUser->buy(s1, 5, 105, "limit");
    currentUser->deposit(1000000000);
    currentUser->buy(s1, 8, 108, "limit");
    currentUser->buy(s1, 10, 118, "limit");
    currentUser->displayWatchlist();
    currentUser->sell(s1, 2, 117, "limit");
    currentUser->displayWatchlist();

    currentUser->buy(s1, 2, 0, "market");
    currentUser->displayWatchlist();
    currentUser->sell(s1, 2, 0, "market");
    currentUser->displayWatchlist();

    // test buy and sell market order
    currentUser->buy(s2, 6, 0, "market");
    currentUser->displayWatchlist();
    currentUser->sell(s2, 10, 0, "market");
  }
}

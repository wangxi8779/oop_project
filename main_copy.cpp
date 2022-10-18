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
  Stock* s1 = new Stock("Tesla", 120);
  //queue buy orders
  s1->insertOrder(new LimitOrder(s1, 90, 10, true));
  s1->insertOrder(new LimitOrder(s1, 100, 10, true));
  //queue sell orders
  s1->insertOrder(new LimitOrder(s1, 105, 5, false));
  s1->insertOrder(new LimitOrder(s1, 108, 5, false));
  s1->insertOrder(new LimitOrder(s1, 120, 12, false));

  Stock* s2 = new Stock("Apple", 120);
  s2->insertOrder(new LimitOrder(s2, 70, 10, true));
  s2->insertOrder(new LimitOrder(s2, 80, 10, true));
  //queue sell orders
  s2->insertOrder(new LimitOrder(s2, 105, 5, false));
  s2->insertOrder(new LimitOrder(s2, 108, 5, false));
  s2->insertOrder(new LimitOrder(s2, 120, 12, false));

  Stock* s3 = new Stock("Google", 130);
  s3->insertOrder(new LimitOrder(s3, 70, 10, true));
  s3->insertOrder(new LimitOrder(s3, 80, 10, true));
  //queue sell orders
  s3->insertOrder(new LimitOrder(s3, 105, 5, false));
  s3->insertOrder(new LimitOrder(s3, 108, 5, false));
  s3->insertOrder(new LimitOrder(s3, 120, 12, false));

  Stock* s4 = new Stock("Amazon", 133);
  s4->insertOrder(new LimitOrder(s4, 70, 10, true));
  s4->insertOrder(new LimitOrder(s4, 80, 10, true));
  //queue sell orders
  s4->insertOrder(new LimitOrder(s4, 105, 5, false));
  s4->insertOrder(new LimitOrder(s4, 108, 5, false));
  s4->insertOrder(new LimitOrder(s4, 120, 12, false));

  Stock* s5 = new Stock("Meta", 122);
  s5->insertOrder(new LimitOrder(s5, 70, 10, true));
  s5->insertOrder(new LimitOrder(s5, 80, 10, true));
  //queue sell orders
  s5->insertOrder(new LimitOrder(s5, 105, 5, false));
  s5->insertOrder(new LimitOrder(s5, 108, 5, false));
  s5->insertOrder(new LimitOrder(s5, 120, 12, false));

  vector<Stock*> stocks = {s1, s2, s3, s4, s5};
  StockMarket stockMarket = StockMarket(stocks);

  // Login
  // Account* currentUser = NULL;
  Account* currentUser = stockMarket.findAccount("e"); //skip login for test
 /* while (!currentUser) {
    string email;
    string password;
    cout << "please input email" << endl;
    cin >> email;
    cout << "please input password" << endl;
    cin >> password;
    currentUser = stockMarket.login(email, password);
  }*/

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
    currentUser->addStock(s1);
    currentUser->addStock(s2);
    currentUser->displayWatchlist();
  }
 bool run=true;
  int input, input2;
  string email;
  string password;


  //main loop
  while(run)
  {
    int input=0, input2=0;
    cout << "1:Buy|||2:Sell|||3:Logout|||4:Login|||5:bank\n6:Deposit|||7:get watchlist|||"<<endl;
    cin >> input;
    // int input, input2;

    if(input == 1)
    {
      cout << "Which stock would you like to buy?1:tesla, 2:apple, 3:google, 4:amazon, 5:meta" << endl;
      cin >> input;
      cout << "How much would you like to buy?" << endl;
      cin >> input2;

    if(input == 1)
      { //currentUser ->deposit(1000000000);
        currentUser -> removeStock(s1);
        currentUser -> addStock(s1);
        currentUser -> buy(s1,input2,s1->getPrice(),"limit");
        currentUser -> withdraw(input2 * (s1->getPrice()));
        input = 0;
        input2 = 0;
        //currentUser ->displayWatchlist();
      }

      if(input == 2)
      { //currentUser ->deposit(1000000000);
        currentUser -> removeStock(s2);
        currentUser -> addStock(s2);
        currentUser -> buy(s2,input2,s2->getPrice(),"limit");
        currentUser -> withdraw(input2 * (s2->getPrice()));
        input = 0;
        input2 = 0;
        //currentUser ->displayWatchlist();
      }

      if(input == 3)
      {
        currentUser -> removeStock(s3);
        currentUser -> addStock(s3);
        currentUser -> buy(s3, input2, s3->getPrice(), "limit");
        currentUser -> withdraw(input2 * (s3->getPrice()));
        input = 0;
        input2 = 0;
      }

       if(input == 4)
      {
        currentUser -> removeStock(s4);
        currentUser -> addStock(s4);
        currentUser -> buy(s4, input2, s4->getPrice(), "limit");
        currentUser -> withdraw(input2 * (s4->getPrice()));
        input = 0;
        input2 = 0;
      }


       if(input == 5)
      {
        currentUser -> removeStock(s5);
        currentUser -> addStock(s5);
        currentUser -> buy(s5, input2, s5->getPrice(), "limit");
        currentUser -> withdraw(input2 * (s5->getPrice()));
        input = 0;
        input2 = 0;
      }

    }

    if(input ==2)
    {
      cout << "which stock would you like to sell:1:tesla, 2:apple, 3:google, 4:amazon, 5:meta"<<endl;
      cin>>input;
      cout << "how much would you like to sell:"<<endl;
      cin>>input2;

      if(input==1)
      {
        //currentUser -> removeStock(s1);
        currentUser -> sell(s1,input2,s1->getPrice(), "");
        currentUser -> deposit(input2 * (s1->getPrice()));
        input = 0;
        input2 = 0;
      }

      if(input==2)
      {
        //currentUser -> removeStock(s1);
        currentUser -> sell(s2,input2,s2->getPrice(), "");
        currentUser -> deposit(input2 * (s2->getPrice()));
        input = 0;
        input2 = 0;
      }

      if(input==3)
      {
        //currentUser -> removeStock(s1);
        currentUser -> sell(s3,input2,s3->getPrice(), "");
        currentUser -> deposit(input2 * (s3->getPrice()));
        input = 0;
        input2 = 0;
      }

      if(input==4)
      {
        //currentUser -> removeStock(s1);
        currentUser -> sell(s4,input2,s4->getPrice(), "");
        currentUser -> deposit(input2 * (s4->getPrice()));
        input = 0;
        input2 = 0;
      }

      if(input==5)
      {
        //currentUser -> removeStock(s1);
        currentUser -> sell(s5,input2,s5->getPrice(), "");
        currentUser -> deposit(input2 * (s5->getPrice()));
        input = 0;
        input2 = 0;
      }

    }

     if(input==3)
    {
      run == false;
      cout <<"Bye"<<endl;
      break;
    }


    if(input == 4)
    {
      cout << "Please enter email" << endl;
      cin >> email;
      cout<<"Please enter password: "<<endl;
      cin>>password;
      currentUser = stockMarket.login(email,password);
    }

    if(input==6)
    {
      currentUser->deposit(1000);
    }

    if(input==5)
    {
     cout<<"Balance: "<< currentUser->getBalance() << endl;
    }

    if(input ==7)
    {
      currentUser->displayWatchlist();
    }

  }
}
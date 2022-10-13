#include <iostream>
#include <string>
#include <vector>

#include "Account.h"
using namespace std;

int main() {
  Account accounts[10];
  Account a1 = Account("12345", "wx", "0430055829", "wangxi8779@hotmail.com");
  // TODO: read accounts from a csv file
  accounts[0] = a1;


  Account* current_user = NULL;
  while (!current_user) {
    string email;
    string password;
    cout << "please input email" << endl;
    cin >> email;
    cout << "please input password" << endl;
    cin >> password;
    for (int i = 0; i < 10; i++) {
      if (accounts[i].login(email, password)) {
        current_user = &accounts[i];
        break;
      }
    }
    if (current_user) {
      cout << "login successfully" << endl;
    } else {
      cout << "email or password is incorrect, please input again" << endl;
    }
  }
}
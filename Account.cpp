#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(string password, string name, string phone, string email) {
  this->password = password;
  this->name = name;
  this->phone = phone;
  this->email = email;
  this->status = "active";
}

#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(){}

Account::Account(string password, string name, string phone, string email) {
  this->password = password;
  this->name = name;
  this->phone = phone;
  this->email = email;
  this->status = "active";
}

bool Account::login(string email, string password){
  return (this->password == password) && (this->email == email);
}
#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(){}

Account::Account(string password, string name, string phone, string email, string status, string type) {
  this->password = password;
  this->name = name;
  this->phone = phone;
  this->email = email;
  this->status = status;
  this->type = type;
}

bool Account::login(string email, string password){
  return (status == "active") && (this->password == password) && (this->email == email);
}

void Account::setStatus(string status) {
  this->status = status;
}

void Account::setType(string type) {
  this->type = type;
}

string Account::getType() {
  return type;
}

string Account::getName() {
  return name;
}

string Account::toRow() {
  string result = name + "," + email + "," + password + "," + phone + "," + status + "," + type + "\n";
  return result;
}

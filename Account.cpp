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
  if (status == "active") {
    if ((this->password == password) && (this->email == email)) {
      cout << "login successfully" << endl;
      return true;
    } else {
      cout << "email or password is incorrect, please input again" << endl;
      return false;
    }
  } else {
    cout << "your account is blocked, please contact admin" << endl;
    return false;
  }
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

string Account::getEmail() {
  return email;
}

string Account::toRow() {
  string result = name + "," + email + "," + password + "," + phone + "," + status + "," + type + "\n";
  return result;
}

double Account::deposit(double amount)
{
  balance += amount;
  return balance;
}

double Account::withdraw(double amount)
{
  balance -= amount;
  return balance;
}

double Account::getBalance()
{
  return balance;
}

Account::~Account() {}

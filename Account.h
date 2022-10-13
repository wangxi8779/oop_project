#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
 private:
  std::string password;
  std::string name;
  std::string status;
  std::string phone;
  std::string email;

 public:
  Account();
  Account(std::string password, std::string name, std::string phone,
          std::string email);
  bool login(std::string email, std::string password);
};
#endif
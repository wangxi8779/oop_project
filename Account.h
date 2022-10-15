#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
 protected:
  std::string password;
  std::string name;
  std::string status;
  std::string type;
  std::string phone;
  std::string email;

 public:
  Account();
  Account(std::string password, std::string name, std::string phone,
          std::string email, std::string status, std::string type);
  bool login(std::string email, std::string password);
  void setStatus(std::string);
  void setType(std::string);
  std::string getType();
  std::string getName();
  std::string toRow();
};
#endif
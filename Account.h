#ifndef ACCOUNT_H;
#define ACCOUNT_H ;
#include <string>

class Account {
 private:
  std::string password;
  std::string name;
  std::string status;
  std::string phone;
  std::string email;

 public:
  Account(std::string password, std::string name, std::string phone,
          std::string email);
//   static bool login(std::string email, std::string password);
};
#endif
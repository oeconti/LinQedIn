#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include"Model/cercastringa.h"

class Login
{
private:
    std::string username;
    std::string password;
    friend class SmartLogin;
public:
    Login();
    Login(const std::string&,const std::string&);

    std::string getUsername()const;
    std::string getPassword()const;

    void setUsername(const std::string&);
    void setPassword(const std::string&);

    bool contieneStringaUsername(const std::string&)const;
};

#endif // LOGIN_H

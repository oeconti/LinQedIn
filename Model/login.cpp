#include "Model/login.h"

//---------------------------------------------COSTRUTTORI--------------------------------------------------------
Login::Login():username("username"),password("password"){}
Login::Login(const std::string& us,const std::string& pwd):username(us),password(pwd){}

//---------------------------------------------METODI-------------------------------------------------------------
//---------------------------------------------Get----------------------------------------------------------------
std::string Login::getUsername()const{
    return username;
}

std::string Login::getPassword()const{
    return password;
}

//---------------------------------------------Set----------------------------------------------------------------

void Login::setUsername(const std::string & us){
    username=us;
}

void Login::setPassword(const std::string & pwd){
    password=pwd;
}

//---------------------------------------------------------------------
bool Login::contieneStringaUsername(const std::string & stringaDaCercare) const{
    CercaStringa c(stringaDaCercare);
    return c.cerca(username);
}

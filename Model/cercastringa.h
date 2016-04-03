#ifndef CERCASTRINGA_H
#define CERCASTRINGA_H
#include <string>
#include <algorithm>
#include <sstream>

class CercaStringa
{
private:
    std::string stringaDaCercare;
    static void stringaToUpper(std::string&);
public:
    CercaStringa(std::string);
    ~CercaStringa();

    void setStringaDaCercare(std::string);
    std::string getStringaDaCercare()const;
    bool cerca(std::string)const;//restituisce true se la stringa passata contiene la stringa da cercare
};

#endif // CERCASTRINGA_H

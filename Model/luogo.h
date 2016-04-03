#ifndef LUOGO_H
#define LUOGO_H
#include <string>
#include "Model/cercastringa.h"

class Luogo
{
private:
    std::string via;
    std::string citta;
    std::string provincia;
    std::string nazione;
public:
    Luogo();
    Luogo(const std::string&,const std::string&,const std::string&,const std::string& );

    std::string getVia() const;
    std::string getCitta() const;
    std::string getProvincia() const;
    std::string getNazione() const;

    void setVia(const std::string&);
    void setCitta(const std::string&);
    void setProvincia(const std::string&);
    void setNazione(const std::string&);

    bool contieneStringa(const std::string&)const;
};

#endif // LUOGO_H

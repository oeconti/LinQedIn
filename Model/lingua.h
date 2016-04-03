#ifndef LINGUA_H
#define LINGUA_H
#include <string>
#include "Model/cercastringa.h"

class Lingua
{
private:
    std::string nomeLingua;
    std::string livelloCompetenzaLinguistica;
public:
    Lingua();
    Lingua(std::string,std::string);
    ~Lingua();

    std::string getNomeLingua() const;
    std::string getLivelloCompetenzaLinguistica()const;

    void setNomeLingua(const std::string&);
    void setLivelloCompetenzaLinguistica(const std::string&);

    bool contieneStringa(const std::string&)const;

};

#endif // LINGUA_H

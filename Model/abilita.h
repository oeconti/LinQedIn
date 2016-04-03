#ifndef ABILITA_H
#define ABILITA_H
#include <string>
#include "Model/cercastringa.h"

class Abilita
{
private:
    std::string nomeAbilita;
    std::string descrizioneAbilita;
public:
    Abilita();
    Abilita(std::string,std::string);

    std::string getNomeAbilita()const;
    std::string getDescrizioneAbilita()const;

    void setNomeAbilita(const std::string&);
    void setDescrizioneAbilita(const std::string&);

    bool contieneStringa(const std::string&)const;
};

#endif // ABILITA_H

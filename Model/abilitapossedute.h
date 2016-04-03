#ifndef ABILITAPOSSEDUTE_H
#define ABILITAPOSSEDUTE_H
#include <map>
#include "abilita.h"

class AbilitaPossedute
{
private:
    std::map<std::string,Abilita> abilitaPossedute;
public:
    AbilitaPossedute();
    ~AbilitaPossedute();

    typedef std::map<std::string,Abilita>::const_iterator const_iterator;
    const_iterator getAbilitaPosseduteBegin()const;
    const_iterator getAbilitaPosseduteEnd()const;
    int getAbilitaPosseduteSize()const;

    void inserisciAbilita(const Abilita&);
    void setAbilita(const std::string&,const Abilita&);
    void eliminaAbilita(const std::string&);

    bool contieneStringa(const std::string&)const;
};

#endif // ABILITAPOSSEDUTE_H

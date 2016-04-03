#include "Model/abilitapossedute.h"
//-----------------------------------------------------------------------------COSTRUTTORI-------------------------------------------------------------------------------------------------------------
AbilitaPossedute::AbilitaPossedute(){}

AbilitaPossedute::~AbilitaPossedute(){}

//------------------------------------------------------------------------------METODI-----------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------Get--------------------------------------------------------------------------------------------------------------------
AbilitaPossedute::const_iterator AbilitaPossedute::getAbilitaPosseduteBegin()const{
    return abilitaPossedute.begin();
}

AbilitaPossedute::const_iterator AbilitaPossedute::getAbilitaPosseduteEnd()const{
    return abilitaPossedute.end();
}

int AbilitaPossedute::getAbilitaPosseduteSize()const{
    return abilitaPossedute.size();
}
//------------------------------------------------------------------------------Set--------------------------------------------------------------------------------------------------------------------
void AbilitaPossedute::inserisciAbilita(const Abilita & ab){
    abilitaPossedute.insert(std::pair<std::string,Abilita>(ab.getNomeAbilita(),ab));
}

void AbilitaPossedute::setAbilita(const std::string& nome,const Abilita & ab){
    std::map<std::string,Abilita>::iterator it=abilitaPossedute.find(nome);
    abilitaPossedute.erase(it);
    abilitaPossedute.insert(std::pair<std::string,Abilita>(ab.getNomeAbilita(),ab));
}

void AbilitaPossedute::eliminaAbilita(const std::string& nome){
    std::map<std::string,Abilita>::iterator it=abilitaPossedute.find(nome);
    abilitaPossedute.erase(it);
}

bool AbilitaPossedute::contieneStringa(const std::string & stringaDaCercare) const{
    if(abilitaPossedute.count(stringaDaCercare)>0)
        return true;
    else{
        bool trovato=false;
        for(std::map<std::string,Abilita>::const_iterator it=abilitaPossedute.begin();it!=abilitaPossedute.end() && !trovato;it++){
            if(it->second.contieneStringa(stringaDaCercare))
                trovato=true;
        }
        return trovato;
    }
}

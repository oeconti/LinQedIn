#include "Model/lingueparlate.h"
//--------------------------------------------------------------------------COSTRUTTORI------------------------------------------------------------------
LingueParlate::LingueParlate(){}

LingueParlate::~LingueParlate(){}

//--------------------------------------------------------------------------METODI-----------------------------------------------------------------------
//--------------------------------------------------------------------------Get--------------------------------------------------------------------------
LingueParlate::const_iterator LingueParlate::getLingueParlateBegin()const{
    return lingueParlate.begin();
}

LingueParlate::const_iterator LingueParlate::getLingueParlateEnd()const{
    return lingueParlate.end();
}

int LingueParlate::getLingueParlateSize()const{
    return lingueParlate.size();
}
//--------------------------------------------------------------------------Set--------------------------------------------------------------------------
void LingueParlate::inserisciLingua(const Lingua & lingua){
    lingueParlate.insert(std::pair<std::string,Lingua>(lingua.getNomeLingua(),lingua));
}

void LingueParlate::setLingua(const std::string& nome, const Lingua & lingua){
    std::map<std::string,Lingua>::iterator it=lingueParlate.find(nome);
    lingueParlate.erase(it);
    lingueParlate.insert(std::pair<std::string,Lingua>(lingua.getNomeLingua(),lingua));
}

void LingueParlate::eliminaLingua(const std::string& nome){
    std::map<std::string,Lingua>::iterator it=lingueParlate.find(nome);
    lingueParlate.erase(it);
}
//-------------------------------------------------------------------------------------
bool LingueParlate::contieneStringa(const std::string & stringaDaCercare) const{
    if(lingueParlate.count(stringaDaCercare)>0)
        return true;
    else{
        bool trovato=false;
        for(const_iterator it=lingueParlate.begin();it!=lingueParlate.end() && !trovato;it++){
            if(it->second.contieneStringa(stringaDaCercare))
                trovato=true;
        }
        return trovato;
    }
}

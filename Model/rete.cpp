#include "Model/rete.h"
//------------------------------------------------------------------------------COSTRUTTORI-----------------------------------------------------------------------------------
Rete::Rete(){}

Rete::~Rete(){}
//-------------------------------------------------------------------------------METODI--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------Get----------------------------------------------------------------------------------------
Rete::const_iterator Rete::getReteBegin()const{
    return listaContatti.begin();
}

Rete::const_iterator Rete::getReteEnd()const{
    return listaContatti.end();
}

int Rete::getReteSize()const{
    return listaContatti.size();
}

bool Rete::controllaPresenzaContatto(const std::string & username) const{
    if(listaContatti.count(username)>0)
        return true;
    else
        return false;
}

//-------------------------------------------------------------------------------Set----------------------------------------------------------------------------------------
bool Rete::aggiungiUtente(const std::string& username,const SmartUtente& smUt){
    if(listaContatti.count(username)>0)
        return false;
    else{
        listaContatti.insert(std::pair<std::string,const SmartUtente*>(username, &smUt));
        return true;
    }
}

bool Rete::eliminaUtente(const std::string& username){
    if(listaContatti.count(username)==0)
        return false;
    else{
        std::map<std::string,const SmartUtente*>::iterator it=listaContatti.find(username);
        listaContatti.erase(it);
        return true;
    }
}

const SmartUtente* Rete::getSmartUtente(const_iterator it) const{
    return it->second;
}



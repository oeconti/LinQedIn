#include "Model/utentebase.h"
#include "Model/database.h"
//------------------------------------------COSTRUTTORI----------------------------------------------------------------
UtenteBase::UtenteBase(){}

UtenteBase::UtenteBase(const Profilo& info,const Login& log): UtenteGratis(info,log){}

UtenteBase::UtenteBase(Utente* ut):UtenteGratis(ut){}

//-------------------------------------------METODI---------------------------------------------------------------------

std::map<std::string,Utente*> UtenteBase::cercaUtente(Database* db,const std::string& stringa)const{
    std::map<std::string,Utente*>risRicerca;
    for(Database::const_iterator it=db->getDatabaseBegin();it!=db->getDatabaseEnd();it++){
        FuntoreBase fB(stringa);
        if(this!=(&*it->second) && fB(&*it->second))
            risRicerca.insert(std::pair<std::string,Utente*>(it->second->getUsername(),&*it->second));
    }
    return risRicerca;
}

std::vector<std::string> UtenteBase::getDescrizioneRicerca()const{
    std::vector<std::string> descrizione;
    descrizione.push_back("Basic");
    descrizione.push_back("Username");
    descrizione.push_back("Dati anagrafici");
    return descrizione;
}


//-------------------------------------------FUNTORI--------------------------------------------------------------------

UtenteBase::FuntoreBase::FuntoreBase(const std::string& stringa):Utente::FuntoreRicerca(stringa){}

bool UtenteBase::FuntoreBase::operator ()(Utente* utente)const{
    unsigned int contatore=0;
    bool trovato=false;
    for(unsigned int i=0;i<stringaDaCercareDivisa.size() && !trovato;i++){
        if(utente->datiAnagraficiContieneStringa(stringaDaCercareDivisa[i]) || utente->usernameContieneStringa(stringaDaCercareDivisa[i]))
            contatore++;
        if(contatore==stringaDaCercareDivisa.size())
            trovato=true;
    }
    return trovato;
}

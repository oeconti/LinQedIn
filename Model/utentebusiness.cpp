#include "Model/utentebusiness.h"
#include "Model/database.h"

//---------------------------------------------COSTRUTTORI---------------------------------------------------------------
UtenteBusiness::UtenteBusiness(){}

UtenteBusiness::UtenteBusiness(const Profilo& info,const Login& log): UtenteAPagamento(info,log){}

UtenteBusiness::UtenteBusiness(Utente* ut):UtenteAPagamento(ut){}
//----------------------------------------------METODI-------------------------------------------------------------------

std::map<std::string,Utente*> UtenteBusiness::cercaUtente(Database* db,const std::string& stringa)const{
    std::map<std::string,Utente*>risRicerca;
    for(Database::const_iterator it=db->getDatabaseBegin();it!=db->getDatabaseEnd();it++){
        FuntoreBusiness fB(stringa);
        if(this!=(&*it->second) && fB(&*it->second))
            risRicerca.insert(std::pair<std::string,Utente*>(it->second->getUsername(),&*it->second));
    }
    return risRicerca;
}

std::vector<std::string> UtenteBusiness::getDescrizioneRicerca()const{
    std::vector<std::string> descrizione;
    descrizione.push_back("Business");
    descrizione.push_back("Username");
    descrizione.push_back("Dati anagrafici");
    descrizione.push_back("Titolo di studio");
    descrizione.push_back("Lingue parlate");
    return descrizione;
}

//----------------------------------------------FUNTORE------------------------------------------------------------------

UtenteBusiness::FuntoreBusiness::FuntoreBusiness(const std::string& stringa):Utente::FuntoreRicerca(stringa){}

bool UtenteBusiness::FuntoreBusiness::operator ()(Utente* utente)const{
    unsigned int contatore=0;
    bool trovato=false;
    for(unsigned int i=0;i<stringaDaCercareDivisa.size() && !trovato;i++){
        if(utente->datiAnagraficiContieneStringa(stringaDaCercareDivisa[i]) ||
           utente->usernameContieneStringa(stringaDaCercareDivisa[i]) ||
           utente->espeScolasticheContieneStringa(stringaDaCercareDivisa[i]) ||
           utente->lingueParlateContieneStringa(stringaDaCercareDivisa[i]))
            contatore++;
        if(contatore==stringaDaCercareDivisa.size())
            trovato=true;
    }
    return trovato;
}


#include "Model/utenteexecutive.h"

//-------------------------------------------COSTRUTTORI-------------------------------------------------------------------------
UtenteExecutive::UtenteExecutive(){}

UtenteExecutive::UtenteExecutive(const Profilo& info,const Login& log): UtenteAPagamento(info,log){}

UtenteExecutive::UtenteExecutive(Utente* ut):UtenteAPagamento(ut) {}
//--------------------------------------------METODI-----------------------------------------------------------------------------
std::map<std::string,Utente*> UtenteExecutive::cercaUtente(Database* db,const std::string& stringa)const{
    std::map<std::string,Utente*>risRicerca;
    for(Database::const_iterator it=db->getDatabaseBegin();it!=db->getDatabaseEnd();it++){
        FuntoreExecutive fB(stringa);
        if(this!=(&*it->second) && fB(&*it->second))
            risRicerca.insert(std::pair<std::string,Utente*>(it->second->getUsername(),&*it->second));
    }
    return risRicerca;
}

std::vector<std::string> UtenteExecutive::getDescrizioneRicerca()const{
    std::vector<std::string> descrizione;
    descrizione.push_back("Executive");
    descrizione.push_back("Username");
    descrizione.push_back("Dati anagrafici");
    descrizione.push_back("Titolo di studio");
    descrizione.push_back("Lingue parlate");
    descrizione.push_back("Esperienze professionali");
    descrizione.push_back("Abilità personali");
    return descrizione;
}

//----------------------------------------------FUNTORE------------------------------------------------------------------

UtenteExecutive::FuntoreExecutive::FuntoreExecutive(const std::string& stringa):Utente::FuntoreRicerca(stringa){}

bool UtenteExecutive::FuntoreExecutive::operator ()(Utente* utente)const{
    unsigned int contatore=0;
    bool trovato=false;
    for(unsigned int i=0;i<stringaDaCercareDivisa.size() && !trovato;i++){
        if(utente->datiAnagraficiContieneStringa(stringaDaCercareDivisa[i]) ||
            utente->usernameContieneStringa(stringaDaCercareDivisa[i]) ||
            utente->espeScolasticheContieneStringa(stringaDaCercareDivisa[i]) ||
            utente->lingueParlateContieneStringa(stringaDaCercareDivisa[i]) ||
            utente->abilitaPosseduteContieneStringa(stringaDaCercareDivisa[i]) ||
            utente->espeProfessionaliContieneStringa(stringaDaCercareDivisa[i]))
            contatore++;
        if(contatore==stringaDaCercareDivisa.size())
            trovato=true;
    }
    return trovato;
}

/*

 */

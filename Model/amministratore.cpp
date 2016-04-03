#include "Model/amministratore.h"

//-------------------------------------------------COSTRUTTORI------------------------------------------------------------------
Amministratore::Amministratore():ptDb(0){}

Amministratore::~Amministratore(){
    delete ptDb;
}


//---------------------------------------------------METODI---------------------------------------------------------------------
void Amministratore::caricaDatabase(){
    ptDb=new Database();
    ptDb->caricaDatabase();
}

void Amministratore::salvaDatabase()const{
    ptDb->salvaDatabase();
}


bool Amministratore::inserisciNuovoUtente(Utente * ut){
    return ptDb->inserisciUtente(ut);
}

bool Amministratore::controllaPresenzaUsername(const std::string & username)const{
    return ptDb->controllaPresenzaUsername(username);
}

bool Amministratore::eliminaUtente(const std::string& username){
    return ptDb->eleminaUtente(username);
}

bool Amministratore::cambiaTipoUtente(const std::string & username,const std::string& nuovoTipo){
    return ptDb->cambiaTipoIscrizione(username,nuovoTipo);
}



Utente* Amministratore::getUtente(const std::string & username)const{
    return ptDb->getUtente(username);
}

SmartUtente& Amministratore::getSmartUtente(const std::string & username) const{
    return ptDb->getSmartUtente(username);
}

Database::const_iterator Amministratore::getDatabaseBegin()const{
    return ptDb->getDatabaseBegin();
}

Database::const_iterator Amministratore::getDatabaseEnd()const{
    return ptDb->getDatabaseEnd();
}

int Amministratore::getDatabaseSize()const{
    return ptDb->getDatabaseSize();
}


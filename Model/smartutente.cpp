#include "Model/smartutente.h"
//-------------------------------------COSTRUTTORI---------------------------------------------------------------
SmartUtente::SmartUtente(Utente* utPa):ut(utPa){}

SmartUtente::SmartUtente(const SmartUtente & smUt):ut(smUt.ut){}

SmartUtente::~SmartUtente(){
    delete ut;
}
//------------------------------------------METODI---------------------------------------------------------------------
//------------------------------------------Overloading----------------------------------------------------------------

SmartUtente& SmartUtente::operator =(Utente* nuovoUt){

    Utente* aux=ut;
    ut=nuovoUt;
    ::delete aux;
    return *this;
}

Utente* SmartUtente::operator->()const{
    return ut;
}

Utente& SmartUtente::operator *()const{
    return *ut;
}

bool SmartUtente::operator ==(const SmartUtente& smUt)const{
    return ut==smUt.ut;
}

bool SmartUtente::operator !=(const SmartUtente& smUt)const{
    return ut!=smUt.ut;
}

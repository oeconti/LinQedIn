#include "Model/anagrafica.h"

//--------------------------------COSTRUTTORI-------------------------------------------------------------------
Anagrafica::Anagrafica():sesso(0),nome("nome"),cognome("cognome"),dataNascita(0,0,0){}

Anagrafica::Anagrafica(const bool &sx, const std::string &nome, const std::string &cognome, const QDate & dataNascita, const Luogo &residenza):
    sesso(sx),nome(nome),cognome(cognome),dataNascita(dataNascita),residenza(residenza){}

//-------------------------------METODI--------------------------------------------------------------------------
//-------------------------------Get-----------------------------------------------------------------------------
bool Anagrafica::getSesso()const{
    return sesso;
}

std::string Anagrafica::getNome()const{
    return nome;
}

std::string Anagrafica::getCognome()const{
    return cognome;
}

QDate Anagrafica::getDataNascita()const{
    return dataNascita;
}

Luogo Anagrafica::getResidenza()const{
    return residenza;
}

//-------------------------------Set-----------------------------------------------------------------------------
void Anagrafica::setSesso(const bool &s){
    sesso=s;
}

void Anagrafica::setNome(const std::string &n){
    nome=n;
}

void Anagrafica::setCognome(const std::string &c){
    cognome=c;
}

void Anagrafica::setDataNascita(const QDate& data){
    dataNascita=data;
}


void Anagrafica::setResidenza(const Luogo& res){
   residenza=res;
}

//------------------------------------------------------------------------------------------------------------------
bool Anagrafica::contieneStringa(const std::string & stringaDaCercare)const{
    CercaStringa c(stringaDaCercare);
    return c.cerca(nome) || c.cerca(cognome) || residenza.contieneStringa(stringaDaCercare);
}

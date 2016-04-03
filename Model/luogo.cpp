#include "Model/luogo.h"

//--------------------------------------COSTRUTTORI-------------------------------------------------------------
Luogo::Luogo():via("via"),citta("citta"),provincia("provincia"),nazione("nazione"){}

Luogo::Luogo(const std::string &v,const std::string &c,
             const std::string &p,const std::string &n):via(v),citta(c),provincia(p),nazione(n){}


//--------------------------------------METODI------------------------------------------------------------------
//--------------------------------------Get---------------------------------------------------------------------
std::string Luogo::getVia() const{
    return via;
}

std::string Luogo::getCitta() const{
    return citta;
}

std::string Luogo::getProvincia()const{
    return provincia;
}

std::string Luogo::getNazione()const{
    return nazione;
}

//-------------------------------------Set-----------------------------------------------------------------------
void Luogo::setVia(const std::string &v){
    via=v;
}

void Luogo::setCitta(const std::string &c){
    citta=c;
}

void Luogo::setProvincia(const std::string &p){
    provincia=p;
}

void Luogo::setNazione(const std::string &n){
    nazione=n;
}

//----------------------------------------------------------------------------------------------------------------------

bool Luogo::contieneStringa(const std::string & stringaDaCercare) const{
    CercaStringa c(stringaDaCercare);
    return c.cerca(via) || c.cerca(citta) || c.cerca(provincia) || c.cerca(nazione);
}

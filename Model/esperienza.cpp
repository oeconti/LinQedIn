#include "Model/esperienza.h"

//---------------------------COSTRUTTORE---------------------------------------------------------------------------
Esperienza::Esperienza():inizio(0,0,0),fine(0,0,0),descrizione("Descrizione Esperienza"){}

Esperienza::Esperienza(const QDate & ini, const QDate &fin, const Luogo & luogoEsp, const std::string & descEsp):
    inizio(ini),fine(fin),locazione(luogoEsp),descrizione(descEsp){}


//---------------------------METODI----------------------------------------------------------------------------------
//---------------------------Get-------------------------------------------------------------------------------------
QDate Esperienza::getInizio() const
{
    return inizio;
}

QDate Esperienza::getFine() const{
    return fine;
}

Luogo Esperienza::getLuogo() const{
    return locazione;
}

std::string Esperienza::getDescrizione() const{
    return descrizione;
}
//---------------------------Set--------------------------------------------------------------------------------------

void Esperienza::setInizio(const QDate& ini){
    inizio=ini;
}


void Esperienza::setFine(const QDate& fin){
    fine=fin;
}


void Esperienza::setLuogo(const Luogo& luogo){
    locazione=luogo;
}

void Esperienza::setDescrizione(const std::string &desc){
    descrizione=desc;
}

//------------------------------------------------------------------------

bool Esperienza::contieneStringa(const std::string & stringaDaCercare) const{
    CercaStringa c(stringaDaCercare);
    return c.cerca(descrizione) || locazione.contieneStringa(stringaDaCercare);
}

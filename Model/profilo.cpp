#include "Model/profilo.h"
#include <iostream>
//------------------------------------------------COSTRUTTORI---------------------------------------------------------------
Profilo::Profilo(){}

Profilo::Profilo(const bool& sesso,const std::string &nome,const std::string& cognome,const QDate& dataNascita,const Luogo& residenza):
    datiAnagrafici(sesso,nome,cognome,dataNascita,residenza){}


//--------------------------------------------------METODI-------------------------------------------------------------------
//--------------------------------------------------Get----------------------------------------------------------------------
Anagrafica Profilo::getAnagrafica() const{
    return datiAnagrafici;
}

bool Profilo::getSesso()const{
    return datiAnagrafici.getSesso();
}
std::string Profilo::getNome()const{
    return datiAnagrafici.getNome();
}

std::string Profilo::getCognome()const{
    return datiAnagrafici.getCognome();
}

QDate Profilo::getDaNascita()const{
    return datiAnagrafici.getDataNascita();
}

Luogo Profilo::getResidenza()const{
    return datiAnagrafici.getResidenza();
}

EsperienzeProfessionali::const_iterator Profilo::getEsperienzeProfessionaliBegin()const{
    return esperienzeProfessionali.getEsperienzeProfessionaliBegin();
}

EsperienzeProfessionali::const_iterator Profilo::getEsperienzeProfessionaliEnd()const{
    return esperienzeProfessionali.getEsperienzeProfessionaliEnd();
}

int Profilo::getEsperienzeProfessionaliSize()const{
    return esperienzeProfessionali.getEsperienzeProfessionaliSize();
}

EsperienzeScolastiche::const_iterator Profilo::getEsperienzeScolasticheBegin()const{
    return esperienzeScolastiche.getEsperienzeScolasticheBegin();
}

EsperienzeScolastiche::const_iterator Profilo::getEsperienzeScolasticheEnd()const{
    return esperienzeScolastiche.getEsperienzeScolasticheeEnd();
}

int Profilo::getEsperienzeScolasticheSize()const{
    return esperienzeScolastiche.getEsperienzeScolasticheSize();
}

LingueParlate::const_iterator Profilo::getLingueParlateBegin()const{
    return lingueParlate.getLingueParlateBegin();
}

LingueParlate::const_iterator Profilo::getLingueParlateEnd()const{
    return lingueParlate.getLingueParlateEnd();
}

int Profilo::getLingueParlateSize()const{
    return lingueParlate.getLingueParlateSize();
}

AbilitaPossedute::const_iterator Profilo::getAbilitaPosseduteBegin()const{
    return abilitaPossedute.getAbilitaPosseduteBegin();
}

AbilitaPossedute::const_iterator Profilo::getAbilitaPosseduteEnd()const{
    return abilitaPossedute.getAbilitaPosseduteEnd();
}

int Profilo::getAbilitaPosseduteSize()const{
    return abilitaPossedute.getAbilitaPosseduteSize();
}



//-----------------------------------------Set------------------------------------------------------------------
void Profilo::setAnagrafica(const Anagrafica& dati){
    datiAnagrafici.setSesso(dati.getSesso());
    datiAnagrafici.setNome(dati.getNome());
    datiAnagrafici.setCognome(dati.getCognome());
    datiAnagrafici.setDataNascita(dati.getDataNascita());
    datiAnagrafici.setResidenza(dati.getResidenza());
}

void Profilo::setSesso(const bool & sex){
    datiAnagrafici.setSesso(sex);
}

void Profilo::setNome(const std::string& n){
    datiAnagrafici.setNome(n);
}

void Profilo::setCognome(const std::string & c){
    datiAnagrafici.setCognome(c);
}

void Profilo::setDataNascita(const QDate& data){
    datiAnagrafici.setDataNascita(data);
}

void Profilo::setResidenza(const Luogo& luogo){
    datiAnagrafici.setResidenza(luogo);
}
//----------------------------------------------------------------------------------------------------------
void Profilo::inserisciEsperienzaProfessionale(const EsperienzaProfessionale & esp){
    esperienzeProfessionali.inserisciEsperienzaProfessionale(esp);
}

void Profilo::setEsperienzaProfessionale(EsperienzeProfessionali::const_iterator & const_it, const EsperienzaProfessionale & esp){
    esperienzeProfessionali.setEsperienzaProfessionale(const_it,esp);
}

void Profilo::eliminaEsperienzaProfessionale(EsperienzeProfessionali::const_iterator & const_it){
    esperienzeProfessionali.eliminaEsperienzaProfessionale(const_it);
}
//------------------------------------------------------------------------------------------------------------
void Profilo::inserisciEsperienzaScolastica(const EsperienzaScolastica & esp){
    esperienzeScolastiche.inserisciEsperienzaScolastica(esp);
}

void Profilo::setEsperienzaScolastica(EsperienzeScolastiche::const_iterator & const_it, const EsperienzaScolastica & esp){
    esperienzeScolastiche.setEsperienzaScolastica(const_it,esp);
}

void Profilo::eliminaEsperienzaScolastica(EsperienzeScolastiche::const_iterator & const_it){
    esperienzeScolastiche.eliminaEsperinzaScolastica(const_it);
}
//------------------------------------------------------------------------------------------------------------
void Profilo::inserisciLingua(const Lingua & l){
    lingueParlate.inserisciLingua(l);
}

void Profilo::setLingua(const std::string& nome, const Lingua & l){
    lingueParlate.setLingua(nome,l);
}

void Profilo::eliminaLingua(const std::string& nome){
    lingueParlate.eliminaLingua(nome);
}
//------------------------------------------------------------------------------------------------------------
void Profilo::inserisciAbilita(const Abilita & ab){
    abilitaPossedute.inserisciAbilita(ab);
}

void Profilo::setAbilita(const std::string& nome, const Abilita & ab){
    abilitaPossedute.setAbilita(nome,ab);
}

void Profilo::eliminaAbilita(const std::string& nome){
    abilitaPossedute.eliminaAbilita(nome);
}


//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
bool Profilo::datiAnagrafContieneStringa(const std::string & stringaDaCercare) const{
    return datiAnagrafici.contieneStringa(stringaDaCercare);
}

bool Profilo::abilitaPosseduteContieneStringa(const std::string & stringaDaCercare) const{
    return abilitaPossedute.contieneStringa(stringaDaCercare);
}

bool Profilo::espeProfessionaliContieneStringa(const std::string & stringaDaCercare) const{
    return esperienzeProfessionali.contieneStringa(stringaDaCercare);
}

bool Profilo::espeScolasticheContieneStringa(const std::string & stringaDaCercare) const{
    return esperienzeScolastiche.contieneStringa(stringaDaCercare);
}

bool Profilo::lingueParlateContieneStringa(const std::string & stringaDaCercare) const{
    return lingueParlate.contieneStringa(stringaDaCercare);
}

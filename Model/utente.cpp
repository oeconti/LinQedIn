#include "Model/utente.h"
#include "Model/database.h"

#include <iostream>

//---------------------------------------COSTRUTTORI-------------------------------------------------------------------
Utente::Utente():profilo(new Profilo()),login(new Login()),rete(new Rete()){}

Utente::Utente(const Profilo& info,const Login& login):profilo(new Profilo(info)),login(new Login(login)),rete(new Rete){}

Utente::Utente(Utente* ut){
    profilo=ut->profilo;
    login=ut->login;
    rete=ut->rete;
}

Utente::~Utente(){}


void Utente::operator delete(void *ut){
    if(ut){
        Utente* aux=static_cast<Utente*>(ut);
        delete aux->login;
        delete aux->profilo;
        delete aux->rete;
    }
}


//--------------------------------------METODI---------------------------------------------------------------------------
//--------------------------------------Get------------------------------------------------------------------------------
Profilo Utente::getProfilo()const{
    return *profilo;
}

Login Utente::getLogin()const{
    return *login;
}


std::string Utente::getUsername()const{
    return  login->getUsername();
}

std::string Utente::getPassword()const{
    return login->getPassword();
}

bool Utente::getSesso()const{
    return profilo->getSesso();
}

std::string Utente::getNome()const{
    return profilo->getNome();
}

std::string Utente::getCognome()const{
    return profilo->getCognome();
}

QDate Utente::getDataNascita()const{
    return profilo->getDaNascita();
}

Luogo Utente::getResidenza()const{
    return profilo->getResidenza();
}

EsperienzeProfessionali::const_iterator Utente::getEsperienzeProfessionaliBegin()const{
    return profilo->getEsperienzeProfessionaliBegin();
}

EsperienzeProfessionali::const_iterator Utente::getEsperienzeProfessionaliEnd()const{
    return profilo->getEsperienzeProfessionaliEnd();
}

int Utente::getEsperienzeProfessionaliSize()const{
    return profilo->getEsperienzeProfessionaliSize();
}

EsperienzeScolastiche::const_iterator Utente::getEsperienzeScolasticheBegin()const{
    return profilo->getEsperienzeScolasticheBegin();
}

EsperienzeScolastiche::const_iterator Utente::getEsperienzeScolasticheEnd()const{
    return profilo->getEsperienzeScolasticheEnd();
}

int Utente::getEsperienzeScolasticheSize()const{
    return profilo->getEsperienzeScolasticheSize();
}

LingueParlate::const_iterator Utente::getLingueParlateBegin()const{
    return profilo->getLingueParlateBegin();
}

LingueParlate::const_iterator Utente::getLingueParlateEnd()const{
    return profilo->getLingueParlateEnd();
}

int Utente::getLingueParlateSize()const{
    return profilo->getLingueParlateSize();
}

AbilitaPossedute::const_iterator Utente::getAbilitaPosseduteBegin()const{
    return profilo->getAbilitaPosseduteBegin();
}

AbilitaPossedute::const_iterator Utente::getAbilitaPosseduteEnd()const{
    return profilo->getAbilitaPosseduteEnd();
}

int Utente::getAbilitaPosseduteSize()const{
    return profilo->getAbilitaPosseduteSize();
}

Rete::const_iterator Utente::getReteBegin()const{
    return rete->getReteBegin();
}

Rete::const_iterator Utente::getReteEnd()const{
    return rete->getReteEnd();
}

int Utente::getReteSize()const{
    return rete->getReteSize();
}

bool Utente::controllaPresenzaContattoRete(const std::string & username) const{
    return rete->controllaPresenzaContatto(username);
}

//--------------------------------------Set------------------------------------------------------------------------------

void Utente::setSesso(const bool & sex){
    profilo->setSesso(sex);
}

void Utente::setNome(const std::string& nome){
    profilo->setNome(nome);
}

void Utente::setCognome(const std::string & c){
    profilo->setCognome(c);
}

void Utente::setDataNascita(const QDate& data){
    profilo->setDataNascita(data);
}


void Utente::setResidenza(const Luogo& luogo){
    profilo->setResidenza(luogo);
}

void Utente::setUsername(const std::string & us){
    login->setUsername(us);
}

void Utente::setPassword(const std::string & pwd){
    login->setPassword(pwd);
}
//---------------------------------------------------------------------------------------------------------------------------
void Utente::inserisciEsperienzaProfessionale(const EsperienzaProfessionale &esp){
    profilo->inserisciEsperienzaProfessionale(esp);
}

void Utente::setEsperienzaProfessionale(EsperienzeProfessionali::const_iterator & const_it, const EsperienzaProfessionale &esp){
    profilo->setEsperienzaProfessionale(const_it,esp);
}

void Utente::eliminaEsperienzaProfessionale(EsperienzeProfessionali::const_iterator & const_it){
    profilo->eliminaEsperienzaProfessionale(const_it);
}
//---------------------------------------------------------------------------------------------------------------------------
void Utente::inserisciEsperienzaScolastica(const EsperienzaScolastica &esp){
    profilo->inserisciEsperienzaScolastica(esp);
}

void Utente::setEsperienzaScolastica(EsperienzeScolastiche::const_iterator & const_it, const EsperienzaScolastica &esp){
    profilo->setEsperienzaScolastica(const_it,esp);
}

void Utente::eliminaEsperienzaScolastica(EsperienzeScolastiche::const_iterator & const_it){
    profilo->eliminaEsperienzaScolastica(const_it);
}
//---------------------------------------------------------------------------------------------------------------------------
void Utente::inserisciAbilita(const Abilita &ab){
    profilo->inserisciAbilita(ab);
}

void Utente::setAbilita(const std::string& nome, const Abilita &ab){
    profilo->setAbilita(nome,ab);
}

void Utente::eliminaAbilita(const std::string& nome){
    profilo->eliminaAbilita(nome);
}
//---------------------------------------------------------------------------------------------------------------------------
void Utente::inserisciLingua(const Lingua &ab){
    profilo->inserisciLingua(ab);
}

void Utente::setLingua(const std::string& nome, const Lingua &ab){
    profilo->setLingua(nome,ab);
}

void Utente::eliminaLingua(const std::string& nome){
    profilo->eliminaLingua(nome);
}
//---------------------------------------------------------------------------------------------------------------------------
void Utente::inserisciContattoRete(const std::string & username, const SmartUtente & smUt){
    rete->aggiungiUtente(username,smUt);
}

void Utente::eliminaContattoRete(const std::string & username){
    rete->eliminaUtente(username);
}

const SmartUtente* Utente::getContattoReteSmart(Rete::const_iterator it){
    return rete->getSmartUtente(it);

}

//------------------------------------------------------------------------------------------------------------------------------
bool Utente::datiAnagraficiContieneStringa(const std::string & stringaDaCercare) const{
    return profilo->datiAnagrafContieneStringa(stringaDaCercare);
}

bool Utente::abilitaPosseduteContieneStringa(const std::string & stringaDaCercare) const{
    return profilo->abilitaPosseduteContieneStringa(stringaDaCercare);
}

bool Utente::espeProfessionaliContieneStringa(const std::string & stringaDaCercare) const{
    return profilo->espeProfessionaliContieneStringa(stringaDaCercare);
}

bool Utente::espeScolasticheContieneStringa(const std::string & stringaDaCercare) const{
    return profilo->espeScolasticheContieneStringa(stringaDaCercare);
}

bool Utente::lingueParlateContieneStringa(const std::string & stringaDaCercare) const{
    return profilo->lingueParlateContieneStringa(stringaDaCercare);
}

bool Utente::usernameContieneStringa(const std::string & stringaDaCercare) const{
    return login->contieneStringaUsername(stringaDaCercare);
}

//-----------------------------------------------------FUNTORE-----------------------------------------------------------------

Utente::FuntoreRicerca::FuntoreRicerca(const std::string& stringa):stringaDaCercareDivisa(dividiStringa(stringa)){}
//----------------------------------------------------
std::vector<std::string> Utente::FuntoreRicerca::dividiStringa(const std::string& stringa){
    std::stringstream ss(stringa);
    std::string tok;
    char delimiter=' ';
    std::vector<std::string> stringaV;
    while(getline(ss, tok, delimiter)) {
        stringaV.push_back(tok);
    }
    return stringaV;
}




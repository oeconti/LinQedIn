#include "amministratorecontroller.h"
#include <iostream>

//------------------------------------------------------------COSTRUTTORI---------------------------------------------------------------------------------------------------------------------
AmministratoreController::AmministratoreController(Amministratore* adM,AmministratoreView* adV):
    adminModel(adM),adminView(adV){
    connect(adminView,SIGNAL(signalEliminaUtente(std::string)),this,SLOT(eliminaUtente(std::string)));
    connect(adminView,SIGNAL(signalCambiaTipoUtente(std::string,std::string)),this,SLOT(cambiaTipoUtente(std::string,std::string)));
    connect(adminView,SIGNAL(signalLogoutAdmin()),this,SLOT(logoutAdminView()));
}

AmministratoreController::~AmministratoreController(){}

//-------------------------------------------------------------METODI--------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------Metodi Logici--------------------------------------------------------------------------------------------------------------------
void AmministratoreController::caricaDatabase(){
    adminModel->caricaDatabase();
}

void AmministratoreController::salvaDatabase()const{
    adminModel->salvaDatabase();
}

bool AmministratoreController::inserisciNuovoUtente(Utente * ut){
    return adminModel->inserisciNuovoUtente(ut);
}

bool AmministratoreController::controllaPresenzaUsername(const std::string & username) const{
    return adminModel->controllaPresenzaUsername(username);
}

Utente* AmministratoreController::getUtente(const std::string& username)const{
    return adminModel->getUtente(username);
}

SmartUtente& AmministratoreController::getSmartUtente(const std::string & username) const{
    return adminModel->getSmartUtente(username);
}

Database::const_iterator AmministratoreController::getDatabaseBegin()const{
    return adminModel->getDatabaseBegin();
}

Database::const_iterator AmministratoreController::getDatabaseEnd()const{
    return adminModel->getDatabaseEnd();
}

int AmministratoreController::getDatabaseSize()const{
    return adminModel->getDatabaseSize();
}

//------------------------------------------------------------Slots----------------------------------------------------------------------------------------------------------------


void AmministratoreController::eliminaUtente(std::string username){
    adminModel->eliminaUtente(username);
    adminModel->salvaDatabase();
    emit signalUtEliminato();
}

void AmministratoreController::cambiaTipoUtente(std::string username, std::string nuovoTipo){
    adminModel->cambiaTipoUtente(username,nuovoTipo);
    adminModel->salvaDatabase();

    emit signalUtCambiato();
}

void AmministratoreController::logoutAdminView(){
    emit signalLogoutAdminView();
}

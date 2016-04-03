#include "controller.h"

Controller::Controller(){
    caricaSchermataInizialeView();
}

Controller::~Controller(){}

void Controller::caricaSchermataInizialeView(){
    schermataInizialeV=new SchermataInizialeView();
    connect(schermataInizialeV,SIGNAL(signalAmministratore()),this,SLOT(caricaAdminView()));
    connect(schermataInizialeV,SIGNAL(signalUtente()),this,SLOT(caricaLoginView()));
}

void Controller::caricaAdminView(){
    schermataInizialeV->close();
    delete schermataInizialeV;
    adminGeneralController=new AmministratoreGeneralController;
    connect(adminGeneralController,SIGNAL(signalLogoutAdminView()),this,SLOT(adminLogout()));
}

void Controller::adminLogout(){
    delete adminGeneralController;
    caricaSchermataInizialeView();
}

void Controller::caricaLoginView(){
    schermataInizialeV->close();
    delete schermataInizialeV;
    loginView=new LoginUtenteView;
    connect(loginView,SIGNAL(signalAnnulla()),this,SLOT(annullaLogin()));
    connect(loginView,SIGNAL(signalLoginCorretto(std::string)),this,SLOT(caricaUtenteView(std::string)));
}

void Controller::annullaLogin(){
    loginView->close();
    delete loginView;
    caricaSchermataInizialeView();
}

void Controller::caricaUtenteView(std::string username){
    loginView->close();
    delete loginView;
    utGeneralControllorer=new UtenteGeneralController(username);
    connect(utGeneralControllorer,SIGNAL(signalLogoutUtente()),this,SLOT(utenteLogout()));
}

void Controller::utenteLogout(){
    delete utGeneralControllorer;
    caricaSchermataInizialeView();
}

#include "amministratoregeneralcontroller.h"
#include <iostream>

AmministratoreGeneralController::AmministratoreGeneralController(){
    adminModel=new Amministratore();
    adminModel->caricaDatabase();
    adminView=new AmministratoreView(adminModel);
    adminController=new AmministratoreController(adminModel,adminView);
    caricaConnect();
}

AmministratoreGeneralController::~AmministratoreGeneralController(){}


void AmministratoreGeneralController::CaricaInsUtView(){
    adminController->salvaDatabase();
    delete adminController;
    delete adminView;
    adminModel->caricaDatabase();
    insUtView=new InserisciUtView(adminModel);
    insUtController=new InserisciUtController(adminModel,insUtView);
    connect(insUtController,SIGNAL(creatoNuovoUtente(bool)),this,SLOT(inseritoUtente(bool)));
}

void AmministratoreGeneralController::inseritoUtente(bool inserito){
    delete insUtView;
    delete insUtController;
    adminModel->caricaDatabase();
    adminView=new AmministratoreView(adminModel);
    adminController=new AmministratoreController(adminModel,adminView);
    if(inserito){
        dialMessage=new DialogMessage("Creazione Utente","Utente creato con successo","Ok");
        dialMessage->show();
    }
    caricaConnect();
}


void AmministratoreGeneralController::eliminatoUtente(){
    delete adminView;
    delete adminController;
    adminModel->caricaDatabase();
    adminView=new AmministratoreView(adminModel);
    adminController=new AmministratoreController(adminModel,adminView);

    dialMessage=new DialogMessage("Eliminazione Utente","Utente eliminato con successo","Ok");
    dialMessage->show();
    caricaConnect();
}

void AmministratoreGeneralController::cambiatoUtente(){
    delete adminView;
    delete adminController;
    adminModel->caricaDatabase();
    adminView=new AmministratoreView(adminModel);
    adminController=new AmministratoreController(adminModel,adminView);

    dialMessage=new DialogMessage("Cambio Iscrizione","Iscrizione cambiata con successo","Ok");
    dialMessage->show();
    caricaConnect();
}

void AmministratoreGeneralController::caricaConnect(){
    connect(adminView,SIGNAL(signalInserisciUtente()),this,SLOT(CaricaInsUtView()));
    connect(adminController,SIGNAL(signalUtEliminato()),this,SLOT(eliminatoUtente()));
    connect(adminController,SIGNAL(signalUtCambiato()),this,SLOT(cambiatoUtente()));
    connect(adminController,SIGNAL(signalLogoutAdminView()),this,SLOT(logoutAdminView()));
}

void AmministratoreGeneralController::logoutAdminView(){
    adminView->close();
    delete adminView;
    delete adminController;
    delete adminModel;
    emit signalLogoutAdminView();
}

#include "utentegeneralcontroller.h"
#include <iostream>

UtenteGeneralController::UtenteGeneralController(std::string user):databaseModel(0),utenteController(0),utenteView(0){
    databaseModel=new Database;
    databaseModel->caricaDatabase();
    creaUtenteView(user);
}

UtenteGeneralController::~UtenteGeneralController(){}


void UtenteGeneralController::creaUtenteView(std::string username){
    utenteView=new UtenteView(databaseModel->getUtente(username));
    utenteController=new UtenteController(databaseModel,databaseModel->getUtente(username),utenteView);
    creaConnect();
    utenteView->showMaximized();
}

void UtenteGeneralController::refreshUtenteView(std::string username, std::string messaggio){
    bool maximized=utenteView->isMaximized();
    delete utenteView;
    delete utenteController;
    databaseModel->caricaDatabase();
    utenteView=new UtenteView(databaseModel->getUtente(username));
    utenteController=new UtenteController(databaseModel,databaseModel->getUtente(username),utenteView);
    if(maximized)
        utenteView->showMaximized();
    else
        utenteView->show();
    creaConnect();
    DialogMessage* dialMessage=new DialogMessage("",messaggio,"Ok");
    dialMessage->show();
}

void UtenteGeneralController::creaConnect(){
    connect(utenteController,SIGNAL(signalAbilitaInserita(std::string)),this,SLOT(abilitaInserita(std::string)));
    connect(utenteController,SIGNAL(signalLinguaAggiunta(std::string)),this,SLOT(linguaAggiunta(std::string)));
    connect(utenteController,SIGNAL(signalEsperienzaProfAggiunta(std::string)),this,SLOT(esperienzaProfAggiunta(std::string)));
    connect(utenteController,SIGNAL(signalEsperienzaScolAggiunta(std::string)),this,SLOT(esperienzaScolAggiunta(std::string)));
    connect(utenteController,SIGNAL(signalDatiAnagraficiModificati(std::string)),this,SLOT(datiAnagraficiModificati(std::string)));
    connect(utenteController,SIGNAL(signalLinguaModificata(std::string)),this,SLOT(linguaModificata(std::string)));
    connect(utenteController,SIGNAL(signalLinguaEliminata(std::string)),this,SLOT(linguaEliminata(std::string)));
    connect(utenteController,SIGNAL(signalAbilitaModificata(std::string)),this,SLOT(abilitaModificata(std::string)));
    connect(utenteController,SIGNAL(signalAbilitaEliminata(std::string)),this,SLOT(abilitaEliminata(std::string)));
    connect(utenteController,SIGNAL(signalEsperienzaScolasticaModificata(std::string)),this,SLOT(esperienzaScolMod(std::string)));
    connect(utenteController,SIGNAL(signalEspScolEliminata(std::string)),this,SLOT(esperienzaScolEliminata(std::string)));
    connect(utenteController,SIGNAL(signalEspProfModificata(std::string)),this,SLOT(esperienzaProfModificata(std::string)));
    connect(utenteController,SIGNAL(signalEspProfEliminata(std::string)),this,SLOT(esperienzaProfEliminata(std::string)));
    connect(utenteController,SIGNAL(signalContattoRimosso(std::string)),this,SLOT(contattoReteRimossso(std::string)));
    connect(utenteController,SIGNAL(signalLogoutUtente()),this,SLOT(logoutUtente()));
}

void UtenteGeneralController::abilitaInserita(std::string username){
    refreshUtenteView(username,"Abilità inserita con successo");
}

void UtenteGeneralController::linguaAggiunta(std::string username){
    refreshUtenteView(username,"Lingua aggiunta con successo");
}

void UtenteGeneralController::esperienzaProfAggiunta(std::string username){
    refreshUtenteView(username,"Esperienza professionale aggiunta con successo");
}

void UtenteGeneralController::esperienzaScolAggiunta(std::string username){
    refreshUtenteView(username,"Titolo di studio aggiunto con successo");
}

void UtenteGeneralController::datiAnagraficiModificati(std::string username){
    refreshUtenteView(username,"Dati anagrafici modificati con successo");
}

void UtenteGeneralController::linguaModificata(std::string username){
    refreshUtenteView(username,"Lingua modificata con successo");
}

void UtenteGeneralController::linguaEliminata(std::string username){
    refreshUtenteView(username,"Lingua eliminata con successo");
}

void UtenteGeneralController::abilitaModificata(std::string username){
    refreshUtenteView(username,"Conoscenza modificata con successo");
}

void UtenteGeneralController::abilitaEliminata(std::string username){
    refreshUtenteView(username,"Conoscenza eliminata con successo");
}

void UtenteGeneralController::esperienzaScolMod(std::string username){
    refreshUtenteView(username,"Titolo di studio modificato con successo");
}

void UtenteGeneralController::esperienzaScolEliminata(std::string username){
    refreshUtenteView(username,"Titolo di studio eliminato con successo");
}

void UtenteGeneralController::esperienzaProfModificata(std::string username){
    refreshUtenteView(username,"Esperinza professionale modificata con successo");
}

void UtenteGeneralController::esperienzaProfEliminata(std::string username){
    refreshUtenteView(username,"Esperinza professionale eliminata con successo");

}

void UtenteGeneralController::contattoReteRimossso(std::string username){
refreshUtenteView(username,"Contatto rimosso dall rete con successo");
}

void UtenteGeneralController::logoutUtente(){
    utenteView->close();
    delete utenteController;
    delete utenteView;
    delete databaseModel;
    emit signalLogoutUtente();
}


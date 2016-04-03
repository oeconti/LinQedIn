#include "utentecontroller.h"

UtenteController::UtenteController(Database* db,Utente* ut,UtenteView* utV):database(db),utente(ut),utenteView(utV){

    connect(utenteView,SIGNAL(signalInserisciAbilita(QStringList)),this,SLOT(inserisciAbilita(QStringList)));
    connect(utenteView,SIGNAL(signalModificaAbilita(QStringList)),this,SLOT(modficiaAbilita(QStringList)));
    connect(utenteView,SIGNAL(signalEliminaAbilita(std::string)),this,SLOT(eliminaAbilita(std::string)));

    connect(utenteView,SIGNAL(signalInserisciLingua(QStringList)),this,SLOT(inserisciLingua(QStringList)));
    connect(utenteView,SIGNAL(signalModificaLingua(QStringList)),this,SLOT(modificaLingua(QStringList)));
    connect(utenteView,SIGNAL(signalEliminaLingua(std::string)),this,SLOT(eliminaLingua(std::string)));

    connect(utenteView,SIGNAL(signalInserisciEspProf(QStringList)),this,SLOT(inserisciEspProf(QStringList)));
    connect(utenteView,SIGNAL(signalModificaEspProf(EsperienzeProfessionali::const_iterator,QStringList)),
            this,SLOT(modificaEspProf(EsperienzeProfessionali::const_iterator,QStringList)));
    connect(utenteView,SIGNAL(signalEliminaEspProf(EsperienzeProfessionali::const_iterator)),this,SLOT(eliminaEspProf(EsperienzeProfessionali::const_iterator)));

    connect(utenteView,SIGNAL(signalInserisciEspScol(QStringList)),this,SLOT(inserisciEspScol(QStringList)));
    connect(utenteView,SIGNAL(signalModificaEspScol(EsperienzeScolastiche::const_iterator,QStringList)),
            this,SLOT(modificaEspScol(EsperienzeScolastiche::const_iterator,QStringList)));
    connect(utenteView,SIGNAL(signalEliminaEspScol(EsperienzeScolastiche::const_iterator)),this,SLOT(eliminaEspScol(EsperienzeScolastiche::const_iterator)));

    connect(utenteView,SIGNAL(signalModificaDatiAnag(QStringList)),this,SLOT(modificaDatiAnagrafici(QStringList)));

    connect(utenteView,SIGNAL(signalRimuoviContattoRete(std::string)),this,SLOT(eliminaContattoRete(std::string)));
    connect(utenteView,SIGNAL(signalAggiungiContattoRete(std::string)),this,SLOT(aggiungiContattoRete(std::string)));

    connect(utenteView,SIGNAL(signalCerca(std::string)),this,SLOT(cerca(std::string)));

    connect(utenteView,SIGNAL(signalLogoutUtente()),this,SLOT(logoutUtente()));
}

UtenteController::~UtenteController(){}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------Abilita---------------------------------------------------------------------------------------

void UtenteController::inserisciAbilita(QStringList abilita){
    utente->inserisciAbilita(Abilita(abilita[0].toStdString(),abilita[1].toStdString()));
    database->salvaDatabase();
    emit signalAbilitaInserita(utente->getUsername());
}

void UtenteController::modficiaAbilita(QStringList abilita){
    utente->setAbilita(abilita[0].toStdString(),Abilita(abilita[1].toStdString(),abilita[2].toStdString()));

    database->salvaDatabase();

    emit signalAbilitaModificata(utente->getUsername());
}

void UtenteController::eliminaAbilita(std::string a){
    utente->eliminaAbilita(a);

    database->salvaDatabase();

    emit signalAbilitaEliminata(utente->getUsername());
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------Lingua------------------------------------------------------------------------------------------

void UtenteController::inserisciLingua(QStringList lingua){
    utente->inserisciLingua(Lingua(lingua[0].toStdString(),lingua[1].toStdString()));
    database->salvaDatabase();
    emit signalLinguaAggiunta(utente->getUsername());
}

void UtenteController::modificaLingua(QStringList lingua){
    utente->setLingua(lingua[0].toStdString(),Lingua(lingua[1].toStdString(),lingua[2].toStdString()));

    database->salvaDatabase();

    emit signalLinguaModificata(utente->getUsername());
}

void UtenteController::eliminaLingua(std::string lingua){
    utente->eliminaLingua(lingua);

    database->salvaDatabase();

    emit signalLinguaEliminata(utente->getUsername());
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------Esperienza professionale------------------------------------------------------------------------------

void UtenteController::inserisciEspProf(QStringList listaEsp){
    utente->inserisciEsperienzaProfessionale(
        EsperienzaProfessionale(listaEsp[0].toStdString(),listaEsp[1].toStdString(),
        QDate::fromString(listaEsp[2],"dd.MM.yyyy"),
        QDate::fromString(listaEsp[3],"dd.MM.yyyy"),
        Luogo("N.S",listaEsp[4].toStdString(),listaEsp[5].toStdString(),listaEsp[6].toStdString()),
        listaEsp[7].toStdString()));

    database->salvaDatabase();
    emit signalEsperienzaProfAggiunta(utente->getUsername());
}

void UtenteController::modificaEspProf(EsperienzeProfessionali::const_iterator it, QStringList listaEsp){
    utente->setEsperienzaProfessionale(
            it,EsperienzaProfessionale(listaEsp[0].toStdString(),listaEsp[1].toStdString(),
            QDate::fromString(listaEsp[2],"dd.MM.yyyy"),
            QDate::fromString(listaEsp[3],"dd.MM.yyyy"),
            Luogo("N:S",listaEsp[4].toStdString(),listaEsp[5].toStdString(),listaEsp[6].toStdString()),
            listaEsp[7].toStdString()));

    database->salvaDatabase();

    emit signalEspProfModificata(utente->getUsername());
}

void UtenteController::eliminaEspProf(EsperienzeProfessionali::const_iterator it){
    utente->eliminaEsperienzaProfessionale(it);

    database->salvaDatabase();

    emit signalEspProfEliminata(utente->getUsername());
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------Esperienza scolastica----------------------------------------------------------------------------------

void UtenteController::inserisciEspScol(QStringList listaEsp){
    utente->inserisciEsperienzaScolastica(
                EsperienzaScolastica(listaEsp[0].toStdString(),listaEsp[1].toStdString(),listaEsp[2].toStdString(),
                QDate::fromString(listaEsp[3],"dd.MM.yyyy"),
                QDate::fromString(listaEsp[4],"dd.MM.yyyy"),
                Luogo("N.S",listaEsp[5].toStdString(),listaEsp[6].toStdString(),listaEsp[7].toStdString()),
                listaEsp[8].toStdString()));
    database->salvaDatabase();
    emit signalEsperienzaScolAggiunta(utente->getUsername());
}

void UtenteController::modificaEspScol(EsperienzeScolastiche::const_iterator it, QStringList listaEsp){
    utente->setEsperienzaScolastica(it,EsperienzaScolastica(listaEsp[0].toStdString(),listaEsp[1].toStdString(),listaEsp[2].toStdString(),
            QDate::fromString(listaEsp[3],"dd.MM.yyyy"),
            QDate::fromString(listaEsp[4],"dd.MM.yyyy"),
            Luogo("N.S",listaEsp[5].toStdString(),listaEsp[6].toStdString(),listaEsp[7].toStdString()),
            listaEsp[8].toStdString()));
    database->salvaDatabase();

    emit signalEsperienzaScolasticaModificata(utente->getUsername());

}

void UtenteController::eliminaEspScol(EsperienzeScolastiche::const_iterator it){
    utente->eliminaEsperienzaScolastica(it);

    database->salvaDatabase();

    emit signalEspScolEliminata(utente->getUsername());
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------Dati anagrafici--------------------------------------------------------------------------------

void UtenteController::modificaDatiAnagrafici(QStringList listaDati){
    if(listaDati[0]=="1")
        utente->setSesso(1);
    else
        utente->setSesso(0);
    utente->setNome(listaDati[1].toStdString());
    utente->setCognome(listaDati[2].toStdString());
    utente->setResidenza(Luogo(listaDati[3].toStdString(),listaDati[4].toStdString(),listaDati[5].toStdString(),listaDati[6].toStdString()));
    utente->setDataNascita(QDate::fromString(listaDati[7],"dd.MM.yyyy"));
    database->salvaDatabase();

    emit signalDatiAnagraficiModificati(utente->getUsername());
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------Rete--------------------------------------------------------------------------------------------

void UtenteController::eliminaContattoRete(std::string username){
    utente->eliminaContattoRete(username);
    database->salvaDatabase();
    emit signalContattoRimosso(utente->getUsername());
}

void UtenteController::aggiungiContattoRete(std::string username){

    utente->inserisciContattoRete(username,database->getSmartUtente(username));

    database->salvaDatabase();

    DialogMessage* dial=new DialogMessage("Aggiungi contatto","Contatto aggiunto con successo","Indietro");
    dial->show();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------Cerca-----------------------------------------------------------------------------------------

std::map<std::string,Utente*> UtenteController::cerca(std::string stringaDaCercare) const{
    return utente->cercaUtente(database,stringaDaCercare);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------Logout------------------------------------------------------------------------------------------

void UtenteController::logoutUtente(){
    emit signalLogoutUtente();
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

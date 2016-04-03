#include "inserisciutcontroller.h"

InserisciUtController::InserisciUtController(Amministratore* a,InserisciUtView* utV):admin(a),insUtView(utV){
    connect(insUtView,SIGNAL(creaUtBasic(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string)),this,
            SLOT(creaBase(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string)));

    connect(insUtView,SIGNAL(creaUtBusiness(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string)),this,
            SLOT(creaBusiness(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string)));

    connect(insUtView,SIGNAL(creaUtExecutive(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string)),this,
            SLOT(creaExecutive(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string)));
    connect(insUtView,SIGNAL(utNonCreato()),this,SLOT(utNonCreato()));
}

InserisciUtController::~InserisciUtController(){}

//------------------------------------------METODI LOGICI

void InserisciUtController::caricaDatabase(){
    admin->caricaDatabase();
}

void InserisciUtController::salvaDatabase()const{
    admin->salvaDatabase();
}

void InserisciUtController::inserisciUt(Utente* ut){
    admin->inserisciNuovoUtente(ut);
}

void InserisciUtController::creaBase(bool sesso,std::string username, std::string pwd, std::string nome, std::string cognome, QDate dNascita,
                                     std::string via, std::string provincia, std::string citta, std::string nazione){
    inserisciUt(new UtenteBase(Profilo(sesso,nome,cognome,dNascita,Luogo(via,provincia,citta,nazione)),Login(username,pwd)));
    salvaDatabase();
    emit creatoNuovoUtente(true);
}


void InserisciUtController::creaBusiness(bool sesso,std::string username, std::string pwd, std::string nome, std::string cognome, QDate dNascita,
                                     std::string via, std::string provincia, std::string citta, std::string nazione){
    inserisciUt(new UtenteBusiness(Profilo(sesso,nome,cognome,dNascita,Luogo(via,provincia,citta,nazione)),Login(username,pwd)));
    salvaDatabase();
    emit creatoNuovoUtente(true);
}

void InserisciUtController::creaExecutive(bool sesso,std::string username, std::string pwd, std::string nome, std::string cognome, QDate dNascita,
                                     std::string via, std::string provincia, std::string citta, std::string nazione){
    inserisciUt(new UtenteExecutive(Profilo(sesso,nome,cognome,dNascita,Luogo(via,provincia,citta,nazione)),Login(username,pwd)));
    salvaDatabase();
    emit creatoNuovoUtente(true);
}

void InserisciUtController::utNonCreato(){
    emit creatoNuovoUtente(false);
}

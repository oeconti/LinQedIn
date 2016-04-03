#include "utenteview.h"

UtenteView::UtenteView(Utente* ut):utente(ut){
    setView();
    connect(btnInsAbilita,SIGNAL(clicked()),this,SLOT(caricaInsAbilitaView()));
    connect(btnInsLingua,SIGNAL(clicked()),this,SLOT(caricaInsLinguaView()));
    connect(btnInsEspLav,SIGNAL(clicked()),this,SLOT(caricaInsEspProfView()));
    connect(btnInsEspScol,SIGNAL(clicked()),this,SLOT(caricaInsEspScolView()));
    connect(btnModifica,SIGNAL(clicked()),this,SLOT(caricaModificaProfiloView()));
    connect(btnCerca,SIGNAL(clicked()),this,SLOT(caricaCercaView()));
    connect(btnLogout,SIGNAL(clicked()),this,SLOT(logoutUtente()));
}

UtenteView::~UtenteView(){}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::setView(){
    this->setMinimumHeight(700);

    creaScrollArea();
    widgetDestro=new QWidget(this);
    creaBoxGenerale();
    creaBoxProfilo();
    creaBoxLogout();

    QVBoxLayout* vWidLay=new QVBoxLayout;
    vWidLay->addWidget(boxGenerale);
    vWidLay->addWidget(boxProfilo);
    vWidLay->addWidget(boxLogout,Qt::AlignBottom);
    widgetDestro->setLayout(vWidLay);

    QGridLayout* gridLay=new QGridLayout;
    gridLay->addWidget(profV,0,0);
    gridLay->addWidget(widgetDestro,0,1,Qt::AlignTop | Qt::AlignLeft );

    this->setLayout(gridLay);
    //this->show();
}

void UtenteView::creaScrollArea(){
    profV=new ProfiloView(this,utente);
}

void UtenteView::creaBoxGenerale(){
    boxGenerale=new QGroupBox("Cerca e rete",widgetDestro);
    btnCerca=new QPushButton("Cerca utente",boxGenerale);
    btnCerca->setFixedHeight(40);
    btnVisualizzaRete=new QPushButton("Visualizza rete",boxGenerale);
    connect(btnVisualizzaRete,SIGNAL(clicked()),this,SLOT(caricaReteView()));
    btnVisualizzaRete->setFixedHeight(40);
    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(btnCerca);
    vLay->addWidget(btnVisualizzaRete);
    boxGenerale->setLayout(vLay);
}

void UtenteView::creaBoxProfilo(){
    boxProfilo=new QGroupBox("Profilo personale", widgetDestro);
    btnModifica=new QPushButton("Modifica Profilo",boxProfilo);
    btnModifica->setFixedHeight(40);
    btnInsAbilita=new QPushButton("Aggiungi abilità",boxProfilo);
    btnInsAbilita->setFixedHeight(40);
    btnInsEspLav=new QPushButton("Aggiungi esperienza professionale",boxProfilo);
    btnInsEspLav->setFixedHeight(40);
    btnInsEspScol=new QPushButton("Aggiungi titolo di studio",boxProfilo);
    btnInsEspScol->setFixedHeight(40);
    btnInsLingua=new QPushButton("Aggiungi lingua parlata",boxProfilo);
    btnInsLingua->setFixedHeight(40);
    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(btnModifica);
    vLay->addWidget(btnInsAbilita);
    vLay->addWidget(btnInsLingua);
    vLay->addWidget(btnInsEspLav);
    vLay->addWidget(btnInsEspScol);
    boxProfilo->setLayout(vLay);
}

void UtenteView::creaBoxLogout(){
    boxLogout=new QGroupBox("Esci",widgetDestro);
    btnLogout=new QPushButton("Logout",boxLogout);
    btnLogout->setFixedHeight(40);
    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(btnLogout);
    boxLogout->setLayout(vLay);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------Abilità-------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
void UtenteView::caricaInsAbilitaView(){
    insAbV=new EditAbilita(this);
    connect(insAbV,SIGNAL(signalInserisciAbilita(QStringList)),this,SLOT(inserisciAbilita(QStringList)));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::inserisciAbilita(QStringList abilita){
    insAbV->close();
    delete insAbV;
    emit signalInserisciAbilita(abilita);

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::caricaModificaAbilitaView(){
    modProV->close();
    delete modProV;
    modAbilitaV=new ModificaAbitliaView(this,utente);
    connect(modAbilitaV,SIGNAL(signlaModificaAbilita(QStringList)),this,SLOT(modificaAbilita(QStringList)));
    connect(modAbilitaV,SIGNAL(signalEliminaAbilita(std::string)),this,SLOT(eliminaAbilita(std::string)));

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::modificaAbilita(QStringList lista){
    modAbilitaV->close();
    delete modAbilitaV;
    emit signalModificaAbilita(lista);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::eliminaAbilita(std::string l){
    modAbilitaV->close();
    delete modAbilitaV;
    emit signalEliminaAbilita(l);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------Lingua-----------------------------------------------------------------------
void UtenteView::caricaInsLinguaView(){
    insLingParlV=new EditLinguaParlata(this);
    connect(insLingParlV,SIGNAL(signalInserisciLingua(QStringList)),this,SLOT(aggiungiLingua(QStringList)));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::aggiungiLingua(QStringList lista){
    insLingParlV->close();
    delete insLingParlV;
    emit signalInserisciLingua(lista);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::caricaModificaLinguaView(){
    modProV->close();
    delete modProV;
    modLinguaV=new ModificaLinguaView(this,utente);
    connect(modLinguaV,SIGNAL(signalModificaLingua(QStringList)),this,SLOT(modificaLingua(QStringList)));
    connect(modLinguaV,SIGNAL(signalEliminaLingua(std::string)),this,SLOT(eliminaLingua(std::string)));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::modificaLingua(QStringList lista){
    modLinguaV->close();
    delete modLinguaV;
    emit signalModificaLingua(lista);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::eliminaLingua(std::string lingua){
    modLinguaV->close();
    delete modLinguaV;
    emit signalEliminaLingua(lingua);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//-------------------------------------------------------Esperienze Professionali------------------------------------------------------------------------------
void UtenteView::caricaInsEspProfView(){
    insEspProfV=new EditEsperienzeProfessionali(this);
    connect(insEspProfV,SIGNAL(signalInserisciEspProf(QStringList)),this,SLOT(aggiungiEspProf(QStringList)));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::aggiungiEspProf(QStringList listaEsp){
    insEspProfV->close();
    delete insEspProfV;
    emit signalInserisciEspProf(listaEsp);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::caricaModificaEspProfView(){
    modProV->close();
    delete modProV;
    modEspProfV=new ModificaEsperienzeProfessionaliView(this,utente);
    connect(modEspProfV,SIGNAL(signalModificaEspProf(EsperienzeProfessionali::const_iterator,QStringList)),this,SLOT(modificaEspProf(EsperienzeProfessionali::const_iterator,QStringList)));
    connect(modEspProfV,SIGNAL(signalEliminaEspProf(EsperienzeProfessionali::const_iterator)),this,SLOT(eliminaEspProf(EsperienzeProfessionali::const_iterator)));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::modificaEspProf(EsperienzeProfessionali::const_iterator it, QStringList listaEsperienza){
    modEspProfV->close();
    delete modEspProfV;
    emit signalModificaEspProf(it,listaEsperienza);

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::eliminaEspProf(EsperienzeProfessionali::const_iterator it){
    modEspProfV->close();
    delete modEspProfV;
    emit signalEliminaEspProf(it);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------Esperienze Scolastiche-----------------------------------------------------------------------

void UtenteView::caricaInsEspScolView(){
    insEspScolV=new EditEsperienzeScolastiche(this);
    connect(insEspScolV,SIGNAL(signalInserisciEspScol(QStringList)),this,SLOT(aggiungiEspScol(QStringList)));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::aggiungiEspScol(QStringList listaEsp){
    insEspScolV->close();
    delete insEspScolV;
    emit signalInserisciEspScol(listaEsp);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::caricaModificaEspScolView(){
    modProV->close();
    delete modProV;
    modTitStudioV=new ModificaTitoloStudioView(this,utente);
    connect(modTitStudioV,SIGNAL(signalModificaEspScol(EsperienzeScolastiche::const_iterator,QStringList)),this,SLOT(modificaEspScol(EsperienzeScolastiche::const_iterator,QStringList)));
    connect(modTitStudioV,SIGNAL(signalEliminaEspScol(EsperienzeScolastiche::const_iterator)),this,SLOT(eliminaEspScol(EsperienzeScolastiche::const_iterator)));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::modificaEspScol(EsperienzeScolastiche::const_iterator it, QStringList listaEsp){
    modTitStudioV->close();
    delete modTitStudioV;
    emit signalModificaEspScol(it,listaEsp);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::eliminaEspScol(EsperienzeScolastiche::const_iterator it){
    modTitStudioV->close();
    delete modTitStudioV;
    emit signalEliminaEspScol(it);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::caricaModificaProfiloView(){
    modProV=new ModificaProfiloView(this);
    connect(modProV,SIGNAL(signalModificaDatiAnagrafici()),this,SLOT(caricaModificaDatiAnagraficiView()));
    connect(modProV,SIGNAL(signalModificaLingueParlate()),this,SLOT(caricaModificaLinguaView()));
    connect(modProV,SIGNAL(signalModificaAbilita()),this,SLOT(caricaModificaAbilitaView()));
    connect(modProV,SIGNAL(signalModificaEsperienzeScolastiche()),this,SLOT(caricaModificaEspScolView()));
    connect(modProV,SIGNAL(signalModificaEsperienzeProfessionali()),this,SLOT(caricaModificaEspProfView()));
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------Dati anagrafici-----------------------------------------------------------------------------

void UtenteView::caricaModificaDatiAnagraficiView(){
    modProV->close();
    delete modProV;
    modDatAnV=new ModificaDatiAnagraficiView(this,utente);
    connect(modDatAnV,SIGNAL(signalModificaDatiAnagrafici(QStringList)),this,SLOT(modificaDatiAnagrafici(QStringList)));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void UtenteView::modificaDatiAnagrafici(QStringList listaDati){
    modDatAnV->close();
    delete modDatAnV;
    emit signalModificaDatiAnag(listaDati);
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------Rete----------------------------------------------------------------------------

void UtenteView::caricaReteView(){
    reteV=new ReteView(this,utente);
    connect(reteV,SIGNAL(signalRimuoviContattoRete(std::string)),this,SLOT(rimuoviContattoRete(std::string)));
}

void UtenteView::rimuoviContattoRete(std::string username){
    reteV->close();
    delete reteV;
    emit signalRimuoviContattoRete(username);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------Ricerca--------------------------------------------------------------------------------

void UtenteView::caricaCercaView(){
    cercaV=new CercaView(this,utente);
    connect(cercaV,SIGNAL(signalCerca(std::string)),this,SLOT(cerca(std::string)));
    connect(cercaV,SIGNAL(signalAggiungiContatto(std::string)),this,SLOT(aggiungiContattoRete(std::string)));
}

std::map<std::string,Utente*> UtenteView::cerca(std::string stringa)const{
    return signalCerca(stringa);
}

void UtenteView::aggiungiContattoRete(std::string username){
    emit signalAggiungiContattoRete(username);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------Logout----------------------------------------------------------------------------

void UtenteView::logoutUtente(){
    emit signalLogoutUtente();
}


#include "inserisciutview.h"


InserisciUtView::InserisciUtView(Amministratore* a):model(a){
    setView();
    connect(btnCrea,SIGNAL(clicked()),this,SLOT(checkDati()));
    connect(btnAnnulla,SIGNAL(clicked()),this,SLOT(annullaCreazione()));
}

InserisciUtView::~InserisciUtView(){}

void InserisciUtView::setView(){

    this->setFixedSize(800,600);

    scrollArea=new QScrollArea(this);
    frmScrollContainer=new QFrame(scrollArea);
    lblUserName=new QLabel("Inserisci un nuovo Username:",frmScrollContainer);
    liEdUserName=new QLineEdit(frmScrollContainer);
    liEdUserName->setFixedWidth(300);

    lblPassword=new QLabel("Inserisci Password:",frmScrollContainer);
    liEdPassword=new QLineEdit(frmScrollContainer);
    liEdPassword->setFixedWidth(300);

    lblNome=new QLabel("Inserisci Nome:",frmScrollContainer);
    liEdNome=new QLineEdit(frmScrollContainer);
    liEdNome->setFixedWidth(300);

    lblCognome=new QLabel("Insersici Cognome:",frmScrollContainer);
    liEdCognome=new QLineEdit(frmScrollContainer);
    liEdCognome->setFixedWidth(300);

    lblNascita=new QLabel("Inserisci data di nascita (Giorno,Mese,Anno):");
    dateBox=new DateBox(frmScrollContainer,1900,2000);

    lblResidenza=new QLabel("Inserisci luogo di residenza attuale:",frmScrollContainer);

    //lblVia=new QLabel("Inserisci via:",frmScrollContainer);
    //liEdVia=new QLineEdit(frmScrollContainer);
    //liEdVia->setFixedWidth(300);

    lblCitta=new QLabel("Inserisci città:",frmScrollContainer);
    liEdCitta=new QLineEdit(frmScrollContainer);
    liEdCitta->setFixedWidth(300);

    lblProvincia=new QLabel("Inserisci Provincia:",frmScrollContainer);
    liEdProvincia=new QLineEdit(frmScrollContainer);
    liEdProvincia->setFixedWidth(300);

    lblNazione=new QLabel("Inserisci nazione di residenza: ",frmScrollContainer);
    liEdNazione=new QLineEdit(frmScrollContainer);
    liEdNazione->setFixedWidth(300);

    btnGrpTipoUtente=new QButtonGroup(frmScrollContainer);
    lblTipoUtente=new QLabel("Seleziona la tipologia di account:",frmScrollContainer);
    rdBtnBasic=new QRadioButton("Basic",frmScrollContainer);
    rdBtnBasic->setChecked(true);
    rdBtnBusiness=new QRadioButton("Business",frmScrollContainer);
    rdBtnExecutive=new QRadioButton("Executive",frmScrollContainer);
    btnGrpTipoUtente->addButton(rdBtnBasic);
    btnGrpTipoUtente->addButton(rdBtnBusiness);
    btnGrpTipoUtente->addButton(rdBtnExecutive);
    QVBoxLayout* chckLay=new QVBoxLayout;
    chckLay->addWidget(rdBtnBasic);
    chckLay->addWidget(rdBtnBusiness);
    chckLay->addWidget(rdBtnExecutive);

    btnGrpSesso=new QButtonGroup(frmScrollContainer);
    lblSesso=new QLabel("Selezione sesso",frmScrollContainer);
    rdBtnSessoU=new QRadioButton("Uomo",frmScrollContainer);
    rdBtnSessoU->setChecked(true);
    rdBtnSessoD=new QRadioButton("Donna",frmScrollContainer);
    btnGrpSesso->addButton(rdBtnSessoU);
    btnGrpSesso->addButton(rdBtnSessoD);
    QHBoxLayout* hSLay=new QHBoxLayout;
    QVBoxLayout* vSLay=new QVBoxLayout;
    hSLay->addWidget(rdBtnSessoU);
    hSLay->addWidget(rdBtnSessoD);
    vSLay->addWidget(lblSesso);
    vSLay->addLayout(hSLay);

    btnAnnulla=new QPushButton("Annulla");
    btnAnnulla->setFixedWidth(200);
    btnCrea=new QPushButton("Crea");
    btnCrea->setFixedWidth(200);

    QLabel* filler=new QLabel;
    filler->setFixedHeight(1);
    QLabel* filler2=new QLabel;
    filler->setFixedHeight(5);
    QLabel* filler3=new QLabel;
    QLabel* filler4=new QLabel;
    QLabel* filler5=new QLabel;
    filler->setFixedHeight(1);

    QGridLayout* gLay=new QGridLayout(frmScrollContainer);
    gLay->setColumnMinimumWidth(0,400);
    gLay->addWidget(lblUserName,0,0);
    gLay->addWidget(lblPassword,0,1);
    gLay->addWidget(liEdUserName,1,0);
    gLay->addWidget(liEdPassword,1,1);
    gLay->addWidget(filler,2,0);
    gLay->addWidget(lblNome,3,0);
    gLay->addWidget(lblCognome,3,1);
    gLay->addWidget(liEdNome,4,0);
    gLay->addWidget(liEdCognome,4,1);
    gLay->addWidget(filler2,5,0);
    gLay->addWidget(lblNascita,6,0);
    gLay->addWidget(dateBox,7,0);
    gLay->addLayout(vSLay,7,1);
    gLay->addWidget(filler3,8,0);
    gLay->addWidget(lblResidenza,9,0);
    //gLay->addWidget(lblVia,10,0);
    gLay->addWidget(lblCitta,10,0);
    //gLay->addWidget(liEdVia,10,1);
    gLay->addWidget(liEdCitta,11,0);
    gLay->addWidget(lblProvincia,10,1);
    gLay->addWidget(lblNazione,12,0);
    gLay->addWidget(liEdProvincia,11,1);
    gLay->addWidget(liEdNazione,13,0);
    gLay->addWidget(filler4,14,0);
    gLay->addWidget(lblTipoUtente,15,0);
    gLay->addLayout(chckLay,16,0);
    gLay->addWidget(filler5,17,0);
    gLay->addWidget(btnCrea,18,0);
    gLay->addWidget(btnAnnulla,18,1);
    frmScrollContainer->setLayout(gLay);
    scrollArea->setWidget(frmScrollContainer);
    QVBoxLayout* vLayDialog=new QVBoxLayout;
    vLayDialog->addWidget(scrollArea);
    setLayout(vLayDialog);
    centraFinestra(800,600);
    this->show();
}

void InserisciUtView::centraFinestra(int windowWidth, int windowHeight){
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

void InserisciUtView::checkDati(){
    std::string username=liEdUserName->text().toStdString();
    std::string password=liEdPassword->text().toStdString();
    std::string nome=liEdNome->text().toStdString();
    std::string cognome=liEdCognome->text().toStdString();
    QDate dNascita=dateBox->getDate();
    //std::string via=liEdVia->text().toStdString();
    std::string citta=liEdCitta->text().toStdString();
    std::string provincia=liEdProvincia->text().toStdString();
    std::string nazione=liEdNazione->text().toStdString();
    bool sesso=false;
    if(rdBtnSessoU->isChecked())
        sesso=true;

    if(username.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo USERNAME","Indietro");
        dialMessage->show();
    }
    else if(model->controllaPresenzaUsername(username)){
        dialMessage=new DialogMessage("Controllo dati","Username già utlizzato, inseriscine uno diverso","Indietro");
        dialMessage->show();
    }
    else if(password.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo PASSWORD","Indietro");
        dialMessage->show();
    }
    else if(nome.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo NOME","Indietro");
        dialMessage->show();
    }
    else if(cognome.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo COGNOME","Indietro");
        dialMessage->show();
    }
    else if(citta.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo CITTA","Indietro");
        dialMessage->show();
    }
    else if(provincia.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo PROVINCIA","Indietro");
        dialMessage->show();
    }
    else if(nazione.size()==0){
        dialMessage=new DialogMessage("Controllo dati","Non hai compilato il campo NAZIONE","Indietro");
        dialMessage->show();
    }
    else{
        if(rdBtnBasic->isChecked())
            emit creaUtBasic(sesso,username,password,nome,cognome,dNascita,"N.S",citta,provincia,nazione);
        else if(rdBtnBusiness->isChecked())
            emit creaUtBusiness(sesso,username,password,nome,cognome,dNascita,"N.S",citta,provincia,nazione);
        else if(rdBtnExecutive->isChecked())
             emit creaUtExecutive(sesso,username,password,nome,cognome,dNascita,"N.S",citta,provincia,nazione);
    }

}

void InserisciUtView::annullaCreazione(){
    emit utNonCreato();
}

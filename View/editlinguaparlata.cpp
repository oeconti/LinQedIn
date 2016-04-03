#include "editlinguaparlata.h"

EditLinguaParlata::EditLinguaParlata(QWidget* p):QDialog(p),vLingua(""){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    creaInserisciMode();
    creaLayout();
    this->show();
}

EditLinguaParlata::EditLinguaParlata(QWidget *, std::string vLing, std::string vLiv):vLingua(vLing),vLivello(vLiv){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    creaEditMode();
    creaLayout();
    this->show();
}

EditLinguaParlata::~EditLinguaParlata(){}

void EditLinguaParlata::creaInserisciMode(){
    this->setWindowTitle("Inserisci lingua");
    lblInsLingua=new QLabel("Lingua:",this);
    lblInsLivLingua=new QLabel("Livello:",this);
    liEdInsLingua=new QLineEdit(this);
    liEdInsLingua->setFixedWidth(225);
    boxInsLivLingua=new QComboBox(this);
    boxInsLivLingua->addItem("A1");
    boxInsLivLingua->addItem("A2");
    boxInsLivLingua->addItem("B1");
    boxInsLivLingua->addItem("B2");
    boxInsLivLingua->addItem("C1");
    boxInsLivLingua->addItem("C2");
    boxInsLivLingua->addItem("Lingua madre");
    btnAnnulaInsLingua=new QPushButton("Annulla",this);
    btnConfermaInsLingua=new QPushButton("Conferma",this);
    connect(btnAnnulaInsLingua,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnConfermaInsLingua,SIGNAL(clicked()),this,SLOT(confermaInsLingua()));
}

void EditLinguaParlata::creaEditMode(){
    this->setWindowTitle("Modifica lingua");
    lblInsLingua=new QLabel("Lingua:",this);
    lblInsLivLingua=new QLabel("Livello:",this);
    liEdInsLingua=new QLineEdit(QString::fromStdString(vLingua), this);
    liEdInsLingua->setFixedWidth(225);
    boxInsLivLingua=new QComboBox(this);
    boxInsLivLingua->addItem("A1");
    boxInsLivLingua->addItem("A2");
    boxInsLivLingua->addItem("B1");
    boxInsLivLingua->addItem("B2");
    boxInsLivLingua->addItem("C1");
    boxInsLivLingua->addItem("C2");
    boxInsLivLingua->addItem("Lingua madre");
    boxInsLivLingua->setCurrentText(QString::fromStdString(vLivello));
    btnAnnulaInsLingua=new QPushButton("Annulla",this);
    btnConfermaInsLingua=new QPushButton("Conferma",this);

    connect(btnAnnulaInsLingua,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnConfermaInsLingua,SIGNAL(clicked()),this,SLOT(confermaModLingua()));
}

void EditLinguaParlata::creaLayout(){
    QHBoxLayout* hBtnLay=new QHBoxLayout;
    hBtnLay->addWidget(btnAnnulaInsLingua);
    hBtnLay->addWidget(btnConfermaInsLingua);
    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(lblInsLingua);
    vLay->addWidget(liEdInsLingua);
    vLay->addWidget(lblInsLivLingua);
    vLay->addWidget(boxInsLivLingua);
    vLay->addLayout(hBtnLay);
    vLay->setSizeConstraint(QLayout::SetFixedSize);
    this->setLayout(vLay);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void EditLinguaParlata::caricaDati(){
    listaLingua.clear();
    nLingua=liEdInsLingua->text().toStdString();
    nLivello=boxInsLivLingua->currentText().toStdString();
    if(vLingua.size()==0){
        listaLingua<<liEdInsLingua->text();
        listaLingua<<boxInsLivLingua->currentText();
    }
    else{
        listaLingua<<QString::fromStdString(vLingua);
        listaLingua<<liEdInsLingua->text();
        listaLingua<<boxInsLivLingua->currentText();
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------

bool EditLinguaParlata::controlloDati(){
    caricaDati();
    if(nLingua.size()==0){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai inserito alcuna lingua da aggiungere","Ok");
        dialMessage->show();
        return false;
    }
    else{
        return true;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void EditLinguaParlata::confermaInsLingua(){
    if(controlloDati())
        emit signalInserisciLingua(listaLingua);
}

void EditLinguaParlata::confermaModLingua(){
    if(controlloDati())
        emit signalModificaLingua(listaLingua);
}

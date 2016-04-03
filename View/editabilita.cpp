#include "editabilita.h"

EditAbilita::EditAbilita(QWidget* p):QDialog(p),vAbilita(""){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    creaInserisciMode();
    creaLayout();
    this->show();

}

EditAbilita::EditAbilita(QWidget * p, std::string vAb, std::string vDesc):QDialog(p),vAbilita(vAb),vDescrizione(vDesc){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    creaEditMode();
    creaLayout();
    this->show();
}

EditAbilita::~EditAbilita(){}

void EditAbilita::creaInserisciMode(){
    this->setWindowTitle("Inserisci abilità");
    lblInsAbilita=new QLabel("Inserisci nuova abilità:<br/>Abilità:",this);
    liEdInsAbilita=new QLineEdit(this);
    lblInsAbilitaDescr=new QLabel("Descrizione:",this);
    txEdInsAbilDescr=new QTextEdit(this);
    txEdInsAbilDescr->setFixedWidth(400);
    txEdInsAbilDescr->setFixedHeight(150);
    btnAnnullaInsAbilita=new QPushButton("Annulla",this);
    btnConfermaInsAbilita=new QPushButton("Inserisci",this);
    connect(btnAnnullaInsAbilita,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnConfermaInsAbilita,SIGNAL(clicked()),this,SLOT(confermaInsAbilita()));
}

void EditAbilita::creaEditMode(){
    this->setWindowTitle("Modifica abilità");
    lblInsAbilita=new QLabel("Abilità:",this);
    liEdInsAbilita=new QLineEdit(this);
    liEdInsAbilita->setText(QString::fromStdString(vAbilita));
    lblInsAbilitaDescr=new QLabel("Descrizione",this);
    txEdInsAbilDescr=new QTextEdit(this);
    txEdInsAbilDescr->setText(QString::fromStdString(vDescrizione));
    txEdInsAbilDescr->setFixedSize(400,150);
    btnAnnullaInsAbilita=new QPushButton("Annulla",this);
    connect(btnAnnullaInsAbilita,SIGNAL(clicked()),this,SLOT(close()));
    btnConfermaInsAbilita=new QPushButton("Modifica",this);
    connect(btnConfermaInsAbilita,SIGNAL(clicked()),this,SLOT(confermaModifica()));
}

void EditAbilita::creaLayout(){
    QHBoxLayout* hBtnLay=new QHBoxLayout;
    hBtnLay->addWidget(btnAnnullaInsAbilita);
    hBtnLay->addWidget(btnConfermaInsAbilita);
    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(lblInsAbilita);
    vLay->addWidget(liEdInsAbilita);
    vLay->addWidget(lblInsAbilitaDescr);
    vLay->addWidget(txEdInsAbilDescr);
    vLay->addLayout(hBtnLay);
    vLay->setSizeConstraint(QLayout::SetFixedSize);
    this->setLayout(vLay);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void EditAbilita::caricaDati(){
    listaAbilita.clear();
    if(vAbilita.size()==0){
        listaAbilita<<liEdInsAbilita->text();
        listaAbilita<<txEdInsAbilDescr->toPlainText();
    }
    else{
        listaAbilita<<QString::fromStdString(vAbilita);
        listaAbilita<<liEdInsAbilita->text();
        listaAbilita<<txEdInsAbilDescr->toPlainText();
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

bool EditAbilita::controlloDati(){
    caricaDati();
    if(liEdInsAbilita->text().size()==0 || txEdInsAbilDescr->toPlainText().size()==0){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai compilato tutti i campi","Ok");
        dialMessage->show();
        return false;
    }
    else{
        return true;
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void EditAbilita::confermaInsAbilita(){
   if(controlloDati()){
       emit signalInserisciAbilita(listaAbilita);
   }
}


void EditAbilita::confermaModifica(){
    if(controlloDati())
        emit signalModificaAbilita(listaAbilita);
}

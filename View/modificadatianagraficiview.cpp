#include "modificadatianagraficiview.h"

ModificaDatiAnagraficiView::ModificaDatiAnagraficiView(QWidget* p, Utente* ut):QDialog(p),utente(ut)
{
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    this->setWindowTitle("Modifica dati anagrafici");
    lblModNome=new QLabel("Nome:",this);
    liEdModNome=new QLineEdit(QString::fromStdString(utente->getNome()),this);
    lblModCognome=new QLabel("Cognome:",this);
    liEdModCognome=new QLineEdit(QString::fromStdString(utente->getCognome()),this);
    lblModSesso=new QLabel("Sesso:",this);
    rdBtnUomo=new QRadioButton("Uomo",this);
    rdBtnDonna=new QRadioButton("Donna",this);
    if(utente->getSesso())
        rdBtnUomo->setChecked(true);
    else
        rdBtnDonna->setChecked(true);
    lblModCittaRes=new QLabel("Città di residenza:",this);
    liEdModCittaRes=new QLineEdit(QString::fromStdString(utente->getResidenza().getCitta()),this);
    lblModProvRes=new QLabel("Provincia di residenza:",this);
    liEdModProvRes=new QLineEdit(QString::fromStdString(utente->getResidenza().getProvincia()),this);
    lblModNazRes=new QLabel("Nazione di residenza:",this);
    liEdModNazRes=new QLineEdit(QString::fromStdString(utente->getResidenza().getNazione()),this);
    lblModDataNascita=new QLabel("Data di nascita:",this);
    dateBoxDataNascita=new DateBox(this,1905,2000,utente->getDataNascita());
    btnAnnullaModDatAn=new QPushButton("Annulla",this);
    btnSalvaDatiAn=new QPushButton("Salva modifiche",this);
    connect(btnAnnullaModDatAn,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnSalvaDatiAn,SIGNAL(clicked()),this,SLOT(modificaDatiAnagrafici()));

    QHBoxLayout* hBtnLay=new QHBoxLayout;
    hBtnLay->addWidget(btnAnnullaModDatAn);
    hBtnLay->addWidget(btnSalvaDatiAn);

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(lblModNome);
    vLay->addWidget(liEdModNome);
    vLay->addWidget(lblModCognome);
    vLay->addWidget(liEdModCognome);
    vLay->addWidget(lblModSesso);
    vLay->addWidget(rdBtnUomo);
    vLay->addWidget(rdBtnDonna);
    vLay->addWidget(lblModCittaRes);
    vLay->addWidget(liEdModCittaRes);
    vLay->addWidget(lblModProvRes);
    vLay->addWidget(liEdModProvRes);
    vLay->addWidget(lblModNazRes);
    vLay->addWidget(liEdModNazRes);
    vLay->addWidget(lblModDataNascita);
    vLay->addWidget(dateBoxDataNascita);
    vLay->addLayout(hBtnLay);
    vLay->setSizeConstraint(QLayout::SetFixedSize);

    this->setLayout(vLay);
    this->show();

}

ModificaDatiAnagraficiView::~ModificaDatiAnagraficiView(){}


//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaDatiAnagraficiView::modificaDatiAnagrafici(){
    listaDati.clear();
    if(rdBtnUomo->isChecked())
        listaDati<<"1";
    else
        listaDati<<"0";

    listaDati<<liEdModNome->text();
    listaDati<<liEdModCognome->text();
    listaDati<<"N.S";
    listaDati<<liEdModCittaRes->text();
    listaDati<<liEdModProvRes->text();
    listaDati<<liEdModNazRes->text();
    listaDati<<dateBoxDataNascita->getDate().toString("dd.MM.yyyy");

    if(listaDati[1].size()==0 || listaDati[2].size()==0 || listaDati[4].size()==0 || listaDati[5].size()==0 || listaDati[6].size()==0){
        DialogMessage* dial=new DialogMessage("Errore","Attenzione, non hai compilato tutti i campi","Ok");
        dial->show();
    }
    else{
        emit signalModificaDatiAnagrafici(listaDati);
    }
}

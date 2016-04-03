#include "editesperienzescolastiche.h"

EditEsperienzeScolastiche::EditEsperienzeScolastiche(QWidget* p):QDialog(p)
{
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    creaInserisciMode();
    creaLayout();
    this->show();
}

EditEsperienzeScolastiche::EditEsperienzeScolastiche(QWidget *p, EsperienzeScolastiche::const_iterator iter):QDialog(p),it(iter){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    creaEditMode();
    creaLayout();
    this->show();
}

EditEsperienzeScolastiche::~EditEsperienzeScolastiche(){}

void EditEsperienzeScolastiche::creaInserisciMode(){

    this->setWindowTitle("Titolo di studio");
    lblInsTitoloStudio=new QLabel("Titolo di studio:",this);
    liEdTitoloStudio=new QLineEdit(this);
    lblInsNomeScuola=new QLabel("Nome istituto:",this);
    liEdNomeScuola=new QLineEdit(this);
    lblInsCittaScuola=new QLabel("Città: ",this);
    liEdInsCittaScuola=new QLineEdit(this);
    lblInsProvScuola=new QLabel("Provincia: ",this);
    liEdInsProvScuola=new QLineEdit(this);
    lblInsNazScuola=new QLabel("Nazione:",this);
    liEdNazScuola=new QLineEdit(this);
    lblDataInizioEspScol=new QLabel("Data inizio:",this);
    chckEspScolCorso=new QCheckBox("In corso",this);
    dataInizoEspScol=new DateBox(this,1970,2015);
    lblDataFineEspScol=new QLabel("Data fine:",this);
    dataFineEspScol=new DateBox(this,1970,2015);
    lblInsGradoScuola=new QLabel("Grado istituto:",this);
    liEdGradoScuola=new QLineEdit(this);
    lblDescrEspScol=new QLabel("Descrizione:",this);
    txEdDescEspScol=new QTextEdit(this);
    txEdDescEspScol->setFixedWidth(600);
    txEdDescEspScol->setFixedHeight(80);
    btnAnnullaInsEspScol=new QPushButton("Annulla",this);
    btnConfermaInsEspScol=new QPushButton("Conferma",this);

    connect(chckEspScolCorso,SIGNAL(clicked()),this,SLOT(checkBoxSetFine()));
    connect(btnAnnullaInsEspScol,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnConfermaInsEspScol,SIGNAL(clicked()),this,SLOT(confermaInsEspScol()));
}

void EditEsperienzeScolastiche::creaEditMode(){

    this->setWindowTitle("Modifica titolo di studio");
    lblInsTitoloStudio=new QLabel("Titolo di studio:",this);
    liEdTitoloStudio=new QLineEdit(this);
    liEdTitoloStudio->setText(QString::fromStdString(it->getTitoloStudio()));
    lblInsNomeScuola=new QLabel("Nome istituto:",this);
    liEdNomeScuola=new QLineEdit(this);
    liEdNomeScuola->setText(QString::fromStdString(it->getNomeScuola()));
    lblInsCittaScuola=new QLabel("Città: ",this);
    liEdInsCittaScuola=new QLineEdit(this);
    liEdInsCittaScuola->setText(QString::fromStdString(it->getLuogo().getCitta()));
    lblInsProvScuola=new QLabel("Provincia: ",this);
    liEdInsProvScuola=new QLineEdit(this);
    liEdInsProvScuola->setText(QString::fromStdString(it->getLuogo().getProvincia()));
    lblInsNazScuola=new QLabel("Nazione:",this);
    liEdNazScuola=new QLineEdit(this);
    liEdNazScuola->setText(QString::fromStdString(it->getLuogo().getNazione()));
    lblDataInizioEspScol=new QLabel("Data inizio:",this);
    dataInizoEspScol=new DateBox(this,1970,2015,it->getInizio());
    lblDataFineEspScol=new QLabel("Data fine:",this);
    if(it->getFine().year()!= 2100){
        dataFineEspScol=new DateBox(this,1970,2015,it->getFine());
        chckEspScolCorso=new QCheckBox("In corso",this);
    }
    else{
        chckEspScolCorso=new QCheckBox("In corso",this);
        chckEspScolCorso->setChecked(true);
        dataFineEspScol=new DateBox(this,0,0);
        dataFineEspScol->refresh(0,0,true);
    }
    lblInsGradoScuola=new QLabel("Grado istituto:",this);
    liEdGradoScuola=new QLineEdit(this);
    liEdGradoScuola->setText(QString::fromStdString(it->getGradoScuola()));
    lblDescrEspScol=new QLabel("Descrizione:",this);
    txEdDescEspScol=new QTextEdit(this);
    txEdDescEspScol->setText(QString::fromStdString(it->getDescrizione()));
    txEdDescEspScol->setFixedWidth(600);
    txEdDescEspScol->setFixedHeight(80);
    btnAnnullaInsEspScol=new QPushButton("Annulla",this);
    btnConfermaInsEspScol=new QPushButton("Conferma",this);

    connect(chckEspScolCorso,SIGNAL(clicked()),this,SLOT(checkBoxSetFine()));
    connect(btnAnnullaInsEspScol,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnConfermaInsEspScol,SIGNAL(clicked()),this,SLOT(confermaModEspScol()));
}

void EditEsperienzeScolastiche::creaLayout(){
    QHBoxLayout* hBtnLay=new QHBoxLayout;
    hBtnLay->addWidget(btnAnnullaInsEspScol);
    hBtnLay->addWidget(btnConfermaInsEspScol);

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(lblInsTitoloStudio);
    vLay->addWidget(liEdTitoloStudio);
    vLay->addWidget(lblInsNomeScuola);
    vLay->addWidget(liEdNomeScuola);
    vLay->addWidget(lblInsCittaScuola);
    vLay->addWidget(liEdInsCittaScuola);
    vLay->addWidget(lblInsProvScuola);
    vLay->addWidget(liEdInsProvScuola);
    vLay->addWidget(lblInsNazScuola);
    vLay->addWidget(liEdNazScuola);
    vLay->addWidget(lblDataInizioEspScol);
    vLay->addWidget(dataInizoEspScol);
    vLay->addWidget(lblDataFineEspScol);
    vLay->addWidget(chckEspScolCorso);
    vLay->addWidget(dataFineEspScol);
    vLay->addWidget(lblInsGradoScuola);
    vLay->addWidget(liEdGradoScuola);
    vLay->addWidget(lblDescrEspScol);
    vLay->addWidget(txEdDescEspScol);
    vLay->addLayout(hBtnLay);
    vLay->setSizeConstraint(QLayout::SetFixedSize);

    this->setLayout(vLay);
}

void EditEsperienzeScolastiche::checkBoxSetFine(){
    if(chckEspScolCorso->isChecked()){
        dataFineEspScol->refresh(0,0,true);
    }
    else{
        dataFineEspScol->refresh(1970,2015,false);
    }
}

void EditEsperienzeScolastiche::caricaDati(){
    listaEsp.clear();
    listaEsp<<liEdNomeScuola->text();
    listaEsp<<liEdGradoScuola->text();
    listaEsp<<liEdTitoloStudio->text();

    inizio=dataInizoEspScol->getDate();
    if(chckEspScolCorso->isChecked())
        fine=QDate(2100,1,1);
    else
        fine=dataFineEspScol->getDate();

    listaEsp<<inizio.toString("dd.MM.yyyy");
    listaEsp<<fine.toString("dd.MM.yyyy");

    listaEsp<<liEdInsCittaScuola->text();
    listaEsp<<liEdInsProvScuola->text();
    listaEsp<<liEdNazScuola->text();
    listaEsp<<txEdDescEspScol->toPlainText();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

bool EditEsperienzeScolastiche::controlloDati(){
    caricaDati();
    if(liEdNomeScuola->text().size()==0 ||
        liEdTitoloStudio->text().size()==0 ||
        liEdInsCittaScuola->text().size()==0 ||
        liEdInsProvScuola->text().size()==0 ||
        liEdNazScuola->text().size()==0 ||
        liEdGradoScuola->text().size()==0 ||
        txEdDescEspScol->toPlainText().size()==0){

        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai compilato tutti i campi","Ok");
        dialMessage->show();
        return false;
    }
    else if(fine < inizio){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, la data di inizio è successiva a quella di fine","Ok");
        dialMessage->show();
        return false;
    }
    else
        return true;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------

void EditEsperienzeScolastiche::confermaInsEspScol(){
    if(controlloDati())
        emit signalInserisciEspScol(listaEsp);
}

void EditEsperienzeScolastiche::confermaModEspScol(){
    if(controlloDati())
        emit signalModificaEspScol(it,listaEsp);
}

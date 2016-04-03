#include "editesperienzeprofessionali.h"

EditEsperienzeProfessionali::EditEsperienzeProfessionali(QWidget* p):QDialog(p)
{
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    this->setWindowTitle("Aggiungi esperienza professionale");
    creaInserisciMode();
    creaLayout();
    this->show();
}

EditEsperienzeProfessionali::EditEsperienzeProfessionali(QWidget *p, EsperienzeProfessionali::const_iterator iter):QDialog(p),it(iter){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    this->setWindowTitle("Modifica esperienza professionale");
    creaEditMode();
    creaLayout();
    this->show();
}

EditEsperienzeProfessionali::~EditEsperienzeProfessionali()
{}

void EditEsperienzeProfessionali::creaInserisciMode(){
    lblInsQualifica=new QLabel("Qualifica:",this);
    liEdInsQualifica=new QLineEdit(this);
    lblInsNomeAzienda=new QLabel("Nome azienda:",this);
    liEdInsNomeAzienda=new QLineEdit(this);
    lblCittaEspProf=new QLabel("Città:",this);
    liEdCittaEspProf=new QLineEdit(this);
    lblProvEspProf=new QLabel("Provincia",this);
    liEdProvEspProf=new QLineEdit(this);
    lblNazEspProf=new QLabel("Nazione:",this);
    liEdNazEspProf=new QLineEdit(this);
    lblDataInizioEspProf=new QLabel("Data inizio:",this);
    dateBoxInizioEspProf=new DateBox(this,1970,2015);
    lblDataFineEspProf=new QLabel("Data fine:",this);
    dateBoxFineEspProf=new DateBox(this,1970,2015);
    lblDescEspProf=new QLabel("Descrizione:",this);
    txEdDescEspProf=new QTextEdit(this);
    txEdDescEspProf->setFixedWidth(600);
    txEdDescEspProf->setFixedHeight(80);
    chckEspProfCorso=new QCheckBox("Ancora in corso",this);
    connect(chckEspProfCorso,SIGNAL(clicked()),this,SLOT(checkBoxSetFine()));
    btnAnnullaInsEspProf=new QPushButton("Annulla",this);
    btnConfermaInsEspProf=new QPushButton("Conferma",this);
    connect(btnAnnullaInsEspProf,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnConfermaInsEspProf,SIGNAL(clicked()),this,SLOT(confermaInserisici()));
}

void EditEsperienzeProfessionali::creaEditMode(){
    lblInsQualifica=new QLabel("Qualifica:",this);
    liEdInsQualifica=new QLineEdit(this);
    liEdInsQualifica->setText(QString::fromStdString(it->getQualifica()));
    lblInsNomeAzienda=new QLabel("Nome azienda:",this);
    liEdInsNomeAzienda=new QLineEdit(this);
    liEdInsNomeAzienda->setText(QString::fromStdString(it->getNomeAzienda()));
    lblCittaEspProf=new QLabel("Città:",this);
    liEdCittaEspProf=new QLineEdit(this);
    liEdCittaEspProf->setText(QString::fromStdString(it->getLuogo().getCitta()));
    lblProvEspProf=new QLabel("Provincia",this);
    liEdProvEspProf=new QLineEdit(this);
    liEdProvEspProf->setText(QString::fromStdString(it->getLuogo().getProvincia()));
    lblNazEspProf=new QLabel("Nazione:",this);
    liEdNazEspProf=new QLineEdit(this);
    liEdNazEspProf->setText(QString::fromStdString(it->getLuogo().getNazione()));
    lblDataInizioEspProf=new QLabel("Data inizio:",this);
    dateBoxInizioEspProf=new DateBox(this,1970,2015,it->getInizio());
    lblDataFineEspProf=new QLabel("Data fine:",this);
    if(it->getFine().year()!= 2100){
        dateBoxFineEspProf=new DateBox(this,1970,2015,it->getFine());
        chckEspProfCorso=new QCheckBox("Ancora in corso",this);
    }
    else{
        chckEspProfCorso=new QCheckBox("In corso",this);
        chckEspProfCorso->setChecked(true);
        dateBoxFineEspProf=new DateBox(this,0,0);
        dateBoxFineEspProf->refresh(0,0,true);
    }
    lblDescEspProf=new QLabel("Descrizione:",this);
    txEdDescEspProf=new QTextEdit(this);
    txEdDescEspProf->setFixedWidth(600);
    txEdDescEspProf->setFixedHeight(80);
    txEdDescEspProf->setText(QString::fromStdString(it->getDescrizione()));
    btnAnnullaInsEspProf=new QPushButton("Annulla",this);
    btnConfermaInsEspProf=new QPushButton("Conferma",this);
    connect(btnAnnullaInsEspProf,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnConfermaInsEspProf,SIGNAL(clicked()),this,SLOT(confermaModifica()));
}

void EditEsperienzeProfessionali::creaLayout(){
    QHBoxLayout* hBtnLay=new QHBoxLayout;
    hBtnLay->addWidget(btnAnnullaInsEspProf);
    hBtnLay->addWidget(btnConfermaInsEspProf);

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(lblInsQualifica);
    vLay->addWidget(liEdInsQualifica);
    vLay->addWidget(lblInsNomeAzienda);
    vLay->addWidget(liEdInsNomeAzienda);
    vLay->addWidget(lblCittaEspProf);
    vLay->addWidget(liEdCittaEspProf);
    vLay->addWidget(lblProvEspProf);
    vLay->addWidget(liEdProvEspProf);
    vLay->addWidget(lblNazEspProf);
    vLay->addWidget(liEdNazEspProf);
    vLay->addWidget(lblDataInizioEspProf);
    vLay->addWidget(dateBoxInizioEspProf);
    vLay->addWidget(lblDataFineEspProf);
    vLay->addWidget(chckEspProfCorso);
    vLay->addWidget(dateBoxFineEspProf);
    vLay->addWidget(lblDescEspProf);
    vLay->addWidget(txEdDescEspProf);
    vLay->addLayout(hBtnLay);

    vLay->setSizeConstraint(QLayout::SetFixedSize);

    this->setLayout(vLay);
}

void EditEsperienzeProfessionali::checkBoxSetFine(){
    if(chckEspProfCorso->isChecked()){
        dateBoxFineEspProf->refresh(0,0,true);
    }
    else{
        dateBoxFineEspProf->refresh(1970,2015,false);
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

bool EditEsperienzeProfessionali::controlloDati(){
    caricaDati();
    if(liEdInsQualifica->text().size()==0 || liEdInsNomeAzienda->text().size()==0 || liEdCittaEspProf->text().size()==0 || liEdProvEspProf->text().size()==0 ||
       liEdNazEspProf->text().size()==0 || txEdDescEspProf->toPlainText().size()==0){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai compilato tutti i campi","Ok");
        dialMessage->show();
        return false;
    }
    else if(dataFine < dataInizio){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, la data di inizio dell'esperenzia professionale è successiva alla sua fine","Ok");
        dialMessage->show();
        return false;
    }
    else{
        return true;
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------


void EditEsperienzeProfessionali::caricaDati(){
    listaEsperienza.clear();
    listaEsperienza<<liEdInsNomeAzienda->text();
    listaEsperienza<<liEdInsQualifica->text();
    dataInizio=dateBoxInizioEspProf->getDate();
    if(chckEspProfCorso->isChecked())
        dataFine=QDate(2100,1,1);
    else
        dataFine=dateBoxFineEspProf->getDate();
    listaEsperienza<<dataInizio.toString("dd.MM.yyyy");
    listaEsperienza<<dataFine.toString("dd.MM.yyyy");
    listaEsperienza<<liEdCittaEspProf->text();
    listaEsperienza<<liEdProvEspProf->text();
    listaEsperienza<<liEdNazEspProf->text();
    listaEsperienza<<txEdDescEspProf->toPlainText();

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void EditEsperienzeProfessionali::confermaInserisici(){
    if(controlloDati()){
        emit signalInserisciEspProf(listaEsperienza);
    }
}

void EditEsperienzeProfessionali::confermaModifica(){
    if(controlloDati()){
        emit signalModificaEspProf(it,listaEsperienza);
    }
}

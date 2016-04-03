#include "modificaprofiloview.h"

ModificaProfiloView::ModificaProfiloView(QWidget* p):QDialog(p){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    setView();
}

ModificaProfiloView::~ModificaProfiloView(){}


void ModificaProfiloView::setView(){
    this->setModal(true);
    lblSeleziona=new QLabel("Seleziona cosa vuoi modificare:",this);
    lblSeleziona->setFixedWidth(325);
    rdBtnDatiAnagrafici=new QRadioButton("Dati anagrafici",this);
    rdBtnLingueParlate=new QRadioButton("Lingue parlate",this);
    rdBtnAbilita=new QRadioButton("Abilità",this);
    rdBtnEspProf=new QRadioButton("Esperienze professionali",this);
    rdBtnEspScol=new QRadioButton("Titoli di studio",this);
    rdBtnDatiAnagrafici->setChecked(true);
    btnAnnulla=new QPushButton("Indietro",this);
    btnConferma=new QPushButton("Conferma",this);
    connect(btnAnnulla,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnConferma,SIGNAL(clicked()),this,SLOT(selezionaModifica()));

    QHBoxLayout* hBtnLay=new QHBoxLayout;
    hBtnLay->addWidget(btnAnnulla);
    hBtnLay->addWidget(btnConferma);

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(lblSeleziona);
    vLay->addWidget(rdBtnDatiAnagrafici);
    vLay->addWidget(rdBtnLingueParlate);
    vLay->addWidget(rdBtnAbilita);
    vLay->addWidget(rdBtnEspScol);
    vLay->addWidget(rdBtnEspProf);
    vLay->addLayout(hBtnLay);
    vLay->setSizeConstraint(QLayout::SetFixedSize);

    this->setLayout(vLay);
    this->show();
}

void ModificaProfiloView::selezionaModifica(){
    if(rdBtnDatiAnagrafici->isChecked()){
        signalModificaDatiAnagrafici();
    }
    else if(rdBtnLingueParlate->isChecked()){
        signalModificaLingueParlate();
    }
    else if(rdBtnAbilita->isChecked()){
        signalModificaAbilita();
    }
    else if(rdBtnEspScol->isChecked()){
        signalModificaEsperienzeScolastiche();
    }
    else{
        signalModificaEsperienzeProfessionali();
    }
}




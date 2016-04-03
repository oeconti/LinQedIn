#include "cercaview.h"

CercaView::CercaView(QWidget* p,Utente* ut):QDialog(p),utente(ut){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    this->setWindowTitle("Cerca utenti in LinQedIn");
    this->setFixedSize(1050,600);

    creaTabella();
    creaCercaBox();
    creaTipoCercaBox();
    creaVisualizzaBox();
    creaIndietroBox();

    QHBoxLayout* hLay=new QHBoxLayout;
    hLay->addWidget(frmTable);

    QVBoxLayout* vLay=new QVBoxLayout;

    vLay->addWidget(grBxCercaUtente ,Qt::AlignTop);
    vLay->addWidget(grBxVisualizzaProfilo,Qt::AlignTop);
    vLay->addWidget(grBxTipoRicerca,Qt::AlignTop);
    vLay->addWidget(grBxIndietro,Qt::AlignBottom);
    vLay->addStretch();

    hLay->addLayout(vLay);

    this->setLayout(hLay);

    this->show();
}

CercaView::~CercaView(){}

void CercaView::creaTabella(){
    frmTable=new QFrame(this);
    frmTable->setFixedSize(690,775);
    tbWrisRicerca=new QTableWidget(frmTable);
    tbWrisRicerca->insertColumn(0);
    tbWrisRicerca->insertColumn(1);
    tbWrisRicerca->insertColumn(2);
    tbWrisRicerca->setSelectionBehavior(QAbstractItemView::SelectRows);
    tbWrisRicerca->setSelectionMode(QAbstractItemView::SingleSelection);
    QStringList campiTabella;
    campiTabella<<"Username"<<"Nome"<<"Cognome";
    tbWrisRicerca->setHorizontalHeaderLabels(campiTabella);
    tbWrisRicerca->horizontalHeader()->setSectionsClickable(false);
    tbWrisRicerca->horizontalHeader()->setDefaultSectionSize(210);

    tbWrisRicerca->setCurrentCell(-1,-1);

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(tbWrisRicerca);
    frmTable->setLayout(vLay);

}

void CercaView::creaCercaBox(){
    grBxCercaUtente=new QGroupBox("Cerca utenti",this);
    grBxCercaUtente->setFixedHeight(150);
    lblCerca=new QLabel("Inserisci una o più parole chiave da cercare:",grBxCercaUtente);
    liEdCerca=new QLineEdit(grBxCercaUtente);
    btnCerca=new QPushButton("Cerca",grBxCercaUtente);
    connect(btnCerca,SIGNAL(clicked()),this,SLOT(cerca()));

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(lblCerca);
    vLay->addWidget(liEdCerca);
    vLay->addWidget(btnCerca);
    vLay->setSizeConstraint(QLayout::SetFixedSize);

    grBxCercaUtente->setLayout(vLay);
}

void CercaView::creaTipoCercaBox(){
    grBxTipoRicerca=new QGroupBox("Potenza di ricerca",this);
    lblDescrizioneRicerca=new QLabel(grBxTipoRicerca);
    QString descrizione;
    std::vector<std::string> vectDescrizione=utente->getDescrizioneRicerca();
    descrizione="Il tuo tipo di ricerca è <b>" + QString::fromStdString(vectDescrizione[0]) + "</b><br/>Potrai cercare all'interno dei seguenti campi:";
    descrizione+="<ul>";
    for(unsigned int i=1;i<vectDescrizione.size();i++){
        descrizione+="<li>" + QString::fromStdString(vectDescrizione[i]) + "</li>";
    }
    descrizione+="</ul>";
    lblDescrizioneRicerca->setText(descrizione);

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(lblDescrizioneRicerca);
    vLay->setSizeConstraint(QLayout::SetFixedSize);
    grBxTipoRicerca->setLayout(vLay);
}

void CercaView::creaVisualizzaBox(){
    grBxVisualizzaProfilo=new QGroupBox("Visualizza e/o aggiungi",this);
    grBxVisualizzaProfilo->setFixedHeight(100);
    btnVisualizzaProfilo=new QPushButton("Visualizza profilo",grBxVisualizzaProfilo);
    btnAggiungiContatto=new QPushButton("Aggiungi ai contatti",grBxVisualizzaProfilo);

    connect(btnVisualizzaProfilo,SIGNAL(clicked()),this,SLOT(visualizzaProfilo()));
    connect(btnAggiungiContatto,SIGNAL(clicked()),this,SLOT(aggiungiContatto()));

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(btnVisualizzaProfilo);
    vLay->addWidget(btnAggiungiContatto);

    grBxVisualizzaProfilo->setLayout(vLay);
}

void CercaView::creaIndietroBox(){
    grBxIndietro=new QGroupBox(this);
    grBxIndietro->setFixedHeight(75);
    btnIndietro=new QPushButton("Indietro",grBxIndietro);
    connect(btnIndietro,SIGNAL(clicked()),this,SLOT(close()));

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(btnIndietro);

    grBxIndietro->setLayout(vLay);
}

//-------------------------------------------------------------------------------------------------------------
void CercaView::cerca(){
    while(tbWrisRicerca->rowCount()>0)
        tbWrisRicerca->removeRow(0);
    int row = tbWrisRicerca->rowCount();

    risRicerca.clear();
    risRicerca=signalCerca(liEdCerca->text().toStdString());
    if(risRicerca.size()==0){
        DialogMessage* dial=new DialogMessage("Ricerca","La tua ricerca non ha prodotto alcun risultato. Prova a cercare cambiando le parole chiave","Indietro");
        dial->show();
    }
    else{
        std::map<std::string,Utente*>::const_iterator it=risRicerca.begin();

        for(;it!=risRicerca.end();it++){
            tbWrisRicerca->insertRow(row);
            tbItUsername=new QTableWidgetItem;
            tbItNome=new QTableWidgetItem;
            tbItCognome=new QTableWidgetItem;
            tbItUsername->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            tbItNome->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            tbItCognome->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

            tbItUsername->setText(QString::fromStdString(it->second->getUsername()));
            tbItNome->setText(QString::fromStdString(it->second->getNome()));
            tbItCognome->setText(QString::fromStdString(it->second->getCognome()));
            tbWrisRicerca->setItem(row,0,tbItUsername);
            tbWrisRicerca->setItem(row,1,tbItNome);
            tbWrisRicerca->setItem(row,2,tbItCognome);
            row++;
        }
        tbWrisRicerca->setCurrentCell(-1,-1);
    }

}

void CercaView::visualizzaProfilo(){
    if(getSelectedUsername().size()==0){
        DialogMessage* dial=new DialogMessage("Visualizza profilo","Attenzione, non hai selezionato alcun utente da visualizzare","Indietro");
        dial->show();
    }
    else{
        std::map<std::string,Utente*>::const_iterator it=risRicerca.find(getSelectedUsername());
        dialContatto=new QDialog(this);
        dialContatto->setModal(true);
        dialContatto->setFixedSize(1024,600);
        dialContatto->setAttribute(Qt::WA_DeleteOnClose,true);
        profiloV=new ProfiloView(dialContatto,it->second);

        QPushButton* btnAggiungi=new QPushButton("Aggiungi ai contatti",dialContatto);
        QPushButton* btnIndietro=new QPushButton("Indietro",dialContatto);
        connect(btnAggiungi,SIGNAL(clicked()),this,SLOT(aggiungiContatto()));
        connect(btnIndietro,SIGNAL(clicked()),dialContatto,SLOT(close()));


        QHBoxLayout* hLay=new QHBoxLayout;
        hLay->addWidget(btnIndietro);
        hLay->addWidget(btnAggiungi);

        QGridLayout* gLay=new QGridLayout;
        gLay->addWidget(profiloV,0,0);
        gLay->addLayout(hLay,1,0);
        dialContatto->setLayout(gLay);
        dialContatto->show();
    }
}

std::string CercaView::getSelectedUsername(){
    int row=tbWrisRicerca->currentRow();
    if(row==-1)
        return ("");
    else{
        QTableWidgetItem* aux=tbWrisRicerca->item(row,0);
        QString auxString=aux->text();
        return auxString.toStdString();
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------

void CercaView::aggiungiContatto(){
    if(utente->controllaPresenzaContattoRete(getSelectedUsername())){
        DialogMessage* dial=new DialogMessage("Aggiungi contatto","L'utente che hai selezionato fa già parte della tua rete","Indietro");
        dial->show();
    }
    else{
        emit signalAggiungiContatto(getSelectedUsername());
    }
}

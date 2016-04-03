#include "modificatitolostudioview.h"

ModificaTitoloStudioView::ModificaTitoloStudioView(QWidget* p,Utente* ut):QDialog(p),utente(ut){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    this->setWindowTitle("Modifica titlo di studio");
    this->setFixedSize(820,400);

    tableWidgetTitoloStudio=new QTableWidget(this);
    tableWidgetTitoloStudio->insertColumn(0);
    tableWidgetTitoloStudio->insertColumn(1);
    tableWidgetTitoloStudio->insertColumn(2);
    tableWidgetTitoloStudio->insertColumn(3);
    tableWidgetTitoloStudio->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidgetTitoloStudio->setSelectionMode(QAbstractItemView::SingleSelection);
    QStringList campiTabella;
    campiTabella<<"Data fine"<<"Data inizio"<<"Titolo di studio"<<"Nome istituto";
    tableWidgetTitoloStudio->setHorizontalHeaderLabels(campiTabella);
    tableWidgetTitoloStudio->horizontalHeader()->setSectionsClickable(false);//disabilita il click negli header;
    tableWidgetTitoloStudio->setColumnWidth(0,90);
    tableWidgetTitoloStudio->setColumnWidth(1,90);
    tableWidgetTitoloStudio->setColumnWidth(2,200);
    tableWidgetTitoloStudio->setColumnWidth(3,300);

    int row=tableWidgetTitoloStudio->rowCount();
    EsperienzeScolastiche::const_iterator it=utente->getEsperienzeScolasticheBegin();
    for(;it!=utente->getEsperienzeScolasticheEnd();it++){
        tableWidgetTitoloStudio->insertRow(row);
        tableItemInizio=new QTableWidgetItem;
        tableItemFine=new QTableWidgetItem;
        tableItemNomeScuola=new QTableWidgetItem;
        tableItemTitolo=new QTableWidgetItem;
        tableItemInizio->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemFine->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemNomeScuola->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemTitolo->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemInizio->setText(it->getInizio().toString("MM/yyyy"));
        if(it->getFine().year() == 2100)
            tableItemFine->setText("In corso");
        else
            tableItemFine->setText(it->getFine().toString("MM/yyyy"));
        tableItemNomeScuola->setText(QString::fromStdString(it->getNomeScuola()));
        tableItemTitolo->setText(QString::fromStdString(it->getTitoloStudio()));

        tableWidgetTitoloStudio->setItem(row,0,tableItemFine);
        tableWidgetTitoloStudio->setItem(row,1,tableItemInizio);
        tableWidgetTitoloStudio->setItem(row,2,tableItemTitolo);
        tableWidgetTitoloStudio->setItem(row,3,tableItemNomeScuola);
        row++;
    }

    tableWidgetTitoloStudio->setCurrentCell(-1,-1);

    QGridLayout* gLay=new QGridLayout;
    gLay->addWidget(tableWidgetTitoloStudio,0,0);


    btnModifica=new QPushButton("Modifica",this);
    connect(btnModifica,SIGNAL(clicked()),this,SLOT(ModificaView()));
    btnElimina=new QPushButton("Elimina",this);
    connect(btnElimina,SIGNAL(clicked()),this,SLOT(confermaElimina()));
    btnAnnulla=new QPushButton("Annulla",this);
    connect(btnAnnulla,SIGNAL(clicked()),this,SLOT(close()));

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(btnModifica);
    vLay->addWidget(btnElimina);
    vLay->addWidget(btnAnnulla);

    gLay->addLayout(vLay,0,1);

    this->setLayout(gLay);
    this->show();


}

ModificaTitoloStudioView::~ModificaTitoloStudioView(){}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

EsperienzeScolastiche::const_iterator ModificaTitoloStudioView::getEsperienza(){
    int index=tableWidgetTitoloStudio->currentRow();
    EsperienzeScolastiche::const_iterator it=utente->getEsperienzeScolasticheBegin();
    for(int i=0;i<index;i++){
        it++;
    }

    return it;
}

//-------------------------------------------------Modifica titolo di stuio-------------------------------------------------------------------------------

void ModificaTitoloStudioView::ModificaView(){
    if(tableWidgetTitoloStudio->currentRow() == -1){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai selezionata alcuna esperienza","Indietro");
        dialMessage->show();
    }
    else{
        editEspScolV=new EditEsperienzeScolastiche(this,getEsperienza());
        connect(editEspScolV,SIGNAL(signalModificaEspScol(EsperienzeScolastiche::const_iterator,QStringList)),this,SLOT(confermaModifica(EsperienzeScolastiche::const_iterator,QStringList)));
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaTitoloStudioView::confermaModifica(EsperienzeScolastiche::const_iterator it,QStringList listaEsp){
        emit signalModificaEspScol(it,listaEsp);
}


//----------------------------------------------------Elimina titolo di studio---------------------------------------------------------------------------

void ModificaTitoloStudioView::confermaElimina(){
    if(tableWidgetTitoloStudio->currentRow() == -1){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai selezionato alcun titolo di studio da eliminare","Indietro");
        dialMessage->show();
    }
    else{
        dialElimina=new QDialog(this);
        dialElimina->setWindowTitle("Elimina titolo di studio");
        dialElimina->setModal(true);
        lblConfermaElimina=new QLabel("Premi conferma se sei sicuro di voler eliminare il titolo di studio selezionato",dialElimina);
        btnAnnullaElimina=new QPushButton("Annulla",dialElimina);
        btnConfermaElimina=new QPushButton("Conferma",dialElimina);
        connect(btnAnnullaElimina,SIGNAL(clicked()),dialElimina,SLOT(close()));
        connect(btnConfermaElimina,SIGNAL(clicked()),this,SLOT(eliminaEspScol()));

        QVBoxLayout* vLay=new QVBoxLayout;
        vLay->addWidget(lblConfermaElimina);

        QHBoxLayout* hLay=new QHBoxLayout;
        hLay->addWidget(btnAnnullaElimina);
        hLay->addWidget(btnConfermaElimina);

        vLay->addLayout(hLay);
        vLay->setSizeConstraint(QLayout::SetFixedSize);
        dialElimina->setLayout(vLay);
        dialElimina->show();
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaTitoloStudioView::eliminaEspScol(){
    dialElimina->close();
    delete dialElimina;

    emit signalEliminaEspScol(getEsperienza());
}

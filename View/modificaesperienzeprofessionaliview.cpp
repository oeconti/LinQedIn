#include "modificaesperienzeprofessionaliview.h"

ModificaEsperienzeProfessionaliView::ModificaEsperienzeProfessionaliView(QWidget* p,Utente* ut):QDialog(p),utente(ut){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    this->setWindowTitle("Modifica esperienza professionale");
    this->setFixedSize(820,400);

    tableWidgetEspProf=new QTableWidget(this);
    tableWidgetEspProf->insertColumn(0);
    tableWidgetEspProf->insertColumn(1);
    tableWidgetEspProf->insertColumn(2);
    tableWidgetEspProf->insertColumn(3);
    tableWidgetEspProf->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidgetEspProf->setSelectionMode(QAbstractItemView::SingleSelection);
    QStringList campiTabella;
    campiTabella<<"Data fine"<<"Data inizio"<<"Qualifica"<<"Azienda";
    tableWidgetEspProf->setHorizontalHeaderLabels(campiTabella);
    tableWidgetEspProf->horizontalHeader()->setSectionsClickable(false);//disabilita il click negli header;
    tableWidgetEspProf->setColumnWidth(0,90);
    tableWidgetEspProf->setColumnWidth(1,90);
    tableWidgetEspProf->setColumnWidth(2,200);
    tableWidgetEspProf->setColumnWidth(3,300);

    int row=tableWidgetEspProf->rowCount();
    EsperienzeProfessionali::const_iterator it=utente->getEsperienzeProfessionaliBegin();
    for(;it!=utente->getEsperienzeProfessionaliEnd();it++){
        tableWidgetEspProf->insertRow(row);
        tableItemInizio=new QTableWidgetItem;
        tableItemFine=new QTableWidgetItem;
        tableItemNomeAzienda=new QTableWidgetItem;
        tableItemQualifica=new QTableWidgetItem;
        tableItemInizio->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemFine->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemNomeAzienda->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemQualifica->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemInizio->setText(it->getInizio().toString("MM/yyyy"));
        if(it->getFine().year() == 2100)
            tableItemFine->setText("In corso");
        else
            tableItemFine->setText(it->getFine().toString("MM/yyyy"));
        tableItemNomeAzienda->setText(QString::fromStdString(it->getNomeAzienda()));
        tableItemQualifica->setText(QString::fromStdString(it->getQualifica()));

        tableWidgetEspProf->setItem(row,0,tableItemFine);
        tableWidgetEspProf->setItem(row,1,tableItemInizio);
        tableWidgetEspProf->setItem(row,2,tableItemQualifica);
        tableWidgetEspProf->setItem(row,3,tableItemNomeAzienda);
        row++;
    }

    tableWidgetEspProf->setCurrentCell(-1,-1);

    QGridLayout* gLay=new QGridLayout;
    gLay->addWidget(tableWidgetEspProf,0,0);


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

ModificaEsperienzeProfessionaliView::~ModificaEsperienzeProfessionaliView(){}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaEsperienzeProfessionaliView::ModificaView(){
    if(tableWidgetEspProf->currentRow() == -1){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai selezionata alcuna esperienza","Indietro");
        dialMessage->show();
    }
    else
    {
        editEspProfV=new EditEsperienzeProfessionali(this,getEsperienza());
        connect(editEspProfV,SIGNAL(signalModificaEspProf(EsperienzeProfessionali::const_iterator,QStringList)),
                this,SLOT(confermaModifica(EsperienzeProfessionali::const_iterator,QStringList)));
    }
}

EsperienzeProfessionali::const_iterator ModificaEsperienzeProfessionaliView::getEsperienza(){
    int index=tableWidgetEspProf->currentRow();
    EsperienzeProfessionali::const_iterator it=utente->getEsperienzeProfessionaliBegin();
    for(int i=0;i<index;i++){
        it++;
    }

    return it;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaEsperienzeProfessionaliView::confermaModifica(EsperienzeProfessionali::const_iterator it,QStringList listaEsp){
        emit signalModificaEspProf(it,listaEsp);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaEsperienzeProfessionaliView::confermaElimina(){
    if(tableWidgetEspProf->currentRow() == -1){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai selezionato alcuna esperienza da eliminare","Indietro");
        dialMessage->show();
    }
    else{
        dialElimina=new QDialog(this);
        dialElimina->setWindowTitle("Elimina esperinza professionale");
        dialElimina->setModal(true);
        lblConfermaElimina=new QLabel("Premi conferma se sei sicuro di voler eliminare l'esperienza selezionata",dialElimina);
        btnAnnullaElimina=new QPushButton("Annulla",dialElimina);
        btnConfermaElimina=new QPushButton("Conferma",dialElimina);
        connect(btnAnnullaElimina,SIGNAL(clicked()),dialElimina,SLOT(close()));
        connect(btnConfermaElimina,SIGNAL(clicked()),this,SLOT(eliminaEsp()));

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

void ModificaEsperienzeProfessionaliView::eliminaEsp(){
    dialElimina->close();
    delete dialElimina;
    emit signalEliminaEspProf(getEsperienza());
}

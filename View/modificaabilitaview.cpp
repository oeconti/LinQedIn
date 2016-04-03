#include "modificaabilitaview.h"

ModificaAbitliaView::ModificaAbitliaView(QWidget* p,Utente* ut):QDialog(p),utente(ut){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    this->setWindowTitle("Modifica abilità");
    this->setFixedSize(530,300);
    tableWidgetAbilita=new QTableWidget(this);
    tableWidgetAbilita->insertColumn(0);
    tableWidgetAbilita->insertColumn(1);
    tableWidgetAbilita->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidgetAbilita->setSelectionMode(QAbstractItemView::SingleSelection);
    QStringList header;
    header << "Abilità" << "Descrizione";
    tableWidgetAbilita->setHorizontalHeaderLabels(header);
    tableWidgetAbilita->horizontalHeader()->setSectionsClickable(false);
    tableWidgetAbilita->horizontalHeader()->setDefaultSectionSize(190);

    int row=tableWidgetAbilita->rowCount();
    AbilitaPossedute::const_iterator it=utente->getAbilitaPosseduteBegin();
    for(;it!=utente->getAbilitaPosseduteEnd();it++){
        tableWidgetAbilita->insertRow(row);
        tableItemNome=new QTableWidgetItem;
        tableItemDescrizione=new QTableWidgetItem;
        tableItemNome->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemDescrizione->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemNome->setText(QString::fromStdString(it->second.getNomeAbilita()));
        tableItemDescrizione->setText(QString::fromStdString(it->second.getDescrizioneAbilita()));
        tableWidgetAbilita->setItem(row,0,tableItemNome);
        tableWidgetAbilita->setItem(row,1,tableItemDescrizione);
        row++;
    }
    tableWidgetAbilita->setCurrentCell(-1,-1);

    QGridLayout* gridLay=new QGridLayout;
    gridLay->addWidget(tableWidgetAbilita,0,0);

    btnModifica=new QPushButton("Modifica",this);
    connect(btnModifica,SIGNAL(clicked()),this,SLOT(modificaView()));
    btnElimina=new QPushButton("Elimina",this);
    connect(btnElimina,SIGNAL(clicked()),this,SLOT(eliminaAbilita()));
    btnAnnulla=new QPushButton("Annulla",this);
    connect(btnAnnulla,SIGNAL(clicked()),this,SLOT(close()));
    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(btnModifica);
    vLay->addWidget(btnElimina);
    vLay->addWidget(btnAnnulla);

    gridLay->addLayout(vLay,0,1);

    this->setLayout(gridLay);
    this->show();
}

ModificaAbitliaView::~ModificaAbitliaView(){}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaAbitliaView::modificaView(){
    if(getSelectedAbilita().size()!=0){
        editAbV=new EditAbilita(this,getSelectedAbilita(),getSelectedDescrizione());
        connect(editAbV,SIGNAL(signalModificaAbilita(QStringList)),this,SLOT(confermaModifica(QStringList)));
    }
    else{
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai selezionato alcuna abilità","Indietro");
        dialMessage->show();
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

std::string ModificaAbitliaView::getSelectedAbilita(){
    int row=tableWidgetAbilita->currentRow();
    if(row==-1)
        return ("");
    else{
        QTableWidgetItem* aux=tableWidgetAbilita->item(row,0);
        QString auxString=aux->text();
        return auxString.toStdString();
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

std::string ModificaAbitliaView::getSelectedDescrizione(){
    int row=tableWidgetAbilita->currentRow();
    if(row==-1)
        return ("");
    else{
        QTableWidgetItem* aux=tableWidgetAbilita->item(row,1);
        QString auxString=aux->text();
        return auxString.toStdString();
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaAbitliaView::confermaModifica(QStringList lista){
    emit signlaModificaAbilita(lista);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaAbitliaView::eliminaAbilita(){
    if(getSelectedAbilita().size()==0){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai selezionato alcuna abilità","Indietro");
        dialMessage->show();
    }
    else
    {
        dialElimina=new QDialog(this);
        dialElimina->setWindowTitle("Elimina abilità");
        dialElimina->setModal(true);
        lblConfermaElimina=new QLabel("Premi conferma se sei sicuro di voler eliminare l'abilità selezionata",dialElimina);
        btnAnnullaElimina=new QPushButton("Annulla",dialElimina);
        btnConfermaElimina=new QPushButton("Conferma",dialElimina);
        connect(btnAnnullaElimina,SIGNAL(clicked()),dialElimina,SLOT(close()));
        connect(btnConfermaElimina,SIGNAL(clicked()),this,SLOT(confermaElimina()));

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

void ModificaAbitliaView::confermaElimina(){
    dialElimina->close();
    delete dialElimina;
    emit signalEliminaAbilita(getSelectedAbilita());
}

#include "modificalinguaview.h"

ModificaLinguaView::ModificaLinguaView(QWidget* p,Utente* ut):QDialog(p),utente(ut)
{
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setFixedSize(530,300);
    this->setModal(true);
    this->setWindowTitle("Modifica lingue parlate");
    tableWidgetLingue=new QTableWidget(this);
    tableWidgetLingue->insertColumn(0);
    tableWidgetLingue->insertColumn(1);
    tableWidgetLingue->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableWidgetLingue->setSelectionMode(QAbstractItemView::SingleSelection);
    QStringList campiTabella;
    campiTabella<<"Lingua"<<"Livello";
    tableWidgetLingue->setHorizontalHeaderLabels(campiTabella);
    tableWidgetLingue->horizontalHeader()->setSectionsClickable(false);//disabilita il click negli header;
    tableWidgetLingue->horizontalHeader()->setDefaultSectionSize(175);//imposta dimensioni label

    int row= tableWidgetLingue->rowCount();
    LingueParlate::const_iterator it=utente->getLingueParlateBegin();
    for(;it!=utente->getLingueParlateEnd();it++){
        tableWidgetLingue->insertRow(row);
        tableItemlingua=new QTableWidgetItem;
        tableItemLivLingua=new QTableWidgetItem;
        tableItemlingua->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemLivLingua->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tableItemlingua->setText(QString::fromStdString(it->second.getNomeLingua()));
        tableItemLivLingua->setText(QString::fromStdString(it->second.getLivelloCompetenzaLinguistica()));
        tableWidgetLingue->setItem(row,0,tableItemlingua);
        tableWidgetLingue->setItem(row,1,tableItemLivLingua);
        row++;
    }
    tableWidgetLingue->setCurrentCell(-1,-1);

    QGridLayout* gridLay=new QGridLayout;
    gridLay->addWidget(tableWidgetLingue,0,0);

    QVBoxLayout* vLay=new QVBoxLayout;
    btnModificaLingua=new QPushButton("Modifica lingua",this);
    btnEliminaLingua=new QPushButton("Elimina lingua",this);
    btnAnnulaModificheLingua=new QPushButton("Annulla",this);

    connect(btnAnnulaModificheLingua,SIGNAL(clicked()),this,SLOT(close()));
    connect(btnModificaLingua,SIGNAL(clicked()),this,SLOT(modificaLingua()));
    connect(btnEliminaLingua,SIGNAL(clicked()),this,SLOT(eliminaLingua()));

    vLay->addWidget(btnModificaLingua);
    vLay->addWidget(btnEliminaLingua);
    vLay->addWidget(btnAnnulaModificheLingua);
    vLay->setSizeConstraint(QLayout::SetFixedSize);

    gridLay->addLayout(vLay,0,1);

    this->setLayout(gridLay);
    this->show();
}

ModificaLinguaView::~ModificaLinguaView(){}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

std::string ModificaLinguaView::getSelectedLingua(){
    int row=tableWidgetLingue->currentRow();
    if(row==-1)
        return ("");
    else{
        QTableWidgetItem* aux=tableWidgetLingue->item(row,0);
        QString auxString=aux->text();
        return auxString.toStdString();
    }
}

std::string ModificaLinguaView::getSelectedLivello(){
    int row=tableWidgetLingue->currentRow();
    if(row==-1)
        return ("");
    else{
        QTableWidgetItem* aux=tableWidgetLingue->item(row,1);
        QString auxString=aux->text();
        return auxString.toStdString();
    }
}


//------------------------------------------------------------------Modifica Lingua-------------------------------------------------------------------------

void ModificaLinguaView::modificaLingua(){
    if(getSelectedLingua().size()==0){
        DialogMessage* dial=new DialogMessage("Errore","Attenzione,non hai selezionato alcuna lingua","Indietro");
        dial->show();
    }
    else{
        modLinguaV=new EditLinguaParlata(this,getSelectedLingua(),getSelectedLivello());
        connect(modLinguaV,SIGNAL(signalModificaLingua(QStringList)),this,SLOT(confermaModifica(QStringList)));
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ModificaLinguaView::confermaModifica(QStringList lista){
    modLinguaV->close();
    delete modLinguaV;
    emit signalModificaLingua(lista);
}

//----------------------------------------------------------------Elimina Lingua------------------------------------------------------------------------------

void ModificaLinguaView::eliminaLingua(){
    if(getSelectedLingua().size()==0){
        DialogMessage* dial=new DialogMessage("Errore","Attenzione,non hai selezionato alcuna lingua","Indietro");
        dial->show();
    }
    else{
        dialElimina=new QDialog(this);
        dialElimina->setWindowTitle("Elimina lingua");
        dialElimina->setModal(true);
        lblConfermaElimina=new QLabel("Premi conferma se sei sicuro di voler eliminare la lingua selezionata",dialElimina);
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

void ModificaLinguaView::confermaElimina(){
    dialElimina->close();
    delete dialElimina;

    emit signalEliminaLingua(getSelectedLingua());
}

#include "reteview.h"

ReteView::ReteView(QWidget* p,Utente* ut):QDialog(p),utente(ut){
    this->setAttribute(Qt::WA_DeleteOnClose,true);
    this->setModal(true);
    this->setWindowTitle("Rete contatti personali");
    this->setFixedSize(800,600);

    creaTabella();
    creaFiltraBox();
    creaAzioniBox();
    creaIndietroBox();

    QHBoxLayout* hLay=new QHBoxLayout;
    hLay->addWidget(frmTable);

    QVBoxLayout* vLay=new QVBoxLayout;

    vLay->addWidget(grBoxFiltra,Qt::AlignTop);
    vLay->addWidget(grBoxAzioni,Qt::AlignTop);
    vLay->addWidget(grBoxIndietro,Qt::AlignTop);
    vLay->addStretch();

    hLay->addLayout(vLay);

    this->setLayout(hLay);

    this->show();
}

ReteView::~ReteView(){}

void ReteView::creaTabella(){

    frmTable=new QFrame(this);
    frmTable->setFixedSize(500,600);
    tbWcontatti=new QTableWidget(frmTable);
    tbWcontatti->setSelectionBehavior(QAbstractItemView::SelectRows);
    tbWcontatti->setSelectionMode(QAbstractItemView::SingleSelection);
    tbWcontatti->insertColumn(0);
    tbWcontatti->insertColumn(1);
    tbWcontatti->insertColumn(2);
    QStringList campiTabella;
    campiTabella<<"Username"<<"Nome"<<"Cognome";
    tbWcontatti->setHorizontalHeaderLabels(campiTabella);
    tbWcontatti->horizontalHeader()->setSectionsClickable(false);
    tbWcontatti->setColumnWidth(0,180);
    tbWcontatti->setColumnWidth(1,130);
    tbWcontatti->setColumnWidth(2,130);

    int row=tbWcontatti->rowCount();
    Rete::const_iterator it=utente->getReteBegin();
    for(;it!=utente->getReteEnd();it++){
        tbWcontatti->insertRow(row);
        tbItUsername=new QTableWidgetItem;
        tbItNome=new QTableWidgetItem;
        tbItCognome=new QTableWidgetItem;
        tbItUsername->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tbItNome->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tbItCognome->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

        const SmartUtente* smUt=utente->getContattoReteSmart(it);
        tbItUsername->setText(QString::fromStdString((*smUt)->getUsername()));
        tbItNome->setText(QString::fromStdString((*smUt)->getNome()));
        tbItCognome->setText(QString::fromStdString((*smUt)->getCognome()));
        tbWcontatti->setItem(row,0,tbItUsername);
        tbWcontatti->setItem(row,1,tbItNome);
        tbWcontatti->setItem(row,2,tbItCognome);
        row++;
    }

    tbWcontatti->setCurrentCell(-1,-1);

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(tbWcontatti);
    frmTable->setLayout(vLay);
}

void ReteView::creaFiltraBox(){
    grBoxFiltra=new QGroupBox("Filtra contatti",this);
    grBoxFiltra->setFixedHeight(150);
    liEdFiltra=new QLineEdit(grBoxFiltra);
    btnReset=new QPushButton("Reset",grBoxFiltra);

    connect(liEdFiltra,SIGNAL(textChanged(QString)),this,SLOT(filtraContatti(QString)));
    connect(btnReset,SIGNAL(clicked()),liEdFiltra,SLOT(clear()));

    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(liEdFiltra);
    vLay->addWidget(btnReset);

    grBoxFiltra->setLayout(vLay);
}

void ReteView::creaAzioniBox(){
    grBoxAzioni=new QGroupBox("Visualizza o elimina contatti",this);
    grBoxAzioni->setFixedHeight(150);
    btnVisualizza=new QPushButton("Visualizza contatto",grBoxAzioni);
    btnElimina=new QPushButton("Elimina contatto",grBoxAzioni);
    QVBoxLayout* vAzioniLay=new QVBoxLayout;
    vAzioniLay->addWidget(btnVisualizza);
    vAzioniLay->addWidget(btnElimina);

    connect(btnVisualizza,SIGNAL(clicked()),this,SLOT(creaContattoView()));
    connect(btnElimina,SIGNAL(clicked()),this,SLOT(creaEliminaView()));

    grBoxAzioni->setLayout(vAzioniLay);
}


void ReteView::creaIndietroBox(){
    grBoxIndietro=new QGroupBox("Esci",this);
    grBoxIndietro->setFixedHeight(100);
    btnIndietro=new QPushButton("Indietro",grBoxIndietro);
    connect(btnIndietro,SIGNAL(clicked()),this,SLOT(close()));
    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(btnIndietro);

    grBoxIndietro->setLayout(vLay);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ReteView::filtraContatti(QString s){
    while(tbWcontatti->rowCount()>0)
        tbWcontatti->removeRow(0);
    int row = tbWcontatti->rowCount();//legge il numero di righe della tabella
    Rete::const_iterator it=utente->getReteBegin();
    for(;it!=utente->getReteEnd();it++){

        const SmartUtente* smUt=utente->getContattoReteSmart(it);

        if(comparatore(s.toStdString(),(*smUt)->getUsername()) || comparatore(s.toStdString(),(*smUt)->getNome()) ||
            comparatore(s.toStdString(),(*smUt)->getCognome())){
            tbWcontatti->insertRow(row);
            tbItUsername=new QTableWidgetItem;
            tbItNome=new QTableWidgetItem;
            tbItCognome=new QTableWidgetItem;
            tbItUsername->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            tbItNome->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            tbItCognome->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);

            tbItUsername->setText(QString::fromStdString((*smUt)->getUsername()));
            tbItNome->setText(QString::fromStdString((*smUt)->getNome()));
            tbItCognome->setText(QString::fromStdString((*smUt)->getCognome()));
            tbWcontatti->setItem(row,0,tbItUsername);
            tbWcontatti->setItem(row,1,tbItNome);
            tbWcontatti->setItem(row,2,tbItCognome);
            row++;
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

bool ReteView::comparatore(std::string a, std::string b){
    if(a.size()>b.size())
        return false;
    if(a==b)
        return true;
    bool diverso=false;
    for(unsigned int i=0;i<a.size() && !diverso;i++){
        if(std::toupper(a[i]) != std::toupper(b[i]))
            diverso=true;
    }
    return !diverso;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ReteView::creaContattoView(){
    if(tbWcontatti->currentRow() == -1){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai selezionato alcun contatto","Indietro");
        dialMessage->show();
    }
    else{
        Rete::const_iterator it=utente->getReteBegin();
        for(int i=0;i<tbWcontatti->currentRow();i++)
            it++;
        const SmartUtente* smUt=utente->getContattoReteSmart(it);

        dialContatto=new QDialog(this);
        dialContatto->setModal(true);
        dialContatto->setFixedSize(1024,600);
        dialContatto->setAttribute(Qt::WA_DeleteOnClose,true);
        profV=new ProfiloView(dialContatto,&*(*smUt));
        QGridLayout* gLay=new QGridLayout;
        gLay->addWidget(profV,0,0);
        dialContatto->setLayout(gLay);
        dialContatto->show();
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ReteView::creaEliminaView(){
    if(tbWcontatti->currentRow()==-1){
        DialogMessage* dialMessage=new DialogMessage("Errore","Attenzione, non hai selezionato alcun contatto","Indietro");
        dialMessage->show();
    }
    else{
        dialElimina=new QDialog(this);
        dialElimina->setWindowTitle("Rimuovi contatto");
        dialElimina->setAttribute(Qt::WA_DeleteOnClose,true);
        lblElimina=new QLabel(dialElimina);
        QString testo="Premi conferma per rimuovere l'utente <b>";
        testo+=QString::fromStdString(getSelectedUsername());
        testo+="</b> dalla tua rete di contatti";
        lblElimina->setText(testo);
        btnAnnullaElimina=new QPushButton("Annulla",dialElimina);
        btnConfermaElimina=new QPushButton("Conferma",dialElimina);

        connect(btnAnnullaElimina,SIGNAL(clicked()),dialElimina,SLOT(close()));
        connect(btnConfermaElimina,SIGNAL(clicked()),this,SLOT(eliminaContatto()));

        QVBoxLayout* vLay=new QVBoxLayout;
        vLay->addWidget(lblElimina);

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

std::string ReteView::getSelectedUsername(){
    int row=tbWcontatti->currentRow();
    if(row==-1)
        return ("");
    else{
        QTableWidgetItem* aux=tbWcontatti->item(row,0);
        QString auxString=aux->text();
        return auxString.toStdString();
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void ReteView::eliminaContatto(){
    dialElimina->close();
    delete dialElimina;
    emit signalRimuoviContattoRete(getSelectedUsername());
}

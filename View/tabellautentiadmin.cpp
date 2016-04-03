#include "tabellautentiadmin.h"

TabellaUtentiAdmin::TabellaUtentiAdmin(Amministratore* adM,QWidget*parent):QTableWidget(parent),adminModel(adM){
    setView();
    caricaEntryTabella();
}

TabellaUtentiAdmin::~TabellaUtentiAdmin(){}

void TabellaUtentiAdmin::setView(){
    this->insertColumn(0);
    this->insertColumn(1);
    this->insertColumn(2);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->setSelectionMode(QAbstractItemView::SingleSelection);
    QStringList campiTabella;//setta le header label della tabella
    campiTabella<<"Username"<<"Password"<<"Tipo Utente";
    this->setHorizontalHeaderLabels(campiTabella);
    this->horizontalHeader()->setSectionsClickable(false);//disabilita il click negli header;
    this->horizontalHeader()->setDefaultSectionSize(194);//imposta dimensioni label
}

void TabellaUtentiAdmin::caricaEntryTabella(){
    int row = this->rowCount();//legge il numero di righe della tabella
    Database::const_iterator const_it=adminModel->getDatabaseBegin();
    for(;const_it!=adminModel->getDatabaseEnd();const_it++){
        this->insertRow(row);
        username=new QTableWidgetItem;
        password=new QTableWidgetItem;
        tipoUtente=new QTableWidgetItem;
        username->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        password->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        tipoUtente->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        username->setText(QString::fromStdString(const_it->second->getUsername()));
        password->setText(QString::fromStdString(const_it->second->getPassword()));
        tipoUtente->setText(QString::fromStdString(getTipoUtente((const_it->second->getUsername()))));
        this->setItem(row,0,username);
        this->setItem(row, 1,password);
        this->setItem(row,2,tipoUtente);
        row++;
    }
    this->setCurrentCell(-1,-1);
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------

std::string TabellaUtentiAdmin::getSelectedUsername()const{
    int row=this->currentRow();
    if(row==-1)
        return ("");
    else{
        QTableWidgetItem* aux=this->item(row,0);
        QString auxString=aux->text();
        return auxString.toStdString();
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

void TabellaUtentiAdmin::filtraUsername(QString user){
    while(this->rowCount()>0)
        this->removeRow(0);
    int row = this->rowCount();//legge il numero di righe della tabella
    Database::const_iterator const_it=adminModel->getDatabaseBegin();
    for(;const_it!=adminModel->getDatabaseEnd();const_it++){
        if(comparatore(user.toStdString(),const_it->second->getUsername())){
            this->insertRow(row);
            username=new QTableWidgetItem;
            password=new QTableWidgetItem;
            tipoUtente=new QTableWidgetItem;
            username->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            password->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            tipoUtente->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            username->setText(QString::fromStdString(const_it->second->getUsername()));
            password->setText(QString::fromStdString(const_it->second->getPassword()));
            tipoUtente->setText(QString::fromStdString(getTipoUtente((const_it->second->getUsername()))));
            this->setItem(row,0,username);
            this->setItem(row, 1,password);
            this->setItem(row,2,tipoUtente);
            row++;
        }
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

bool TabellaUtentiAdmin::comparatore(std::string a, std::string b){
    if(a.size()>b.size())
        return false;
    if(a==b)
        return true;
    bool diverso=false;
    for(unsigned int i=0;i<a.size() && !diverso;i++){
        if(a[i]!=b[i])
            diverso=true;
    }
    return !diverso;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

std::string TabellaUtentiAdmin::getTipoUtente(std::string username){
    Utente* utente=adminModel->getUtente(username);

    std::string tipoUt;

    if(typeid(*utente)==typeid(UtenteBase))
        tipoUt="Basic";
    else if(typeid(*utente)==typeid(UtenteBusiness))
        tipoUt="Business";
    else if(typeid(*utente)==typeid(UtenteExecutive))
        tipoUt="Executive";

    return tipoUt;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

std::string TabellaUtentiAdmin::getSelectedType()const{
    int row=this->currentRow();
    if(row==-1)
        return ("");
    else{
        QTableWidgetItem* aux=this->item(row,2);
        QString auxString=aux->text();
        return auxString.toStdString();
    }
}

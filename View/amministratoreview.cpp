#include "amministratoreview.h"

//--------------------------------------------------------------------------COSTRUTTORI----------------------------------------------------------------------------------
AmministratoreView::AmministratoreView(Amministratore* admin):model(admin){
    setView();
}
AmministratoreView::~AmministratoreView(){}

//----------------------------------------------------------------------------METODI-----------------------------------------------------------------------------------
void AmministratoreView::setView(){
    this->setWindowTitle("LinQedIn - Amministatore");
    this->setFixedSize(1024,600);
    QHBoxLayout* hLay=new QHBoxLayout;//layout che divide in due l'applicazione
    QVBoxLayout* vLayout=new QVBoxLayout;
    tabellaUtenti=new TabellaUtentiAdmin(model,this);
    creaFiltraBox();//genera il primo box
    creaCambiaIscirizoneBox();//genera il secondo box
    creaInserisciEliminaUtenteBox();//genera ultimo box
    creaBoxEsci();
    hLay->addWidget(tabellaUtenti);//aggiungo la tabella
    vLayout->addWidget(boxFiltra,Qt::AlignTop);
    vLayout->addWidget(boxCambiaIscrizione,Qt::AlignTop);
    vLayout->addWidget(boxInserisciEliminaUtente,Qt::AlignTop);
    vLayout->addWidget(boxEsci,Qt::AlignTop);
    hLay->addLayout(vLayout);

    setLayout(hLay);
    centraFinestra(1024,600);
    this->show();
}


void AmministratoreView::centraFinestra(int windowWidth, int windowHeight){
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}


void AmministratoreView::creaFiltraBox(){
    QVBoxLayout *boxFiltraLayout=new QVBoxLayout;
    boxFiltra=new QGroupBox("Filtra utenti della tabella",this);
    boxFiltra->setFixedSize(375,175);
    labelFiltra=new QLabel(boxFiltra);
    labelFiltra->setText("Inserisci il nome utente da cercare:");
    lineEditFiltra=new QLineEdit(boxFiltra);
    lineEditFiltra->setFixedWidth(300);
    btnResetFiltra=new QPushButton("Reset",boxFiltra);
    btnResetFiltra->setFixedWidth(125);
    boxFiltraLayout->addWidget(labelFiltra);
    boxFiltraLayout->addWidget(lineEditFiltra);
    boxFiltraLayout->addWidget(btnResetFiltra);
    boxFiltraLayout->addStretch();
    boxFiltra->setLayout(boxFiltraLayout);
    connect(btnResetFiltra,SIGNAL(clicked()),lineEditFiltra,SLOT(clear()));
    connect(lineEditFiltra,SIGNAL(textChanged(QString)),tabellaUtenti,SLOT(filtraUsername(QString)));
}

void AmministratoreView::creaCambiaIscirizoneBox(){
    QVBoxLayout *boxCambiaIscrizioneLayout=new QVBoxLayout;
    boxCambiaIscrizione=new QGroupBox("Cambia tipo di iscrizione a LinQedIn",this);
    boxCambiaIscrizione->setFixedSize(375,175);
    labelCambiaIscrizione=new QLabel(boxCambiaIscrizione);
    labelCambiaIscrizione->setText("Seleziona il nuovo tipo di iscrizione dell'utente");

    radioBtnBase=new QRadioButton("Utente Basic",boxCambiaIscrizione);
    radioBtnBusiness=new QRadioButton("Utente Business",boxCambiaIscrizione);
    radioBtnExclusive=new QRadioButton("Utente Executive",boxCambiaIscrizione);

    btnCambiaIscrizione=new QPushButton("Cambia",boxCambiaIscrizione);
    btnCambiaIscrizione->setFixedWidth(100);
    connect(btnCambiaIscrizione,SIGNAL(clicked()),this,SLOT(confermaCambioUtente()));

    boxCambiaIscrizioneLayout->addWidget(labelCambiaIscrizione);
    boxCambiaIscrizioneLayout->addWidget(radioBtnBase);
    boxCambiaIscrizioneLayout->addWidget(radioBtnBusiness);
    boxCambiaIscrizioneLayout->addWidget(radioBtnExclusive);
    boxCambiaIscrizioneLayout->addWidget(btnCambiaIscrizione);
    boxCambiaIscrizioneLayout->addStretch();
    boxCambiaIscrizione->setLayout(boxCambiaIscrizioneLayout);
}

void AmministratoreView::creaInserisciEliminaUtenteBox(){
    QVBoxLayout* boxInserisciEliminaUtenteLayout=new QVBoxLayout;
    boxInserisciEliminaUtente=new QGroupBox("Inserisci o rimuovi un utente da LinQedIn",this);
    boxInserisciEliminaUtente->setFixedSize(375,125);
    btnInserisciUtente=new QPushButton("Inserisci nuovo utente",boxInserisciEliminaUtente);
    btnInserisciUtente->setFixedWidth(200);

    btnEliminaUtente=new QPushButton("Elimina utente",boxInserisciEliminaUtente);
    btnEliminaUtente->setFixedWidth(200);
    boxInserisciEliminaUtenteLayout->addWidget(btnInserisciUtente);
    boxInserisciEliminaUtenteLayout->addWidget(btnEliminaUtente);
    boxInserisciEliminaUtente->setLayout(boxInserisciEliminaUtenteLayout);

    connect(btnInserisciUtente,SIGNAL(clicked()),this,SLOT(inserisciUtente()));
    connect(btnEliminaUtente,SIGNAL(clicked()),this,SLOT(confermaEliminaUtente()));

}

void AmministratoreView::creaBoxEsci(){
    boxEsci=new QGroupBox("Esci",this);
    boxEsci->setFixedSize(375,100);
    btnLogout=new QPushButton("Logout",boxEsci);
    btnLogout->setFixedWidth(200);
    connect(btnLogout,SIGNAL(clicked()),this,SLOT(logout()));
    QVBoxLayout* vLay=new QVBoxLayout;
    vLay->addWidget(btnLogout);

    boxEsci->setLayout(vLay);
}

//-----------------------SEGNALI-------------------------
void AmministratoreView::inserisciUtente(){
    emit signalInserisciUtente();
}

void AmministratoreView::confermaEliminaUtente(){
    dialConfermaElimina=new QDialog;
    dialConfermaElimina->setModal(true);
    lblConfermaElimina=new QLabel(dialConfermaElimina);

    if(tabellaUtenti->getSelectedUsername().size()!=0){
        btnConfermaElimina=new QPushButton("Conferma");
        btnAnnullaElimina=new QPushButton("Annulla");
        std::string tot="Premere Conferma per eliminare l'utente <b>" + tabellaUtenti->getSelectedUsername() + "</b><br/>Premere Annulla per annullare l'operazione";
        lblConfermaElimina->setText(QString::fromStdString(tot));
        QVBoxLayout* vLay=new QVBoxLayout(dialConfermaElimina);
        QHBoxLayout* hLay=new QHBoxLayout;
        dialConfermaElimina->layout()->setSizeConstraint(QLayout::SetFixedSize);
        hLay->addWidget(btnAnnullaElimina);
        hLay->addWidget(btnConfermaElimina);
        vLay->addWidget(lblConfermaElimina);
        vLay->addLayout(hLay);
        dialConfermaElimina->setLayout(vLay);
        dialConfermaElimina->show();
        connect(btnAnnullaElimina,SIGNAL(clicked()),dialConfermaElimina,SLOT(close()));
        connect(btnConfermaElimina,SIGNAL(clicked()),this,SLOT(eliminaUtente()));
    }
    else{
        dialMessage=new DialogMessage("Elimina Utente","Non hai selezionato alcune utente da eliminare","Ok");
        dialMessage->show();
    }


}

void AmministratoreView::eliminaUtente(){
    dialConfermaElimina->close();
    emit signalEliminaUtente(tabellaUtenti->getSelectedUsername());
}

void AmministratoreView::confermaCambioUtente(){
    if(tabellaUtenti->getSelectedUsername().size()==0){
        dialMessage=new DialogMessage("Cambia tipo di iscrizione","Non hai selezionato alcun utente","Ok");
        dialMessage->show();
    }
    else if(!radioBtnBase->isChecked() && !radioBtnBusiness->isChecked() && !radioBtnExclusive->isChecked()){
        dialMessage=new DialogMessage("Cambia tipo di iscrizione","Non hai selezionato il nuovo tipo di utente","Ok");
        dialMessage->show();
    }
    else if(radioBtnBase->isChecked() && tabellaUtenti->getSelectedType()=="Basic"){
        dialMessage=new DialogMessage("Cambia tipo di iscrizione","L'utente selezionato è già un utente di tipo basic","Ok");
        dialMessage->show();
    }
    else if(radioBtnBusiness->isChecked() && tabellaUtenti->getSelectedType()=="Business"){
        dialMessage=new DialogMessage("Cambia tipo di iscrizione","L'utente selezionato è già un utente di tipo business","Ok");
        dialMessage->show();
    }
    else if(radioBtnExclusive->isChecked() && tabellaUtenti->getSelectedType()=="Executive"){
        dialMessage=new DialogMessage("Cambia tipo di iscrizione","L'utente selezionato è già un utente di tipo executive","Ok");
        dialMessage->show();
    }
    else{
        dialConfermaCambioIscrizione=new QDialog;
        dialConfermaCambioIscrizione->setWindowTitle("Cambio iscirizone");
        dialConfermaCambioIscrizione->setModal(true);
        QVBoxLayout* vLay=new QVBoxLayout(dialConfermaCambioIscrizione);
        dialConfermaCambioIscrizione->layout()->setSizeConstraint(QLayout::SetFixedSize);
        QLabel* lblMessaggio=new QLabel(dialConfermaCambioIscrizione);
        QPushButton* btnAnnulaCambio=new QPushButton("Annulla",dialConfermaCambioIscrizione);
        QPushButton* btnConfermaCambio=new QPushButton("Conferma",dialConfermaCambioIscrizione);
        btnAnnulaCambio->setFixedWidth(125);
        btnConfermaCambio->setFixedWidth(125);
        QHBoxLayout* hLay=new QHBoxLayout;
        hLay->addWidget(btnAnnulaCambio);
        hLay->addWidget(btnConfermaCambio);
        vLay->addWidget(lblMessaggio);
        vLay->addLayout(hLay);

        std::string username=tabellaUtenti->getSelectedUsername();
        std::string tipoUt=tabellaUtenti->getSelectedType();
        std::string nuovoTipo;
        if(radioBtnBase->isChecked())
            nuovoTipo="Basic";
        else if(radioBtnBusiness->isChecked())
            nuovoTipo="Business";
        else if(radioBtnExclusive->isChecked())
            nuovoTipo="Executive";

        QString strMessaggio=QString::fromStdString("Stai per cambiare il tipo di iscrizione dell'utente " + username + "" + " da tipo " + tipoUt + " a tipo " + nuovoTipo);
        lblMessaggio->setText(strMessaggio);
        dialConfermaCambioIscrizione->show();
        connect(btnAnnulaCambio,SIGNAL(clicked()),dialConfermaCambioIscrizione,SLOT(close()));
        connect(btnConfermaCambio,SIGNAL(clicked()),this,SLOT(cambiaTipoUtente()));
    }
}

void AmministratoreView::cambiaTipoUtente(){
    dialConfermaCambioIscrizione->close();
    std::string nuovoTipo;
    if(radioBtnBase->isChecked())
        nuovoTipo="Basic";
    else if(radioBtnBusiness->isChecked())
        nuovoTipo="Business";
    else if(radioBtnExclusive->isChecked())
        nuovoTipo="Executive";

    emit signalCambiaTipoUtente(tabellaUtenti->getSelectedUsername(),nuovoTipo);
}

void AmministratoreView::logout(){
    emit signalLogoutAdmin();
}

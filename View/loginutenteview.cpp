#include "loginutenteview.h"

LoginUtenteView::LoginUtenteView(){
    databaseModel=new Database;
    databaseModel->caricaDatabase();
    setView();
    connect(btnConferma,SIGNAL(clicked()),this,SLOT(verificaLogin()));
    connect(btnAnnula,SIGNAL(clicked()),this,SLOT(annullaLogin()));
}

LoginUtenteView::~LoginUtenteView(){
    delete databaseModel;
}


void LoginUtenteView::setView(){
    this->setWindowTitle("Login - LinQedIn");
    lblMessaggio=new QLabel("Effettua il login per accedere:",this);
    lblUsername=new QLabel("Username:",this);
    lblPassword=new QLabel("Password:",this);
    btnConferma=new QPushButton("Login",this);
    btnAnnula=new QPushButton("Annulla",this);
    liEdUsername=new QLineEdit(this);
    liEdUsername->setFixedWidth(350);
    liEdPassword=new QLineEdit(this);
    liEdPassword->setFixedWidth(350);
    liEdPassword->setEchoMode(QLineEdit::Password);
    QLabel* filler=new QLabel(this);
    QVBoxLayout* vLay=new QVBoxLayout(this);
    vLay->addWidget(lblMessaggio);
    vLay->addWidget(lblUsername);
    vLay->addWidget(liEdUsername);
    vLay->addWidget(lblPassword);
    vLay->addWidget(liEdPassword);
    vLay->addWidget(filler);
    QHBoxLayout* hLay=new QHBoxLayout;
    hLay->addWidget(btnAnnula);
    hLay->addWidget(btnConferma);
    vLay->addLayout(hLay);
    vLay->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(vLay);
    centraFinestra(450,250);
    this->show();
}

void LoginUtenteView::centraFinestra(int windowWidth, int windowHeight){
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}

void LoginUtenteView::verificaLogin(){
    if(!databaseModel->controllaPresenzaUsername(liEdUsername->text().toStdString())){
        dialMessage=new DialogMessage("Dati non corretti","Username o password inseriti non corretti","Ok");
        dialMessage->show();
    }
    else{
        Utente* ut=databaseModel->getUtente(liEdUsername->text().toStdString());
        if(ut->getPassword()!=liEdPassword->text().toStdString()){
            dialMessage=new DialogMessage("Dati non corretti","Username o password inseriti non corretti","Ok");
            dialMessage->show();
        }
        else{
            emit signalLoginCorretto(liEdUsername->text().toStdString());
        }
    }
}

void LoginUtenteView::annullaLogin(){
    emit signalAnnulla();
}

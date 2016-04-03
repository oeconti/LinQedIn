#include "schermatainizialeview.h"

//--------------------------------------------------------------------COSTRUTTORI---------------------------------------------------------------------------------------------------
SchermataInizialeView::SchermataInizialeView()
{
    this->setFixedSize(375,100);
    labelIniziale=new QLabel(this);
    labelIniziale->setText(QString::fromStdString("Benvenuto!\nSeleziona in che modo vuoi loggarti a LinQedIn:"));

    buttonAdmin=new QPushButton(this);
    buttonAdmin->setText(QString::fromStdString("Amministratore"));
    buttonAdmin->setFixedWidth(150);

    buttonUser=new QPushButton(this);
    buttonUser->setText(QString::fromStdString("Utente"));
    buttonUser->setFixedWidth(150);

    connect(buttonAdmin,SIGNAL(clicked()),this,SLOT(caricaAmministratore()));
    connect(buttonUser,SIGNAL(clicked()),this,SLOT(caricaUtente()));

    QGridLayout *layout=new QGridLayout();
    layout->addWidget(labelIniziale,0,0,1,2);
    layout->addWidget(buttonAdmin,1,0);
    layout->addWidget(buttonUser,1,1);
    setLayout(layout);
    centraFinestra(375,100);
    this->show();
}

SchermataInizialeView::~SchermataInizialeView(){}

//----------------------------------------------------------------------METODI---------------------------------------------------------------------------------------------------------

void SchermataInizialeView::centraFinestra(int windowWidth, int windowHeight){
    QDesktopWidget *desktop = QApplication::desktop();
    int x, y;
    int screenWidth, screenHeight;
    screenWidth = desktop->width();
    screenHeight = desktop->height();
    x = (screenWidth-windowWidth) / 2;
    y = (screenHeight-windowHeight) / 2;
    this->move(x,y);
}


//----------------------------------------------------------------------Signals--------------------------------------------------------------------------------------------------------
void SchermataInizialeView::caricaAmministratore(){
    emit signalAmministratore();
}

void SchermataInizialeView::caricaUtente(){
    emit signalUtente();
}

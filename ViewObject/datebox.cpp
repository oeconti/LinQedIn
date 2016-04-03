#include "datebox.h"

DateBox::DateBox(QWidget* parent,int i,int f):QWidget(parent),annoInizio(i),annoFine(f){
    giorno=new QComboBox(parent);
    mese=new QComboBox(parent);
    anno=new QComboBox(parent);
    giorno->setFixedWidth(100);
    mese->setFixedWidth(100);
    anno->setFixedWidth(100);
    generaNumeri(giorno,1,31);
    generaNumeri(mese,1,12);
    generaNumeri(anno,annoInizio,annoFine);
    QHBoxLayout* lay=new QHBoxLayout;
    lay->setSizeConstraint(QLayout::SetFixedSize);
    lay->addWidget(giorno);
    lay->addWidget(mese);
    lay->addWidget(anno);
    setLayout(lay);
    connect(mese,SIGNAL(activated(int)),this,SLOT(aggiornaGiorni()));
    connect(anno,SIGNAL(activated(int)),this,SLOT(aggiornaGiorni()));
}

DateBox::DateBox(QWidget * parent, int i, int f, QDate dataToSet):QWidget(parent),annoInizio(i),annoFine(f){
    giorno=new QComboBox(parent);
    mese=new QComboBox(parent);
    anno=new QComboBox(parent);
    giorno->setFixedWidth(100);
    mese->setFixedWidth(100);
    anno->setFixedWidth(100);
    generaNumeri(giorno,1,31);
    generaNumeri(mese,1,12);
    generaNumeri(anno,annoInizio,annoFine);

    giorno->setCurrentText(intToQString(dataToSet.day()));
    mese->setCurrentText(intToQString(dataToSet.month()));
    anno->setCurrentText(intToQString(dataToSet.year()));
    QHBoxLayout* lay=new QHBoxLayout;
    lay->setSizeConstraint(QLayout::SetFixedSize);
    lay->addWidget(giorno);
    lay->addWidget(mese);
    lay->addWidget(anno);
    setLayout(lay);
    connect(mese,SIGNAL(activated(int)),this,SLOT(aggiornaGiorni()));
    connect(anno,SIGNAL(activated(int)),this,SLOT(aggiornaGiorni()));
}


DateBox::~DateBox(){}

void DateBox::generaNumeri(QComboBox* c,int inizio,int fine){
    for(int i=inizio;i<fine + 1;i++){
        std::string numero;
        std::stringstream buffer;
        buffer<<i;
        numero=buffer.str();
        c->addItem(QString::fromStdString(numero));
    }
}

QDate DateBox::getDate()const{
    int g=giorno->currentText().toInt();
    int m=mese->currentText().toInt();
    int a=anno->currentText().toInt();
    return QDate(a,m,g);
}

void DateBox::refresh(int annoInizio,int annoFine,bool corso){
    if(corso){
        giorno->clear();
        mese->clear();
        anno->clear();
    }
    else{
        generaNumeri(giorno,1,31);
        generaNumeri(mese,1,12);
        generaNumeri(anno,annoInizio,annoFine);
    }
}

//----------------------------Slot

void DateBox::aggiornaGiorni(){
    int m=mese->currentText().toInt();
    switch(m){
        case(1):
            giorno->clear();
            generaNumeri(giorno,1,31);
            break;
        case(2):
            giorno->clear();
            if(anno->currentText().toInt() % 4 == 0)
                generaNumeri(giorno,1,29);
            else
                generaNumeri(giorno,1,28);
            break;
        case(3):
            giorno->clear();
            generaNumeri(giorno,1,31);
            break;
        case(4):
            giorno->clear();
            generaNumeri(giorno,1,30);
            break;
        case(5):
            giorno->clear();
            generaNumeri(giorno,1,31);
            break;
        case(6):
            giorno->clear();
            generaNumeri(giorno,1,30);
            break;
        case(7):
            giorno->clear();
            generaNumeri(giorno,1,31);
            break;
        case(8):
            giorno->clear();
            generaNumeri(giorno,1,31);
            break;
        case(9):
            giorno->clear();
            generaNumeri(giorno,1,30);
            break;
        case(10):
            giorno->clear();
            generaNumeri(giorno,1,31);
            break;
        case(11):
            giorno->clear();
            generaNumeri(giorno,1,30);
            break;
        case(12):
            giorno->clear();
            generaNumeri(giorno,1,31);
            break;
    }
}

QString DateBox::intToQString(int x){
    std::stringstream convert;
    std::string result;
    convert<<x;
    result=convert.str();
    return QString::fromStdString(result);
}

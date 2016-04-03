#ifndef INSERISCIUTVIEW_H
#define INSERISCIUTVIEW_H
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QScrollArea>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSizePolicy>
#include <QPushButton>
#include <QFrame>
#include <QComboBox>
#include <QRadioButton>
#include <QPushButton>
#include <string>
#include <QDate>
#include <QButtonGroup>

#include "Model/amministratore.h"
#include "ViewObject/datebox.h"
#include "ViewObject/dialogmessage.h"


class InserisciUtView:public QWidget
{
    Q_OBJECT
private:
    Amministratore* model;

    QScrollArea* scrollArea;
    QFrame* frmScrollContainer;

    QLineEdit* liEdUserName;
    QLabel* lblUserName;
    QLineEdit* liEdPassword;
    QLabel* lblPassword;
    QLineEdit* liEdNome;
    QLabel* lblNome;
    QLineEdit* liEdCognome;
    QLabel* lblCognome;
    QLabel* lblNascita;
    DateBox* dateBox;
    QLabel* lblResidenza;
    QLabel* lblVia;
    QLineEdit* liEdVia;
    QLabel* lblCitta;
    QLineEdit* liEdCitta;
    QLabel* lblProvincia;
    QLineEdit* liEdProvincia;
    QLabel* lblNazione;
    QLineEdit* liEdNazione;
    QLabel* lblTipoUtente;

    QButtonGroup* btnGrpTipoUtente;
    QRadioButton* rdBtnBasic;
    QRadioButton* rdBtnBusiness;
    QRadioButton* rdBtnExecutive;

    QPushButton* btnCrea;
    QPushButton* btnAnnulla;

    QButtonGroup* btnGrpSesso;
    QLabel* lblSesso;
    QRadioButton* rdBtnSessoU;
    QRadioButton* rdBtnSessoD;

    DialogMessage* dialMessage;

    void setView();
    void centraFinestra(int,int);

public:
    InserisciUtView(Amministratore*);
    ~InserisciUtView();

private slots:
    void checkDati();
    void annullaCreazione();

signals:
    void creaUtBasic(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string);
    void creaUtBusiness(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string);
    void creaUtExecutive(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string);
    void utNonCreato();

};

#endif // INSERISCIUTVIEW_H

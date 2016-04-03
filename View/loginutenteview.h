#ifndef LOGINUTENTEVIEW_H
#define LOGINUTENTEVIEW_H
#include <QDialog>
#include <QDesktopWidget>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "Model/database.h"
#include "ViewObject/dialogmessage.h"


class LoginUtenteView:public QDialog
{
    Q_OBJECT
private:
    Database* databaseModel;

    QLabel* lblMessaggio;
    QLabel* lblUsername;
    QLabel* lblPassword;

    QLineEdit* liEdUsername;
    QLineEdit* liEdPassword;

    QPushButton* btnConferma;
    QPushButton* btnAnnula;

    DialogMessage* dialMessage;

    void setView();
    void centraFinestra(int,int);

public:
    LoginUtenteView();
    ~LoginUtenteView();

private slots:
    void verificaLogin();
    void annullaLogin();
signals:
    void signalLoginCorretto(std::string);
    void signalAnnulla();
};

#endif // LOGINUTENTEVIEW_H

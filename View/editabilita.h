#ifndef EDITABILITA_H
#define EDITABILITA_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <string>
#include <QStringList>

#include "ViewObject/dialogmessage.h"

class EditAbilita:public QDialog
{
    Q_OBJECT
private:
    QLabel* lblInsAbilita;
    QLineEdit* liEdInsAbilita;
    QLabel* lblInsAbilitaDescr;
    QTextEdit* txEdInsAbilDescr;
    QPushButton* btnConfermaInsAbilita;
    QPushButton* btnAnnullaInsAbilita;

    std::string vAbilita;
    std::string vDescrizione;
    QStringList listaAbilita;

    void creaInserisciMode();
    void creaEditMode();
    void creaLayout();
    bool controlloDati();
    void caricaDati();

public:
    EditAbilita(QWidget*);
    EditAbilita(QWidget *,std::string,std::string);
    ~EditAbilita();

private slots:
    void confermaInsAbilita();
    void confermaModifica();
signals:
    void signalInserisciAbilita(QStringList);
    void signalModificaAbilita(QStringList);
};

#endif // EDITABILITA_H

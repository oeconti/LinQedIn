#ifndef MODIFICADATIANAGRAFICIVIEW_H
#define MODIFICADATIANAGRAFICIVIEW_H
#include <QDialog>
#include <QLabel>
#include <QLabel>
#include <QRadioButton>
#include <QLineEdit>
#include <QPushButton>
#include <QStringList>
#include <QDate>
#include "ViewObject/datebox.h"
#include "ViewObject/dialogmessage.h"
#include "Model/utente.h"

class ModificaDatiAnagraficiView: public QDialog
{
    Q_OBJECT
private:
    Utente* utente;
    QLabel* lblModNome;
    QLineEdit* liEdModNome;
    QLabel* lblModCognome;
    QLineEdit* liEdModCognome;
    QLabel* lblModSesso;
    QRadioButton* rdBtnUomo;
    QRadioButton* rdBtnDonna;
    QLabel* lblModCittaRes;
    QLineEdit* liEdModCittaRes;
    QLabel* lblModProvRes;
    QLineEdit* liEdModProvRes;
    QLabel* lblModNazRes;
    QLineEdit* liEdModNazRes;
    QLabel* lblModDataNascita;
    DateBox* dateBoxDataNascita;
    QPushButton* btnAnnullaModDatAn;
    QPushButton* btnSalvaDatiAn;

    QStringList listaDati;

public:
    ModificaDatiAnagraficiView(QWidget*,Utente*);
    ~ModificaDatiAnagraficiView();
private slots:
    void modificaDatiAnagrafici();
signals:
    void signalModificaDatiAnagrafici(QStringList);
};

#endif // MODIFICADATIANAGRAFICIVIEW_H

#ifndef AMMINISTRATOREVIEW_H
#define AMMINISTRATOREVIEW_H
#include "Model/amministratore.h"
#include "ViewObject/dialogmessage.h"
#include "View/tabellautentiadmin.h"

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDesktopWidget>
#include <QApplication>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QRadioButton>
#include <QDialog>

class AmministratoreView: public QWidget
{
    Q_OBJECT
private:
    Amministratore* model;
    TabellaUtentiAdmin *tabellaUtenti;
    QGroupBox *boxFiltra;
    QLabel *labelFiltra;
    QLineEdit *lineEditFiltra;
    QPushButton* btnResetFiltra;

    QGroupBox* boxCambiaIscrizione;
    QLabel* labelCambiaIscrizione;
    QRadioButton* radioBtnBase;
    QRadioButton* radioBtnBusiness;
    QRadioButton* radioBtnExclusive;
    QPushButton* btnCambiaIscrizione;

    QGroupBox* boxInserisciEliminaUtente;
    QPushButton* btnInserisciUtente;
    QPushButton* btnEliminaUtente;

    QGroupBox* boxEsci;
    QPushButton* btnLogout;

    QDialog* dialConfermaElimina;
    QLabel* lblConfermaElimina;
    QPushButton* btnConfermaElimina;
    QPushButton* btnAnnullaElimina;

    DialogMessage* dialMessage;

    QDialog* dialConfermaCambioIscrizione;


    void setView();
    void centraFinestra(int,int);

    void creaFiltraBox();
    void creaCambiaIscirizoneBox();
    void creaInserisciEliminaUtenteBox();
    void creaBoxEsci();

public:
    AmministratoreView(Amministratore*);
    ~AmministratoreView();
private slots:
    void inserisciUtente();
    void eliminaUtente();
    void confermaEliminaUtente();
    void confermaCambioUtente();
    void cambiaTipoUtente();

    void logout();
signals:
    void signalInserisciUtente();
    void signalEliminaUtente(std::string);
    void signalCambiaTipoUtente(std::string,std::string);
    void signalLogoutAdmin();


};

#endif // AMMINISTRATOREVIEW_H

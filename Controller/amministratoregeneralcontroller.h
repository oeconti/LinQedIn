#ifndef AMMINISTRATOREGENERALCONTROLLER_H
#define AMMINISTRATOREGENERALCONTROLLER_H
#include <QObject>
#include "Controller/amministratorecontroller.h"
#include "Controller/inserisciutcontroller.h"
#include "View/amministratoreview.h"
#include "View/inserisciutview.h"
#include "ViewObject/dialogmessage.h"

class AmministratoreGeneralController:public QObject//mi serve la derivazione per usare le signal e le connect
{
    Q_OBJECT
private:
    Amministratore* adminModel;

    AmministratoreController *adminController;
    AmministratoreView *adminView;

    InserisciUtController* insUtController;
    InserisciUtView* insUtView;

    DialogMessage* dialMessage;

    void caricaConnect();

public:
    AmministratoreGeneralController();
    ~AmministratoreGeneralController();
private slots:
    void CaricaInsUtView();
    void inseritoUtente(bool);
    void eliminatoUtente();
    void cambiatoUtente();
    void logoutAdminView();
signals:
    void signalLogoutAdminView();
};

#endif // AMMINISTRATOREGENERALCONTROLLER_H

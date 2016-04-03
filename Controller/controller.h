#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <string>
#include "View/schermatainizialeview.h"
#include "Controller/amministratoregeneralcontroller.h"
#include "View/loginutenteview.h"
#include "Controller/utentegeneralcontroller.h"

class Controller:public QObject{
    Q_OBJECT
private:
    SchermataInizialeView* schermataInizialeV;
    AmministratoreGeneralController* adminGeneralController;
    LoginUtenteView* loginView;
    UtenteGeneralController* utGeneralControllorer;

public:
    Controller();
    ~Controller();
private slots:
    void caricaAdminView();
    void caricaSchermataInizialeView();
    void caricaLoginView();
    void caricaUtenteView(std::string);
    void adminLogout();
    void annullaLogin();
    void utenteLogout();
};

#endif // CONTROLLER_H

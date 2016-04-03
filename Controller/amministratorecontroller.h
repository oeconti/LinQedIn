#ifndef AMMINISTRATORECONTROLLER_H
#define AMMINISTRATORECONTROLLER_H
#include "Model/amministratore.h"
#include "View/amministratoreview.h"
#include <QObject>

class AmministratoreController:public QObject{
    Q_OBJECT
private:
    Amministratore* adminModel;
    AmministratoreView* adminView;

public:
    AmministratoreController(Amministratore*,AmministratoreView*);
    ~AmministratoreController();

    void caricaDatabase();
    void salvaDatabase()const;

    bool inserisciNuovoUtente(Utente*);
    bool controllaPresenzaUsername(const std::string&)const;

    Utente* getUtente(const std::string&)const;
    SmartUtente& getSmartUtente(const std::string&)const;
    Database::const_iterator getDatabaseBegin()const;
    Database::const_iterator getDatabaseEnd()const;
    int getDatabaseSize()const;
private slots:
    void eliminaUtente(std::string);
    void cambiaTipoUtente(std::string,std::string);
    void logoutAdminView();
signals:
    void signalUtEliminato();
    void signalUtCambiato();
    void signalLogoutAdminView();
};

#endif // AMMINISTRATORECONTROLLER_H

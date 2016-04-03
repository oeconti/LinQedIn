#ifndef UTENTEGENERALCONTROLLER_H
#define UTENTEGENERALCONTROLLER_H
#include <QObject>

#include "View/utenteview.h"
#include "ViewObject/dialogmessage.h"
#include "Model/database.h"
#include "Controller/utentecontroller.h"



class UtenteGeneralController:public QObject
{
    Q_OBJECT
private:
    Database* databaseModel;
    UtenteController* utenteController;

    UtenteView* utenteView;

public:
    UtenteGeneralController(std::string);
    ~UtenteGeneralController();

private slots:
    void creaUtenteView(std::string);
    void refreshUtenteView(std::string,std::string);

    void abilitaInserita(std::string);
    void linguaAggiunta(std::string);
    void esperienzaProfAggiunta(std::string);
    void esperienzaScolAggiunta(std::string);
    void datiAnagraficiModificati(std::string);
    void linguaModificata(std::string);
    void linguaEliminata(std::string);
    void abilitaModificata(std::string);
    void abilitaEliminata(std::string);
    void esperienzaScolMod(std::string);
    void esperienzaScolEliminata(std::string);
    void esperienzaProfModificata(std::string);
    void esperienzaProfEliminata(std::string);
    void contattoReteRimossso(std::string);

    void creaConnect();
    void logoutUtente();

signals:
    void signalLogoutUtente();
};

#endif // UTENTEGENERALCONTROLLER_H

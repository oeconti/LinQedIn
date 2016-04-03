#ifndef UTENTECONTROLLER_H
#define UTENTECONTROLLER_H
#include <QObject>
#include <QStringList>

#include "Model/database.h"
#include "Model/utente.h"
#include "View/utenteview.h"
#include "View/modificaprofiloview.h"
#include "ViewObject/dialogmessage.h"

class UtenteController:public QObject
{
    Q_OBJECT
private:
    Database* database;
    Utente* utente;
    UtenteView* utenteView;
    ModificaProfiloView* modProfView;
public:
    UtenteController(Database*,Utente*,UtenteView*);
    ~UtenteController();
public slots:
    void inserisciAbilita(QStringList);
    void modficiaAbilita(QStringList);
    void eliminaAbilita(std::string);

    void inserisciLingua(QStringList);
    void modificaLingua(QStringList);
    void eliminaLingua(std::string);


    void inserisciEspProf(QStringList);
    void modificaEspProf(EsperienzeProfessionali::const_iterator,QStringList);
    void eliminaEspProf(EsperienzeProfessionali::const_iterator);

    void inserisciEspScol(QStringList);
    void modificaEspScol(EsperienzeScolastiche::const_iterator,QStringList);
    void eliminaEspScol(EsperienzeScolastiche::const_iterator);

    void modificaDatiAnagrafici(QStringList);

    void eliminaContattoRete(std::string);

    std::map<std::string,Utente*> cerca(std::string)const;

    void aggiungiContattoRete(std::string);

    void logoutUtente();
signals:
    void signalAbilitaInserita(std::string);
    void signalAbilitaModificata(std::string);
    void signalAbilitaEliminata(std::string);

    void signalLinguaAggiunta(std::string);
    void signalLinguaModificata(std::string);
    void signalLinguaEliminata(std::string);

    void signalEsperienzaProfAggiunta(std::string);
    void signalEspProfModificata(std::string);
    void signalEspProfEliminata(std::string);

    void signalEsperienzaScolAggiunta(std::string);
    void signalEsperienzaScolasticaModificata(std::string);
    void signalEspScolEliminata(std::string);

    void signalDatiAnagraficiModificati(std::string);

    void signalContattoRimosso(std::string);

    void signalLogoutUtente();
};

#endif // UTENTECONTROLLER_H

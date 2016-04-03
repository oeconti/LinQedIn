#ifndef UTENTEVIEW_H
#define UTENTEVIEW_H
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QString>
#include <QFrame>
#include <QGroupBox>
#include <QStringList>
#include <string>


#include "Model/utente.h"
#include "ViewObject/dialogmessage.h"
#include "ViewObject/datebox.h"
#include "ViewObject/profiloview.h"
#include "View/modificaprofiloview.h"
#include "View/editabilita.h"
#include "View/editesperienzeprofessionali.h"
#include "View/editesperienzescolastiche.h"
#include "View/editlinguaparlata.h"
#include "View/modificalinguaview.h"
#include "View/modificadatianagraficiview.h"
#include "View/modificaabilitaview.h"
#include "View/modificatitolostudioview.h"
#include "View/modificaesperienzeprofessionaliview.h"
#include "View/reteview.h"
#include "View/cercaview.h"

class UtenteView:public QWidget
{
    Q_OBJECT
private:
    Utente* utente;

    ProfiloView* profV;

    QWidget* widgetDestro;
    QGroupBox* boxGenerale;
    QGroupBox* boxProfilo;
    QGroupBox* boxLogout;

    QPushButton* btnCerca;
    QPushButton* btnVisualizzaRete;
    QPushButton* btnLogout;

    QPushButton* btnModifica;
    QPushButton* btnInsEspLav;
    QPushButton* btnInsEspScol;
    QPushButton* btnInsAbilita;
    QPushButton* btnInsLingua;

    ModificaProfiloView* modProV;
    ModificaLinguaView* modLinguaV;
    ModificaDatiAnagraficiView* modDatAnV;
    ModificaAbitliaView* modAbilitaV;
    ModificaTitoloStudioView* modTitStudioV;
    ModificaEsperienzeProfessionaliView* modEspProfV;

    EditAbilita* insAbV;
    EditEsperienzeProfessionali* insEspProfV;
    EditEsperienzeScolastiche* insEspScolV;
    EditLinguaParlata* insLingParlV;

    ReteView* reteV;

    CercaView* cercaV;

    void setView();
    void creaScrollArea();
    void creaBoxGenerale();
    void creaBoxProfilo();
    void creaBoxLogout();
public:
    UtenteView(Utente*);
    ~UtenteView();
private slots:
    void caricaModificaProfiloView();

    void caricaInsAbilitaView();
    void inserisciAbilita(QStringList);
    void caricaModificaAbilitaView();
    void modificaAbilita(QStringList);
    void eliminaAbilita(std::string);

    void caricaInsLinguaView();
    void aggiungiLingua(QStringList);
    void caricaModificaLinguaView();
    void modificaLingua(QStringList);
    void eliminaLingua(std::string);


    void caricaInsEspProfView();
    void aggiungiEspProf(QStringList);
    void caricaModificaEspProfView();
    void modificaEspProf(EsperienzeProfessionali::const_iterator,QStringList);
    void eliminaEspProf(EsperienzeProfessionali::const_iterator);


    void caricaInsEspScolView();
    void aggiungiEspScol(QStringList);
    void caricaModificaEspScolView();
    void modificaEspScol(EsperienzeScolastiche::const_iterator,QStringList);
    void eliminaEspScol(EsperienzeScolastiche::const_iterator);

    void caricaModificaDatiAnagraficiView();
    void modificaDatiAnagrafici(QStringList);

    void caricaReteView();
    void rimuoviContattoRete(std::string);

    void caricaCercaView();
    std::map<std::string,Utente*> cerca(std::string)const;
    void aggiungiContattoRete(std::string);

    void logoutUtente();

signals:
    void signalInserisciAbilita(QStringList);
    void signalModificaAbilita(QStringList);
    void signalEliminaAbilita(std::string);

    void signalInserisciLingua(QStringList);
    void signalModificaLingua(QStringList);
    void signalEliminaLingua(std::string);


    void signalInserisciEspProf(QStringList);
    void signalModificaEspProf(EsperienzeProfessionali::const_iterator,QStringList);
    void signalEliminaEspProf(EsperienzeProfessionali::const_iterator);

    void signalInserisciEspScol(QStringList);
    void signalModificaEspScol(EsperienzeScolastiche::const_iterator,QStringList);
    void signalEliminaEspScol(EsperienzeScolastiche::const_iterator);

    void signalModificaDatiAnag(QStringList);

    void signalRimuoviContattoRete(std::string);

    std::map<std::string,Utente*> signalCerca(std::string)const;
    void signalAggiungiContattoRete(std::string);

    void signalLogoutUtente();

};

#endif // UTENTEVIEW_H

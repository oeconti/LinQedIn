#ifndef INSERISCIUTCONTROLLER_H
#define INSERISCIUTCONTROLLER_H
#include "Model/amministratore.h"
#include "View/inserisciutview.h"

#include <QObject>

class InserisciUtController:public QObject
{
    Q_OBJECT
private:
    Amministratore* admin;
    InserisciUtView* insUtView;
public:
    InserisciUtController(Amministratore*,InserisciUtView*);
    ~InserisciUtController();

    void caricaDatabase();
    void salvaDatabase()const;
    void inserisciUt(Utente*);
private slots:
    void creaBase(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string);
    void creaBusiness(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string);
    void creaExecutive(bool,std::string,std::string,std::string,std::string,QDate,std::string,std::string,std::string,std::string);
    void utNonCreato();
signals:
    void creatoNuovoUtente(bool);
};

#endif // INSERISCIUTCONTROLLER_H

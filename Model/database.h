#ifndef DATABASE_H
#define DATABASE_H
#include <map>
#include <string>
#include <QFile>
#include <QString>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <iostream>
#include <typeinfo>
#include <QDir>

#include "Model/smartutente.h"
#include "Model/utentebase.h"
#include "Model/utenteexecutive.h"
#include "Model/utentebusiness.h"

class Database
{
private:

    static QString percorsoDbUt;
    static QString percorsoDbRete;

    std::map<std::string, SmartUtente&> listaUtenti;
    void caricaDatiAnagrafci(QXmlStreamReader&,Utente*);
    void caricaEsperienzeProfessionali(QXmlStreamReader&,Utente*);
    void caricaEsperienzeScolastiche(QXmlStreamReader&,Utente*);
    void caricaAbilitaPossedute(QXmlStreamReader&,Utente*);
    void caricaLingueParlate(QXmlStreamReader&,Utente*);
    void caricaUtente(QXmlStreamReader&,Utente*);
    void caricaRete(QXmlStreamReader&,Utente*);

    void salvaDatiUtente(std::map<std::string,SmartUtente&>::const_iterator&,QXmlStreamWriter&)const;
    void salvaDatiAnagrafici(std::map<std::string,SmartUtente&>::const_iterator&,QXmlStreamWriter&)const;
    void salvaEsperienzeProfessionali(std::map<std::string,SmartUtente&>::const_iterator&,QXmlStreamWriter&)const;
    void salvaEsperienzeScolastiche(std::map<std::string,SmartUtente&>::const_iterator&,QXmlStreamWriter&)const;
    void salvaAbilitaPossedute(std::map<std::string,SmartUtente&>::const_iterator&,QXmlStreamWriter&)const;
    void salvaLingueParlate(std::map<std::string,SmartUtente&>::const_iterator&,QXmlStreamWriter&)const;
    void salvaReteUtente(std::map<std::string,SmartUtente&>::const_iterator&,QXmlStreamWriter&)const;
public:
    Database();
    typedef std::map<std::string,SmartUtente&>::const_iterator const_iterator;
    void caricaDatabase();
    void salvaDatabase()const;

    bool inserisciUtente(Utente*);
    bool eleminaUtente(const std::string&);

    bool controllaPresenzaUsername(const std::string&)const;
    Utente* getUtente(const std::string&)const;
    SmartUtente& getSmartUtente(const std::string&)const;
    bool cambiaTipoIscrizione(const std::string&,const std::string&);
    const_iterator getDatabaseBegin()const;
    const_iterator getDatabaseEnd()const;
    int getDatabaseSize()const;

    ~Database();
};

#endif // DATABASE_H

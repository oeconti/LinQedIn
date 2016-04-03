#ifndef AMMINISTRATORE_H
#define AMMINISTRATORE_H
#include "Model/database.h"
#include <string>

class Amministratore
{
private:
    Database *ptDb;
public:
    Amministratore();
    ~Amministratore();

    void caricaDatabase();
    void salvaDatabase()const;

    bool inserisciNuovoUtente(Utente*);
    bool controllaPresenzaUsername(const std::string&)const;
    bool eliminaUtente(const std::string&);
    bool cambiaTipoUtente(const std::string&,const std::string&);

    Utente* getUtente(const std::string&)const;
    SmartUtente& getSmartUtente(const std::string&)const;
    Database::const_iterator getDatabaseBegin()const;
    Database::const_iterator getDatabaseEnd()const;
    int getDatabaseSize()const;
};

#endif // AMMINISTRATORE_H

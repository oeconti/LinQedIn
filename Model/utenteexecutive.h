#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H
#include "Model/utenteapagamento.h"
#include "Model/database.h"

class Database;

class UtenteExecutive:public UtenteAPagamento
{
private:
    class FuntoreExecutive:public Utente::FuntoreRicerca{
    public:
        FuntoreExecutive(const std::string&);
        bool operator()(Utente*)const;
    };

public:
    UtenteExecutive();
    UtenteExecutive(const Profilo&,const Login&);

    UtenteExecutive(Utente*);

    virtual std::map<std::string,Utente*> cercaUtente(Database*,const std::string&)const;
    virtual std::vector<std::string> getDescrizioneRicerca()const;
};

#endif // UTENTEEXECUTIVE_H

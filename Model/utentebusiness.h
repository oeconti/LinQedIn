#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H
#include "Model/utenteapagamento.h"

class Database;

class UtenteBusiness:public UtenteAPagamento
{
private:

    class FuntoreBusiness:public Utente::FuntoreRicerca{
    public:
        FuntoreBusiness(const std::string&);
        bool operator()(Utente*)const;
    };

public:
    UtenteBusiness();
    UtenteBusiness(const Profilo&,const Login&);
    UtenteBusiness(Utente*);

    virtual std::map<std::string,Utente*> cercaUtente(Database*,const std::string&)const;
    virtual std::vector<std::string> getDescrizioneRicerca()const;
};

#endif // UTENTEBUSINESS_H

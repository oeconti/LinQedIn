#ifndef UTENTEBASE_H
#define UTENTEBASE_H
#include "Model/utentegratis.h"

class Database;

class UtenteBase: public UtenteGratis
{
private:
    class FuntoreBase:public FuntoreRicerca{
    public:
        FuntoreBase(const std::string&);
        bool operator ()(Utente*)const;
    };

public:
    UtenteBase();
    UtenteBase(const Profilo&,const Login&);

    UtenteBase(Utente*);


    virtual std::map<std::string,Utente*> cercaUtente(Database*,const std::string&)const;
    virtual std::vector<std::string> getDescrizioneRicerca()const;
};

#endif // UTENTEBASE_H

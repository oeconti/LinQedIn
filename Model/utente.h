#ifndef UTENTE_H
#define UTENTE_H
#include <list>
#include <string>
#include <vector>
#include "Model/profilo.h"
#include "Model/login.h"
#include "Model/rete.h"


class SmartUtente;
class Database;

class Utente
{
private:
    Profilo* profilo;
    Login* login;
    Rete* rete;

protected:
    class FuntoreRicerca{
    public:
        std::vector<std::string> stringaDaCercareDivisa;

        FuntoreRicerca(const std::string&);
        //bool operator()(Utente*)const;

        static std::vector<std::string> dividiStringa(const std::string&);//restituisce un vettore contente la stringa divisa dallo spazio

    };

public:
    Utente();
    Utente(const Profilo&, const Login&);
    Utente(Utente*);//costruttore di utente in memoria condivisa,punta alle stesse profilo

    Profilo getProfilo()const;
    Login getLogin()const;

    std::string getUsername()const;
    std::string getPassword()const;
    bool getSesso()const;
    std::string getNome()const;
    std::string getCognome()const;
    QDate getDataNascita()const;
    Luogo getResidenza()const;

    EsperienzeProfessionali::const_iterator getEsperienzeProfessionaliBegin()const;
    EsperienzeProfessionali::const_iterator getEsperienzeProfessionaliEnd()const;
    int getEsperienzeProfessionaliSize()const;

    EsperienzeScolastiche::const_iterator getEsperienzeScolasticheBegin()const;
    EsperienzeScolastiche::const_iterator getEsperienzeScolasticheEnd()const;
    int getEsperienzeScolasticheSize()const;

    LingueParlate::const_iterator getLingueParlateBegin()const;
    LingueParlate::const_iterator getLingueParlateEnd()const;
    int getLingueParlateSize()const;

    AbilitaPossedute::const_iterator getAbilitaPosseduteBegin()const;
    AbilitaPossedute::const_iterator getAbilitaPosseduteEnd()const;
    int getAbilitaPosseduteSize()const;

    Rete::const_iterator getReteBegin()const;
    Rete::const_iterator getReteEnd()const;
    int getReteSize()const;

    void setSesso(const bool&);
    void setNome(const std::string &);
    void setCognome(const std::string &);
    void setDataNascita(const QDate&);
    void setResidenza(const Luogo&);
    void setUsername(const std::string&);
    void setPassword(const std::string&);

    void inserisciEsperienzaProfessionale(const EsperienzaProfessionale&);
    void setEsperienzaProfessionale(EsperienzeProfessionali::const_iterator&,const EsperienzaProfessionale&);
    void eliminaEsperienzaProfessionale(EsperienzeProfessionali::const_iterator&);

    void inserisciEsperienzaScolastica(const EsperienzaScolastica&);
    void setEsperienzaScolastica(EsperienzeScolastiche::const_iterator&,const EsperienzaScolastica&);
    void eliminaEsperienzaScolastica(EsperienzeScolastiche::const_iterator&);

    void inserisciLingua(const Lingua&);
    void setLingua(const std::string&,const Lingua&);
    void eliminaLingua(const std::string&);

    void inserisciAbilita(const Abilita&);
    void setAbilita(const std::string&,const Abilita&);
    void eliminaAbilita(const std::string&);

    void inserisciContattoRete(const std::string&,const SmartUtente&);
    void eliminaContattoRete(const std::string&);
    const SmartUtente* getContattoReteSmart(Rete::const_iterator);
    bool controllaPresenzaContattoRete(const std::string&)const;


    bool datiAnagraficiContieneStringa(const std::string&)const;
    bool abilitaPosseduteContieneStringa(const std::string&)const;
    bool espeProfessionaliContieneStringa(const std::string&)const;
    bool espeScolasticheContieneStringa(const std::string&)const;
    bool lingueParlateContieneStringa(const std::string&)const;
    bool usernameContieneStringa(const std::string&)const;

    virtual std::map<std::string,Utente*> cercaUtente(Database*,const std::string&) const =0;
    virtual std::vector<std::string> getDescrizioneRicerca() const=0;

    virtual ~Utente();

    void operator delete(void*);


};

#endif // UTENTE_H

#ifndef PROFILO_H
#define PROFILO_H
#include <string>
#include <list>
#include <vector>
#include "Model/anagrafica.h"
#include "Model/esperienzeprofessionali.h"
#include "Model/esperienzescolastiche.h"
#include "Model/lingueparlate.h"
#include "Model/abilitapossedute.h"

class Profilo
{
private:
    Anagrafica datiAnagrafici;
    EsperienzeProfessionali esperienzeProfessionali;
    EsperienzeScolastiche esperienzeScolastiche;
    LingueParlate lingueParlate;
    AbilitaPossedute abilitaPossedute;
    friend class SmartProfilo;
public:
    Profilo();
    Profilo(const bool&,const std::string&,const std::string&, const QDate&,const Luogo&);//sesso,nome,cognome,nascita,residenza

    Anagrafica getAnagrafica()const;

    bool getSesso()const;
    std::string getNome()const;
    std::string getCognome()const;
    QDate getDaNascita()const;
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


    void setAnagrafica(const Anagrafica&);
    void setSesso(const bool&);
    void setNome(const std::string &);
    void setCognome(const std::string &);
    void setDataNascita(const QDate&);
    void setResidenza(const Luogo&);

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

    bool datiAnagrafContieneStringa(const std::string&)const;
    bool abilitaPosseduteContieneStringa(const std::string&)const;
    bool espeProfessionaliContieneStringa(const std::string&)const;
    bool espeScolasticheContieneStringa(const std::string&)const;
    bool lingueParlateContieneStringa(const std::string&)const;


};

#endif // Profilo_H

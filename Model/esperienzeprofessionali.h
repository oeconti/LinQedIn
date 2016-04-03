#ifndef ESPERIENZEPROFESSIONALI_H
#define ESPERIENZEPROFESSIONALI_H
#include <list>
#include "Model/esperienzaprofessionale.h"

class EsperienzeProfessionali
{
private:
    std::list<EsperienzaProfessionale> esperienzeProfessionali;//in ordine dalla più nuova alla più vecchia
    static bool dataComparator(const Esperienza&,const Esperienza&);
public:
    EsperienzeProfessionali();
    ~EsperienzeProfessionali();

    typedef std::list<EsperienzaProfessionale>::const_iterator const_iterator;
    const_iterator getEsperienzeProfessionaliBegin()const;
    const_iterator getEsperienzeProfessionaliEnd()const;
    int getEsperienzeProfessionaliSize()const;

    void inserisciEsperienzaProfessionale(const EsperienzaProfessionale&);
    void setEsperienzaProfessionale(const_iterator&,const EsperienzaProfessionale&);
    void eliminaEsperienzaProfessionale(const_iterator&);

    bool contieneStringa(const std::string&)const;
};

#endif // ESPERIENZEPROFESSIONALI_H

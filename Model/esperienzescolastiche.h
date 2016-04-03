#ifndef ESPERIENZESCOLASTICHE_H
#define ESPERIENZESCOLASTICHE_H
#include <list>
#include "Model/esperienzascolastica.h"

class EsperienzeScolastiche
{
private:
    std::list<EsperienzaScolastica> esperienzeScolastiche;
    static bool dataComparator(const Esperienza&,const Esperienza&);
public:
    EsperienzeScolastiche();
    ~EsperienzeScolastiche();

    typedef std::list<EsperienzaScolastica>::const_iterator const_iterator;
    const_iterator getEsperienzeScolasticheBegin()const;
    const_iterator getEsperienzeScolasticheeEnd()const;
    int getEsperienzeScolasticheSize()const;

    void inserisciEsperienzaScolastica(const EsperienzaScolastica&);
    void setEsperienzaScolastica(const_iterator&,const EsperienzaScolastica&);
    void eliminaEsperinzaScolastica(const_iterator&);

    bool contieneStringa(const std::string&)const;
};

#endif // ESPERIENZESCOLASTICHE_H

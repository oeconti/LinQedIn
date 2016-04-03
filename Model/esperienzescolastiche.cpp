#include "Model/esperienzescolastiche.h"

//---------------------------------------------------------------------------------COSTRUTTORI----------------------------------------------------------------------
EsperienzeScolastiche::EsperienzeScolastiche()
{}

EsperienzeScolastiche::~EsperienzeScolastiche(){}

//----------------------------------------------------------------------------------METODI--------------------------------------------------------------------------
//Comparatore per sort della lista
bool EsperienzeScolastiche::dataComparator(const Esperienza & esp1, const Esperienza & esp2){
    return esp1.getFine()>esp2.getFine();
}
//----------------------------------------------------------------------------------Get-----------------------------------------------------------------------------
EsperienzeScolastiche::const_iterator EsperienzeScolastiche::getEsperienzeScolasticheBegin()const{
    return esperienzeScolastiche.begin();
}

EsperienzeScolastiche::const_iterator EsperienzeScolastiche::getEsperienzeScolasticheeEnd()const{
    return esperienzeScolastiche.end();
}

int EsperienzeScolastiche::getEsperienzeScolasticheSize()const{
    return esperienzeScolastiche.size();
}
//----------------------------------------------------------------------------------Set-----------------------------------------------------------------------------
void EsperienzeScolastiche::inserisciEsperienzaScolastica(const EsperienzaScolastica& esp){//desc esp
    esperienzeScolastiche.push_back(esp);
    esperienzeScolastiche.sort(EsperienzeScolastiche::dataComparator);
}

void EsperienzeScolastiche::setEsperienzaScolastica(const_iterator & const_it, const EsperienzaScolastica & esp){
    std::list<EsperienzaScolastica>::iterator it;
    it=esperienzeScolastiche.begin();
    while(it!=const_it)
        it++;
    *it=esp;
}

void EsperienzeScolastiche::eliminaEsperinzaScolastica(const_iterator & const_it){
    std::list<EsperienzaScolastica>::iterator it;
    it=esperienzeScolastiche.begin();
    while(it!=const_it)
        it++;
    esperienzeScolastiche.erase(it);
}
//--------------------------------------------------------------------------------------------------------------------
bool EsperienzeScolastiche::contieneStringa(const std::string & stringaDaCercare) const{
    bool trovato=false;
    for(const_iterator it=esperienzeScolastiche.begin();it!=esperienzeScolastiche.end() && !trovato;it++){
        if(it->contieneStringa(stringaDaCercare))
            trovato=true;
    }
    return trovato;
}

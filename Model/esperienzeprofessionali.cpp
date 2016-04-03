#include "Model/esperienzeprofessionali.h"
//----------------------------------------------------------------------------------------COSTRUTTORI------------------------------------------------------------------------------------
EsperienzeProfessionali::EsperienzeProfessionali(){}

EsperienzeProfessionali::~EsperienzeProfessionali(){}

//----------------------------------------------------------------------------------------METODI-----------------------------------------------------------------------------------------
//Comparatore per sort della lista
bool EsperienzeProfessionali::dataComparator(const Esperienza & esp1, const Esperienza & esp2){
    return esp1.getFine()>esp2.getFine();
}
//----------------------------------------------------------------------------------------Get--------------------------------------------------------------------------------------------
EsperienzeProfessionali::const_iterator EsperienzeProfessionali::getEsperienzeProfessionaliBegin()const{
    return esperienzeProfessionali.begin();
}

EsperienzeProfessionali::const_iterator EsperienzeProfessionali::getEsperienzeProfessionaliEnd()const{
    return esperienzeProfessionali.end();
}

int EsperienzeProfessionali::getEsperienzeProfessionaliSize()const{
    return esperienzeProfessionali.size();
}
//----------------------------------------------------------------------------------------Set--------------------------------------------------------------------------------------------
void EsperienzeProfessionali::inserisciEsperienzaProfessionale(const EsperienzaProfessionale& esp){
    esperienzeProfessionali.push_back(esp);
    esperienzeProfessionali.sort(EsperienzeProfessionali::dataComparator);
}

void EsperienzeProfessionali::setEsperienzaProfessionale(const_iterator & const_it, const EsperienzaProfessionale & esp){
    std::list<EsperienzaProfessionale>::iterator it=esperienzeProfessionali.begin();
    while(it!=const_it)
        it++;
    *it=esp;
}

void EsperienzeProfessionali::eliminaEsperienzaProfessionale(const_iterator & const_it){
    std::list<EsperienzaProfessionale>::iterator it=esperienzeProfessionali.begin();
    while(it!=const_it)
        it++;
    esperienzeProfessionali.erase(it);
}
//----------------------------------------------------------------------------------------------------------------
bool EsperienzeProfessionali::contieneStringa(const std::string & stringaDaCercare) const{
    bool trovato=false;
    for(const_iterator it=esperienzeProfessionali.begin();it!=esperienzeProfessionali.end() && !trovato;it++){
        if(it->contieneStringa(stringaDaCercare))
            trovato=true;
    }
    return trovato;
}

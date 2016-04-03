#include "Model/esperienzaprofessionale.h"

//-------------------------------COSTRUTTORE--------------------------------------------------------------------
EsperienzaProfessionale::EsperienzaProfessionale():nomeAzienda("Nome Azienda"),qualifica("Qualifica"){}

EsperienzaProfessionale::EsperienzaProfessionale(
        const std::string & nome,const std::string &qual,//nomeAzienda, qualifica
        const QDate& ini,//inizio esp
        const QDate& fin,//fine esp
        const Luogo& luogo,//luogoesp
        const std::string& desc)://desc esp
        Esperienza(ini,fin,luogo,desc),nomeAzienda(nome),qualifica(qual){}

//------------------------------METODI--------------------------------------------------------------------------
//------------------------------Get-----------------------------------------------------------------------------
std::string EsperienzaProfessionale::getNomeAzienda()const{
    return nomeAzienda;
}

std::string EsperienzaProfessionale::getQualifica()const{
    return qualifica;
}

//------------------------------Set----------------------------------------------------------------------------

void EsperienzaProfessionale::setNomeAzienda(const std::string &n){
    nomeAzienda=n;
}

void EsperienzaProfessionale::setQualifica(const std::string &q){
    qualifica=q;
}

bool EsperienzaProfessionale::contieneStringa(const std::string & stringaDaCercare) const{
    CercaStringa c(stringaDaCercare);
    return Esperienza::contieneStringa(stringaDaCercare) || c.cerca(nomeAzienda) || c.cerca(qualifica);
}

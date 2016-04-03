#include "Model/esperienzascolastica.h"
//-----------------------------------------COSTRUTTORI-------------------------------------------------------------------
EsperienzaScolastica::EsperienzaScolastica():nomeScuola("Nome Scuola"),gradoScuola("Grado Scuola"), titoloStudio("Titolo di Studio"){}

EsperienzaScolastica::EsperienzaScolastica(
        const std::string & nome, const std::string &grado, const std::string &titolo,//nomescuola,grado,titolostudio
        const QDate& ini,//inizioesp
        const QDate& fin,//fineesp
        const Luogo& luogo,//luogoesp
        const std::string& desc)://descrizione esp
        Esperienza(ini,fin,luogo,desc),nomeScuola(nome),gradoScuola(grado),titoloStudio(titolo){}

//-----------------------------------------METODI-----------------------------------------------------------------------
//-----------------------------------------Get--------------------------------------------------------------------------
std::string EsperienzaScolastica::getNomeScuola()const{
    return nomeScuola;
}

std::string EsperienzaScolastica::getGradoScuola()const{
    return gradoScuola;
}

std::string EsperienzaScolastica::getTitoloStudio()const{
    return titoloStudio;
}

//-----------------------------------------Set--------------------------------------------------------------------------

void EsperienzaScolastica::setNomeScuola(const std::string &n){
    nomeScuola=n;
}

void EsperienzaScolastica::setGradoScuola(const std::string &g){
    gradoScuola=g;
}

void EsperienzaScolastica::setTitoloStudio(const std::string &t){
    titoloStudio=t;
}
//---------------------------------------------------------------
bool EsperienzaScolastica::contieneStringa(const std::string & stringaDaCercare) const{
    CercaStringa c(stringaDaCercare);
    return Esperienza::contieneStringa(stringaDaCercare) || c.cerca(nomeScuola) || c.cerca(gradoScuola) || c.cerca(titoloStudio);
}

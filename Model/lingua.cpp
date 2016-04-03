#include "Model/lingua.h"

//-----------------------------------------------------------------------------COSTRUTTORI-------------------------------------------------------------------------------------------------------------
Lingua::Lingua():nomeLingua("Nessuna Lingua Inserita"),livelloCompetenzaLinguistica("Indefinito"){}

Lingua::Lingua(std::string nome, std::string livello):nomeLingua(nome),livelloCompetenzaLinguistica(livello){}

Lingua::~Lingua(){}

//------------------------------------------------------------------------------METODI-----------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------Get--------------------------------------------------------------------------------------------------------------------
std::string Lingua::getNomeLingua()const{
    return nomeLingua;
}

std::string Lingua::getLivelloCompetenzaLinguistica()const{
    return livelloCompetenzaLinguistica;
}
//------------------------------------------------------------------------------Set--------------------------------------------------------------------------------------------------------------------
void Lingua::setNomeLingua(const std::string& nome){
    nomeLingua=nome;
}

void Lingua::setLivelloCompetenzaLinguistica(const std::string & livello){
    livelloCompetenzaLinguistica=livello;
}
//-------------------------------------------------------------------------------------------
bool Lingua::contieneStringa(const std::string & stringaDaCercare) const{
    CercaStringa c(stringaDaCercare);
    return c.cerca(nomeLingua) || c.cerca(livelloCompetenzaLinguistica);
}

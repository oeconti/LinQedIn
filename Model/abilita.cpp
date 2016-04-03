#include "Model/abilita.h"
//-----------------------------------------------------------------------------COSTRUTTORI-------------------------------------------------------------------------------------------------------------
Abilita::Abilita():nomeAbilita("Nessuna abiilita inserita"),descrizioneAbilita("indefinito"){}

Abilita::Abilita(std::string nome, std::string descrizione):nomeAbilita(nome),descrizioneAbilita(descrizione){}

//------------------------------------------------------------------------------METODI-----------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------Get--------------------------------------------------------------------------------------------------------------------
std::string Abilita::getNomeAbilita()const{
    return nomeAbilita;
}

std::string Abilita::getDescrizioneAbilita()const{
    return descrizioneAbilita;
}
//------------------------------------------------------------------------------Set--------------------------------------------------------------------------------------------------------------------
void Abilita::setNomeAbilita(const std::string & nome){
    nomeAbilita=nome;
}

void Abilita::setDescrizioneAbilita(const std::string & descrizione){
    descrizioneAbilita=descrizione;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------------
bool Abilita::contieneStringa(const std::string & stringaDaCercare) const{
    CercaStringa c(stringaDaCercare);
    return c.cerca(nomeAbilita) || c.cerca(descrizioneAbilita);
}

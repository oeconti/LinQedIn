#include "cercastringa.h"

CercaStringa::CercaStringa(std::string stringa):stringaDaCercare(stringa){
    stringaToUpper(stringaDaCercare);
}

CercaStringa::~CercaStringa(){}

void CercaStringa::stringaToUpper(std::string & stringa){
    transform(stringa.begin(),stringa.end(),stringa.begin(),::toupper);
}

void CercaStringa::setStringaDaCercare(std::string stringa){
    stringaDaCercare=stringa;
}

std::string CercaStringa::getStringaDaCercare()const{
    return stringaDaCercare;
}

bool CercaStringa::cerca(std::string stringa) const{

    if(stringa.size()<stringaDaCercare.size())
        return false;
    else{
        stringaToUpper(stringa);

        std::stringstream ss(stringa);//trasformo la stringa in uno stream
        std::string tok;//token della stringa
        char delimiter=' ';//delimitatore delle parole della stringa
        bool trovato=false;
        while(getline(ss, tok, delimiter) && !trovato) {
            if(stringaDaCercare==tok)
                trovato=true;
        }

        return trovato;
    }
}


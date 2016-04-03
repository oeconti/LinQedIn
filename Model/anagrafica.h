#ifndef ANAGRAFICA_H
#define ANAGRAFICA_H
#include "Model/luogo.h"
#include "Model/cercastringa.h"

#include <QDate>
#include <string>

class Anagrafica
{
private:
    bool sesso;
    std::string nome;
    std::string cognome;
    QDate dataNascita;
    Luogo residenza;
public:
    Anagrafica();
    Anagrafica(const bool&,const std::string&,const std::string&,//sesso,nome,cognome,
               const QDate&,//datanascita
               const Luogo&);//luogo residenza

    bool getSesso()const;
    std::string getNome()const;
    std::string getCognome()const;
    QDate getDataNascita()const;
    Luogo getResidenza()const;

    void setSesso(const bool&);
    void setNome(const std::string &);
    void setCognome(const std::string &);
    void setDataNascita(const QDate&);
    void setResidenza(const Luogo&);

    bool contieneStringa(const std::string&)const;//restituisce true se nella classe anagrafica è presente la stringa passata
};

#endif // ANAGRAFICA_H

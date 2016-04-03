#ifndef ESPERIENZA_H
#define ESPERIENZA_H
#include <QDate>
#include <string>
#include "Model/luogo.h"
#include "Model/cercastringa.h"

class Esperienza
{
private:
    QDate inizio;
    QDate fine;
    Luogo locazione;
    std::string descrizione;

public:
    Esperienza();
    Esperienza(const QDate&,const QDate&,const Luogo&,const std::string&);

    QDate getInizio()const;
    QDate getFine()const;
    Luogo getLuogo()const;
    std::string getDescrizione()const;

    void setInizio(const QDate&);
    void setFine(const QDate&);
    void setLuogo(const Luogo&);
    void setDescrizione(const std::string&);

    virtual bool contieneStringa(const std::string&)const;

};

#endif // ESPERIENZA_H

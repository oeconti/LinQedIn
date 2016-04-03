#ifndef ESPERIENZASCOLASTICA_H
#define ESPERIENZASCOLASTICA_H
#include <string>
#include "Model/esperienza.h"

class EsperienzaScolastica: public Esperienza
{
private:
    std::string nomeScuola;
    std::string gradoScuola;
    std::string titoloStudio;
public:
    EsperienzaScolastica();
    EsperienzaScolastica(const std::string&,const std::string&,const std::string&,//nomeScuola,grado,titolo
                         const QDate&,//inizio
                         const QDate&,//fine
                         const Luogo&,//luogo
                         const std::string &);//descrizione

    std::string getNomeScuola()const;
    std::string getGradoScuola()const;
    std::string getTitoloStudio()const;

    void setNomeScuola(const std::string&);
    void setGradoScuola(const std::string&);
    void setTitoloStudio(const std::string&);

    bool contieneStringa(const std::string &) const;
};

#endif // ESPERIENZASCOLASTICA_H

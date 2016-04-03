#ifndef ESPERIENZAPROFESSIONALE_H
#define ESPERIENZAPROFESSIONALE_H
#include <string>
#include "Model/esperienza.h"

class EsperienzaProfessionale:public Esperienza
{
private:
    std::string nomeAzienda;
    std::string qualifica;
public:
    EsperienzaProfessionale();
    EsperienzaProfessionale(const std::string&,const std::string&,//nomeAzienda, qualifica
                            const QDate&,//inizio esp
                            const QDate&,//fine esp
                            const Luogo&,//luogo esp
                            const std::string&);//descr esp

    std::string getNomeAzienda()const;
    std::string getQualifica()const;

    void setNomeAzienda(const std::string&);
    void setQualifica(const std::string&);

    bool contieneStringa(const std::string &) const;
};

#endif // ESPERIENZAPROFESSIONALE_H

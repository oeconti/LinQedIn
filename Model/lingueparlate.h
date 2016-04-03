#ifndef LINGUEPARLATE_H
#define LINGUEPARLATE_H
#include <map>
#include "Model/lingua.h"

class LingueParlate
{
private:
    std::map<std::string,Lingua> lingueParlate;
public:
    LingueParlate();
    ~LingueParlate();

    typedef std::map<std::string,Lingua>::const_iterator const_iterator;
    const_iterator getLingueParlateBegin()const;
    const_iterator getLingueParlateEnd()const;
    int getLingueParlateSize()const;

    void inserisciLingua(const Lingua&);
    void setLingua(const std::string&,const Lingua&);
    void eliminaLingua(const std::string&);

    bool contieneStringa(const std::string&)const;
};

#endif // LINGUEPARLATE_H

#ifndef RETE_H
#define RETE_H
#include <map>
#include <string>
#include <vector>

class SmartUtente;
class Utente;

class Rete
{
private:
    std::map<std::string,const SmartUtente*> listaContatti;
public:
    Rete();
    ~Rete();

    typedef std::map<std::string,const SmartUtente*>::const_iterator const_iterator;
    const_iterator getReteBegin()const;
    const_iterator getReteEnd()const;
    int getReteSize()const;

    bool aggiungiUtente(const std::string&,const SmartUtente&);
    bool eliminaUtente(const std::string&);
    const SmartUtente* getSmartUtente(const_iterator)const;
    bool controllaPresenzaContatto(const std::string&)const;
};

#endif // RETE_H

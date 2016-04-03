#ifndef SMARTUTENTE_H
#define SMARTUTENTE_H
#include "Model/utente.h"

class SmartUtente
{
private:
    Utente *ut;
public:
    SmartUtente(Utente*);
    SmartUtente(const SmartUtente&);

    ~SmartUtente();

    SmartUtente& operator=(Utente*);
    Utente* operator->() const;
    Utente& operator *() const;
    bool operator==(const SmartUtente&)const;
    bool operator!=(const SmartUtente&)const;
};

#endif // SMARTUTENTE_H

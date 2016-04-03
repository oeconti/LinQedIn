#ifndef UTENTEGRATIS_H
#define UTENTEGRATIS_H
#include "Model/utente.h"

class UtenteGratis: public Utente
{
public:
    UtenteGratis();
    UtenteGratis(const Profilo&,const Login&);
    UtenteGratis(Utente*);

};
#endif // UTENTEGRATIS_H

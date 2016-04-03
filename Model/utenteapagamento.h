#ifndef UTENTEAPAGAMENTO_H
#define UTENTEAPAGAMENTO_H
#include "Model/utente.h"

class UtenteAPagamento: public Utente
{
public:
    UtenteAPagamento();
    UtenteAPagamento(const Profilo&, const Login&);
    UtenteAPagamento(Utente*);
};

#endif // UTENTEAPAGAMENTO_H

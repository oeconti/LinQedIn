#include "Model/utenteapagamento.h"

UtenteAPagamento::UtenteAPagamento(){}
UtenteAPagamento::UtenteAPagamento(const Profilo& info,const Login& login):Utente(info,login){}
UtenteAPagamento::UtenteAPagamento(Utente* ut):Utente(ut){}

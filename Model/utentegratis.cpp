#include "Model/utentegratis.h"

//----------------------------------------COSTRUTTORI------------------------------------------------------------------
UtenteGratis::UtenteGratis(){}
UtenteGratis::UtenteGratis(const Profilo& info,const Login& log): Utente(info,log){}
UtenteGratis::UtenteGratis(Utente* ut):Utente(ut){}
//---------------------------------------METODI-------------------------------------------------------------------------


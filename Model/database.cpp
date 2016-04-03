#include "Model/database.h"

QString Database::percorsoDbUt="../Database/database_utenti.xml";
QString Database::percorsoDbRete="../Database/database_rete.xml";


//----------------------------------------------COSTRUTTORI---------------------------------------------------------
Database::Database(){}

Database::~Database(){
    for(std::map<std::string,SmartUtente&>::iterator it=listaUtenti.begin();it!=listaUtenti.end();it++){
        delete &(it->second);
        listaUtenti.erase(it);
    }
}
//------------------------------------------METODI--------------------------------------------------------------
void Database::caricaDatiAnagrafci(QXmlStreamReader & xmlReader, Utente* ut){
    Luogo residenza;
    xmlReader.readNext();
    while(!(xmlReader.name()=="DatiAnagrafici" && xmlReader.isEndElement())){
        if(xmlReader.name()=="sesso"){
            if(xmlReader.readElementText().toStdString()=="0")
                ut->setSesso(0);
            else
                ut->setSesso(1);
            xmlReader.readNext();
        }
        else if(xmlReader.name()=="username"){
            ut->setUsername(xmlReader.readElementText().toStdString());
            xmlReader.readNext();
        }
        else if(xmlReader.name()=="password"){
            ut->setPassword(xmlReader.readElementText().toStdString());
            xmlReader.readNext();
        }
        else if(xmlReader.name()=="nome"){
            ut->setNome(xmlReader.readElementText().toStdString());
            xmlReader.readNext();
        }
        else if(xmlReader.name()=="cognome"){
            ut->setCognome(xmlReader.readElementText().toStdString());
            xmlReader.readNext();
        }
        else if(xmlReader.name()=="dataNascita"){
            ut->setDataNascita(QDate::fromString(QString::fromStdString(xmlReader.readElementText().toStdString()),"yyyy.MM.dd"));
            xmlReader.readNext();
        }
        else if(xmlReader.name()=="via"){
            residenza.setVia(xmlReader.readElementText().toStdString());
            xmlReader.readNext();
        }
        else if(xmlReader.name()=="citta"){
            residenza.setCitta(xmlReader.readElementText().toStdString());
            xmlReader.readNext();
        }
        else if(xmlReader.name()=="provincia"){
            residenza.setProvincia(xmlReader.readElementText().toStdString());
            xmlReader.readNext();
        }
        else if(xmlReader.name()=="nazione"){
            residenza.setNazione(xmlReader.readElementText().toStdString());
            xmlReader.readNext();
        }
        else{
            xmlReader.readNext();
        }
    }
    ut->setResidenza(residenza);
    xmlReader.readNext();
}

void Database::caricaEsperienzeProfessionali(QXmlStreamReader &xmlReader,Utente* ut){
    EsperienzaProfessionale esp;
    Luogo posAz;

    while (!(xmlReader.name()=="EsperienzeProfessionali" && xmlReader.isEndElement())) {
        if(xmlReader.name()=="EsperienzaProfessionale"){
            while(!(xmlReader.name()=="EsperienzaProfessionale" && xmlReader.isEndElement())){
                if(xmlReader.name()=="nomeAzienda"){
                    esp.setNomeAzienda(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="qualifica"){
                    esp.setQualifica(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="inizioEsperienza"){
                    esp.setInizio(QDate::fromString(QString::fromStdString(xmlReader.readElementText().toStdString()),"yyyy.MM.dd"));
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="fineEsperienza"){
                    esp.setFine(QDate::fromString(QString::fromStdString(xmlReader.readElementText().toStdString()),"yyyy.MM.dd"));
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="via"){
                    posAz.setVia(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="citta"){
                    posAz.setCitta(xmlReader.readElementText().toStdString());;
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="provincia"){
                    posAz.setProvincia(xmlReader.readElementText().toStdString());;
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="nazione"){
                    posAz.setNazione(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="descrizione"){
                    esp.setDescrizione(xmlReader.readElementText().toStdString());
                    esp.setLuogo(posAz);
                    ut->inserisciEsperienzaProfessionale(esp);
                    xmlReader.readNext();
                }
                else{
                    xmlReader.readNext();
                }
            }
            xmlReader.readNext();
        }
        else{
            xmlReader.readNext();
        }
    }
    xmlReader.readNext();
}

void Database::caricaEsperienzeScolastiche(QXmlStreamReader & xmlReader, Utente* ut){
    EsperienzaScolastica esp;
    Luogo posSc;

    while (!(xmlReader.name()=="EsperienzeScolastiche" && xmlReader.isEndElement())) {
        if(xmlReader.name()=="EsperienzaScolastica"){
            while(!(xmlReader.name()=="EsperienzaScolastica" && xmlReader.isEndElement())){
                if(xmlReader.name()=="nomeScuola"){
                    esp.setNomeScuola(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="gradoScuola"){
                    esp.setGradoScuola(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="titoloStudio"){
                    esp.setTitoloStudio(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="inizioEsperienza"){
                    esp.setInizio(QDate::fromString(QString::fromStdString(xmlReader.readElementText().toStdString()),"yyyy.MM.dd"));
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="fineEsperienza"){
                    esp.setFine(QDate::fromString(QString::fromStdString(xmlReader.readElementText().toStdString()),"yyyy.MM.dd"));
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="via"){
                    posSc.setVia(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="citta"){
                    posSc.setCitta(xmlReader.readElementText().toStdString());;
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="provincia"){
                    posSc.setProvincia(xmlReader.readElementText().toStdString());;
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="nazione"){
                    posSc.setNazione(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="descrizione"){
                    esp.setDescrizione(xmlReader.readElementText().toStdString());
                    esp.setLuogo(posSc);
                    ut->inserisciEsperienzaScolastica(esp);
                    xmlReader.readNext();
                }
                else{
                    xmlReader.readNext();
                }
            }
            xmlReader.readNext();
        }
        else{
            xmlReader.readNext();
        }
    }
    xmlReader.readNext();
}

void Database::caricaAbilitaPossedute(QXmlStreamReader & xmlReader, Utente * ut){
    Abilita ab;
    while (!(xmlReader.name()=="AbilitaPossedute" && xmlReader.isEndElement())) {
        if(xmlReader.name()=="Abilita"){
            while(!(xmlReader.name()=="Abilita" && xmlReader.isEndElement())){
                if(xmlReader.name()=="nomeAbilita"){
                    ab.setNomeAbilita(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="descrizioneAbilita"){
                    ab.setDescrizioneAbilita(xmlReader.readElementText().toStdString());
                    ut->inserisciAbilita(ab);
                    xmlReader.readNext();
                }
                else{
                    xmlReader.readNext();
                }
            }
            xmlReader.readNext();
        }
        else{
            xmlReader.readNext();
        }
    }
    xmlReader.readNext();
}

void Database::caricaLingueParlate(QXmlStreamReader & xmlReader, Utente * ut){
    Lingua l;
    while (!(xmlReader.name()=="LingueParlate" && xmlReader.isEndElement())) {
        if(xmlReader.name()=="Lingua"){
            while(!(xmlReader.name()=="Lingua" && xmlReader.isEndElement())){
                if(xmlReader.name()=="nomeLingua"){
                    l.setNomeLingua(xmlReader.readElementText().toStdString());
                    xmlReader.readNext();
                }
                else if(xmlReader.name()=="livelloCompetenzaLinguistica"){
                    l.setLivelloCompetenzaLinguistica(xmlReader.readElementText().toStdString());
                    ut->inserisciLingua(l);
                    xmlReader.readNext();
                }
                else{
                    xmlReader.readNext();
                }
            }
            xmlReader.readNext();
        }
        else{
            xmlReader.readNext();
        }
    }
    xmlReader.readNext();
}

void Database::caricaUtente(QXmlStreamReader& xmlReader, Utente* ut){
    while(!(xmlReader.name()=="UtenteBase" && xmlReader.isEndElement())
          && !(xmlReader.name()=="UtenteBusiness" && xmlReader.isEndElement())
          && !(xmlReader.name()=="UtenteExecutive" && xmlReader.isEndElement())){
        if(xmlReader.name()=="DatiAnagrafici"&& !xmlReader.isEndElement()){
            caricaDatiAnagrafci(xmlReader,ut);
        }
        else if(xmlReader.name()=="EsperienzeProfessionali" && !xmlReader.isEndElement()){
            caricaEsperienzeProfessionali(xmlReader,ut);
        }
        else if(xmlReader.name()=="EsperienzeScolastiche"&& !xmlReader.isEndElement()){
            caricaEsperienzeScolastiche(xmlReader,ut);
        }
        else if(xmlReader.name()=="AbilitaPossedute"&& !xmlReader.isEndElement()){
            caricaAbilitaPossedute(xmlReader,ut);
        }
        else if(xmlReader.name()=="LingueParlate"&& !xmlReader.isEndElement()){
            caricaLingueParlate(xmlReader,ut);
        }
        else{
            xmlReader.readNext();
        }
    }
}

void Database::caricaRete(QXmlStreamReader & xmlReader, Utente *ut){
    while(!(xmlReader.name()=="Utente" && xmlReader.isEndElement())){
        if(xmlReader.name()=="contatto"){
            std::map<std::string,SmartUtente&>::iterator it=listaUtenti.find(xmlReader.readElementText().toStdString());
            ut->inserisciContattoRete(it->first,it->second);
            xmlReader.readNext();
        }
        else
            xmlReader.readNext();
    }
}

void Database::caricaDatabase(){
    listaUtenti.clear();

    QDir dir("../Database/");
    if (!dir.exists()) {
        dir.mkpath(".");
    }

    QFile fileUtenti(percorsoDbUt);
    if (!fileUtenti.open(QFile::ReadOnly | QFile::Text))
        {
            std::cerr << "Error: Cannot read file " << qPrintable("database_utenti.xml")
             << ": " << qPrintable(fileUtenti.errorString())
             << std::endl;
        }
    QXmlStreamReader xmlReader;
    xmlReader.setDevice(&fileUtenti);
    while(!xmlReader.atEnd()){
        if(xmlReader.name()=="Utente" && !xmlReader.isEndElement()){
            while(!(xmlReader.name()=="Utente" && xmlReader.isEndElement())){
                if(xmlReader.name()=="UtenteBase" && !xmlReader.isEndElement()){
                    UtenteBase *ut=new UtenteBase();
                    caricaUtente(xmlReader,ut);
                    inserisciUtente(ut);
                }
                else if(xmlReader.name()=="UtenteBusiness" && !xmlReader.isEndElement()){
                    UtenteBusiness *ut=new UtenteBusiness();
                    caricaUtente(xmlReader,ut);
                    inserisciUtente(ut);
                }
                else if(xmlReader.name()=="UtenteExecutive" && !xmlReader.isEndElement()){
                    UtenteExecutive *ut=new UtenteExecutive();
                    caricaUtente(xmlReader,ut);
                    inserisciUtente(ut);
                }
                else{
                    xmlReader.readNext();
                }
            }
        }
        else{
            xmlReader.readNext();
        }
    }

    fileUtenti.close();

    QFile fileRete(percorsoDbRete);
    if (!fileRete.open(QFile::ReadOnly | QFile::Text))
        {
            std::cerr << "Error: Cannot read file " << qPrintable("database_rete.xml")
             << ": " << qPrintable(fileRete.errorString())
             << std::endl;
        }
    xmlReader.setDevice(&fileRete);
    while(!xmlReader.atEnd()){
        if(xmlReader.name()=="Utente" && !xmlReader.isEndElement()){
            while(!(xmlReader.name()=="Utente" && xmlReader.isEndElement())){
                if(xmlReader.name()=="username"){
                    std::map<std::string,SmartUtente&>::iterator it=listaUtenti.find(xmlReader.readElementText().toStdString());
                    caricaRete(xmlReader,&*(it->second));
                }
                else
                    xmlReader.readNext();
            }
        }
        else{
            xmlReader.readNext();
        }
    }
}
//------------------------------------------Salvataggio Database-------------------------------------------------------------------------
void Database::salvaDatabase()const{
    std::map<std::string,SmartUtente&>::const_iterator it;
    it=listaUtenti.begin();
    QFile fileUtenti(percorsoDbUt);
    fileUtenti.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&fileUtenti);
    xmlWriter.setAutoFormatting(true);

    QFile fileRete(percorsoDbRete);
    fileRete.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlRete(&fileRete);
    xmlRete.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlRete.writeStartDocument();
        xmlWriter.writeStartElement("Utenti");
        xmlRete.writeStartElement("Rete");
            for(unsigned int i=0;i<listaUtenti.size();i++){
                salvaDatiUtente(it,xmlWriter);
                salvaReteUtente(it,xmlRete);
                it++;
            }
        xmlRete.writeEndElement();
        xmlWriter.writeEndElement();//chiude utenti
    xmlWriter.writeEndDocument();
    xmlRete.writeEndElement();
    fileUtenti.close();
    fileRete.close();
}

void Database::salvaDatiUtente(std::map<std::string,SmartUtente&>::const_iterator & it, QXmlStreamWriter& xmlWriter)const{
    xmlWriter.writeStartElement("Utente");
    if(typeid(*it->second)==typeid(UtenteBase))
        xmlWriter.writeStartElement("UtenteBase");
    else if(typeid(*it->second)==typeid(UtenteBusiness))
        xmlWriter.writeStartElement("UtenteBusiness");
    else if(typeid(*it->second)==typeid(UtenteExecutive))
        xmlWriter.writeStartElement("UtenteExecutive");

    salvaDatiAnagrafici(it,xmlWriter);
    salvaEsperienzeProfessionali(it,xmlWriter);
    salvaEsperienzeScolastiche(it,xmlWriter);
    salvaAbilitaPossedute(it,xmlWriter);
    salvaLingueParlate(it,xmlWriter);

    xmlWriter.writeEndElement();//chiude tipo utente
    xmlWriter.writeEndElement();// chiude utente
}

void Database::salvaDatiAnagrafici(std::map<std::string,SmartUtente&>::const_iterator & it, QXmlStreamWriter & xmlWriter) const{
    xmlWriter.writeStartElement("DatiAnagrafici");
    xmlWriter.writeTextElement("username",QString::fromStdString(it->first));
    xmlWriter.writeTextElement("password",QString::fromStdString(it->second->getPassword()));
    if(it->second->getSesso())
        xmlWriter.writeTextElement("sesso","1");
    else
        xmlWriter.writeTextElement("sesso","0");
    xmlWriter.writeTextElement("nome",QString::fromStdString(it->second->getNome()));
    xmlWriter.writeTextElement("cognome",QString::fromStdString(it->second->getCognome()));
    xmlWriter.writeTextElement("dataNascita",it->second->getDataNascita().toString("yyyy.MM.dd"));
    xmlWriter.writeStartElement("Residenza");
        xmlWriter.writeTextElement("via",QString::fromStdString(it->second->getResidenza().getVia()));
        xmlWriter.writeTextElement("citta",QString::fromStdString(it->second->getResidenza().getCitta()));
        xmlWriter.writeTextElement("provincia",QString::fromStdString(it->second->getResidenza().getProvincia()));
        xmlWriter.writeTextElement("nazione",QString::fromStdString(it->second->getResidenza().getNazione()));
    xmlWriter.writeEndElement();//chiude residenza
    xmlWriter.writeEndElement();
}

void Database::salvaEsperienzeProfessionali(std::map<std::string,SmartUtente&>::const_iterator & it, QXmlStreamWriter & xmlWriter)const{
    xmlWriter.writeStartElement("EsperienzeProfessionali");
    for(EsperienzeProfessionali::const_iterator const_it=it->second->getEsperienzeProfessionaliBegin();const_it!=it->second->getEsperienzeProfessionaliEnd();const_it++){
        xmlWriter.writeStartElement("EsperienzaProfessionale");
            xmlWriter.writeTextElement("nomeAzienda",QString::fromStdString(const_it->getNomeAzienda()));
            xmlWriter.writeTextElement("qualifica",QString::fromStdString(const_it->getQualifica()));
            xmlWriter.writeTextElement("inizioEsperienza",const_it->getInizio().toString("yyyy.MM.dd"));
            xmlWriter.writeTextElement("fineEsperienza",const_it->getFine().toString("yyyy.MM.dd"));
            xmlWriter.writeStartElement("Luogo");
                xmlWriter.writeTextElement("via",QString::fromStdString(const_it->getLuogo().getVia()));
                xmlWriter.writeTextElement("citta",QString::fromStdString(const_it->getLuogo().getCitta()));
                xmlWriter.writeTextElement("provincia",QString::fromStdString(const_it->getLuogo().getProvincia()));
                xmlWriter.writeTextElement("nazione",QString::fromStdString(const_it->getLuogo().getNazione()));
            xmlWriter.writeEndElement();//chiude luogo
            xmlWriter.writeTextElement("descrizione",QString::fromStdString(const_it->getDescrizione()));
        xmlWriter.writeEndElement();//chiude esperienza
    }
    xmlWriter.writeEndElement();//chiude esperienze professionali
}

void Database::salvaEsperienzeScolastiche(std::map<std::string,SmartUtente&>::const_iterator & it, QXmlStreamWriter & xmlWriter)const{
    xmlWriter.writeStartElement("EsperienzeScolastiche");
    for(EsperienzeScolastiche::const_iterator const_it=it->second->getEsperienzeScolasticheBegin();const_it!=it->second->getEsperienzeScolasticheEnd();const_it++){
        xmlWriter.writeStartElement("EsperienzaScolastica");
            xmlWriter.writeTextElement("nomeScuola",QString::fromStdString(const_it->getNomeScuola()));
            xmlWriter.writeTextElement("gradoScuola",QString::fromStdString(const_it->getGradoScuola()));
            xmlWriter.writeTextElement("titoloStudio",QString::fromStdString(const_it->getTitoloStudio()));
            xmlWriter.writeTextElement("inizioEsperienza",const_it->getInizio().toString("yyyy.MM.dd"));
            xmlWriter.writeTextElement("fineEsperienza",const_it->getFine().toString("yyyy.MM.dd"));
            xmlWriter.writeStartElement("Luogo");
                xmlWriter.writeTextElement("via",QString::fromStdString(const_it->getLuogo().getVia()));
                xmlWriter.writeTextElement("citta",QString::fromStdString(const_it->getLuogo().getCitta()));
                xmlWriter.writeTextElement("provincia",QString::fromStdString(const_it->getLuogo().getProvincia()));
                xmlWriter.writeTextElement("nazione",QString::fromStdString(const_it->getLuogo().getNazione()));
            xmlWriter.writeEndElement();//chiude luogo
            xmlWriter.writeTextElement("descrizione",QString::fromStdString(const_it->getDescrizione()));
        xmlWriter.writeEndElement();//chiude esperienza
    }
    xmlWriter.writeEndElement(); //fine esperienze scolastiche
}

void Database::salvaAbilitaPossedute(std::map<std::string,SmartUtente&>::const_iterator & it, QXmlStreamWriter & xmlWriter)const{
    xmlWriter.writeStartElement("AbilitaPossedute");
    for(AbilitaPossedute::const_iterator const_it=it->second->getAbilitaPosseduteBegin();const_it!=it->second->getAbilitaPosseduteEnd();const_it++){
        xmlWriter.writeStartElement("Abilita");
            xmlWriter.writeTextElement("nomeAbilita",QString::fromStdString(const_it->second.getNomeAbilita()));
            xmlWriter.writeTextElement("descrizioneAbilita",QString::fromStdString(const_it->second.getDescrizioneAbilita()));
        xmlWriter.writeEndElement();//chiude abilita
    }
    xmlWriter.writeEndElement();//fine abilita possedute
}

void Database::salvaLingueParlate(std::map<std::string,SmartUtente&>::const_iterator & it, QXmlStreamWriter & xmlWriter)const{
    xmlWriter.writeStartElement("LingueParlate");
    for(LingueParlate::const_iterator const_it=it->second->getLingueParlateBegin();const_it!=it->second->getLingueParlateEnd();const_it++){
        xmlWriter.writeStartElement("Lingua");
            xmlWriter.writeTextElement("nomeLingua",QString::fromStdString(const_it->second.getNomeLingua()));
            xmlWriter.writeTextElement("livelloCompetenzaLinguistica",QString::fromStdString(const_it->second.getLivelloCompetenzaLinguistica()));
        xmlWriter.writeEndElement();//chiude lingua
    }
    xmlWriter.writeEndElement();//chiude lingueParlate
}

void Database::salvaReteUtente(std::map<std::string,SmartUtente&>::const_iterator & it, QXmlStreamWriter & xmlRete)const{
    xmlRete.writeStartElement("Utente");
    xmlRete.writeTextElement("username",QString::fromStdString(it->second->getUsername()));
        xmlRete.writeStartElement("Contatti");
        for(Rete::const_iterator const_it=it->second->getReteBegin();const_it!=it->second->getReteEnd();const_it++){
            xmlRete.writeTextElement("contatto",QString::fromStdString(const_it->first));
        }
        xmlRete.writeEndElement();//chiude contatti
    xmlRete.writeEndElement();//chiude utente
}

//-------------------------------------------------------------------------------------------------------------------------------------------

bool Database::inserisciUtente(Utente* ut){
    if(!controllaPresenzaUsername(ut->getUsername())){
        SmartUtente *smUt=new SmartUtente(ut);
        std::string user=ut->getUsername();
        listaUtenti.insert(std::pair<std::string,SmartUtente&>(user,*smUt));
        return true;
    }
    else
        return false;
}

bool Database::eleminaUtente(const std::string & username){
    if(controllaPresenzaUsername(username)){
        std::map<const std::string,SmartUtente&>::iterator it=listaUtenti.begin();
        for(;it!=listaUtenti.end();it++){
            if(it->first!=username)
                it->second->eliminaContattoRete(username);
        }
        it=listaUtenti.find(username);
        delete &(*it->second);
        listaUtenti.erase(it);

        return true;
    }
    else
        return false;
}

bool Database::controllaPresenzaUsername(const std::string & user)const{
    if(listaUtenti.count(user)>0)
        return true;
    else
        return false;
}

Utente* Database::getUtente(const std::string & username) const{
    std::map<std::string,SmartUtente&>::const_iterator it=listaUtenti.find(username);
    return &*(it->second);
}

SmartUtente& Database::getSmartUtente(const std::string& username)const{
    std::map<std::string,SmartUtente&>::const_iterator it=listaUtenti.find(username);
    return it->second;
}

bool Database::cambiaTipoIscrizione(const std::string& username,const std::string& nuovoTipo){
    std::map<std::string,SmartUtente&>::iterator it;
    it=listaUtenti.find(username);
    if(&*(it->second)){
        if(nuovoTipo=="Basic"){
            it->second=new UtenteBase(&*(it->second));
        }
        else if(nuovoTipo=="Business"){
            it->second=new UtenteBusiness(&*(it->second));
        }
        else if(nuovoTipo=="Executive"){
            it->second=new UtenteExecutive(&(*it->second));
        }
        return true;
    }
    else return false;
}

Database::const_iterator Database::getDatabaseBegin()const{
    return listaUtenti.begin();
}

Database::const_iterator Database::getDatabaseEnd()const{
    return listaUtenti.end();
}

int Database::getDatabaseSize()const{
    return listaUtenti.size();
}

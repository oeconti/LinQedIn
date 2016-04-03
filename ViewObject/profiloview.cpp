#include "profiloview.h"

ProfiloView::ProfiloView(QWidget* p,const Utente* ut):QScrollArea(p),utente(ut){
    this->setMinimumWidth(950);
    this->setObjectName("scrArea");

    this->setStyleSheet("#scrArea{background-color: white;}");
    frmScrArea=new QFrame(this);
    frmScrArea->setObjectName("Frame");
    frmScrArea->setStyleSheet("#Frame{background:transparent;}");


    QString strDatiProfilo="<h2>" + QString::fromStdString(utente->getNome()) + " " + QString::fromStdString(utente->getCognome()) + "</h2>";
    QLabel* lblDatiProfilo=new QLabel(strDatiProfilo,frmScrArea);
    lblDatiProfilo->setObjectName("lblDatiProfilo");
    lblDatiProfilo->setStyleSheet("#lblDatiProfilo{text-transform: uppercase;}");


    QString strUsername="<br/><b>Username:</b> " + QString::fromStdString(utente->getUsername());
    lblUsername=new QLabel(strUsername,frmScrArea);

    QString strDataNascita="<br/><b>Data di nascita:</b> " + utente->getDataNascita().toString("dd/MM/yyyy");
    lblDataNascita=new QLabel(strDataNascita,frmScrArea);

    QString strResidenza="<br/><b>Luogo di residenza:</b> ";
    strResidenza+=QString::fromStdString(utente->getResidenza().getCitta());
    strResidenza+= " (";
    strResidenza+= "";
    strResidenza+= QString::fromStdString(utente->getResidenza().getProvincia()) + ", " +QString::fromStdString(utente->getResidenza().getNazione()) + ")" ;
    lblResidenza=new QLabel(strResidenza,frmScrArea);

    QString strProfessioneAttuale="<br/><b>Professione attuale: </b>";
    if(utente->getEsperienzeProfessionaliSize()==0){
        strProfessioneAttuale+="Dato non inserito";
    }
    else{
        EsperienzeProfessionali::const_iterator const_it=utente->getEsperienzeProfessionaliBegin();
        if(const_it->getFine().year()==2100){
            strProfessioneAttuale+=QString::fromStdString(const_it->getQualifica());
        }
        else{
            strProfessioneAttuale+="Dato non inserito";
        }
    }
    lblProfessione=new QLabel(strProfessioneAttuale,frmScrArea);

    QString strTitoloStudio="<br/><b>Titolo di studio: </b>";
    if(utente->getEsperienzeScolasticheSize()==0){
        strTitoloStudio+="Non specificato";
    }
    else{
        EsperienzeScolastiche::const_iterator const_it=utente->getEsperienzeScolasticheBegin();
        strTitoloStudio+= QString::fromStdString(const_it->getTitoloStudio());
    }
    lblTitoloStudio=new QLabel(strTitoloStudio,frmScrArea);

    QString strLingueParlate="<br/><b>Lingue parlate: </b>";

    if(utente->getLingueParlateSize()==0){
        strLingueParlate+="Nessuna lingua inserita";
    }
    else{
        for(LingueParlate::const_iterator const_it=utente->getLingueParlateBegin();const_it!=utente->getLingueParlateEnd();const_it++){
            strLingueParlate+="<ul type=disc><li><b>Lingua: " + QString::fromStdString(const_it->second.getNomeLingua()) + "</b></li>";
            strLingueParlate+="<li>Livello: " + QString::fromStdString(const_it->second.getLivelloCompetenzaLinguistica()) + "</li></ul>";
        }
    }

    lblLingueParlate=new QLabel(strLingueParlate,frmScrArea);

    QString strEsperinzeProfessionali="<br/><b><h3>Esperienze professionali:</h3> </b>";

    if(utente->getEsperienzeProfessionaliSize()==0){
        strEsperinzeProfessionali+="Dati non inseriti";
    }
    else{
        for(EsperienzeProfessionali::const_iterator it=utente->getEsperienzeProfessionaliBegin();it!=utente->getEsperienzeProfessionaliEnd();it++){
            strEsperinzeProfessionali+="<ul type=disc>";
            strEsperinzeProfessionali+="<li><b>" + it->getInizio().toString("MM/yyyy") + " - ";
            if(it->getFine().year()== 2100)
                strEsperinzeProfessionali+="In corso</b></li>";
            else
                strEsperinzeProfessionali+=it->getFine().toString("MM/yyyy") + "</b></li>";
            strEsperinzeProfessionali+="<ul type=square><li><b>Qualifica: " + QString::fromStdString(it->getQualifica()) + "</b></li>";
            strEsperinzeProfessionali+="<li>Azienda: " + QString::fromStdString(it->getNomeAzienda()) + "</li>";
            strEsperinzeProfessionali+="<li>Luogo: " + QString::fromStdString(it->getLuogo().getCitta()) + "(" + QString::fromStdString(it->getLuogo().getProvincia()) + ", ";
            strEsperinzeProfessionali+=QString::fromStdString(it->getLuogo().getNazione()) + ")" + "</li>";


            strEsperinzeProfessionali+="<li>Descrizione: " + QString::fromStdString(it->getDescrizione()) + "</li></ul>";
            strEsperinzeProfessionali+="</ul>";
        }
    }

    lblEsperinezeProfessionali=new QLabel(strEsperinzeProfessionali,frmScrArea);

    QString strEsperienzeScolastiche="<br/><h3> Titoli di studio: </h3>";

    if(utente->getEsperienzeScolasticheSize()==0){
        strEsperienzeScolastiche+="Dati non inseriti";
    }
    else{
        for(EsperienzeScolastiche::const_iterator it=utente->getEsperienzeScolasticheBegin();it!=utente->getEsperienzeScolasticheEnd();it++){
            strEsperienzeScolastiche+="<ul type=disc>";
            strEsperienzeScolastiche+="<li><b>" + it->getInizio().toString("MM/yyyy") + " - ";
            if(it->getFine().year()== 2100)
                strEsperienzeScolastiche+="In corso";
            else
                strEsperienzeScolastiche+=it->getFine().toString("MM/yyyy") + "</b></li>";
            strEsperienzeScolastiche+="<ul type=square><li><b>Titolo:" + QString::fromStdString(it->getTitoloStudio()) + "</b></li>";
            strEsperienzeScolastiche+="<li>Istituto: " + QString::fromStdString(it->getNomeScuola()) + "</li>";
            strEsperienzeScolastiche+="<li>Luogo: " + QString::fromStdString(it->getLuogo().getCitta()) + "(" + QString::fromStdString(it->getLuogo().getProvincia()) + ", ";
            strEsperienzeScolastiche+=QString::fromStdString(it->getLuogo().getNazione()) + ")</li>";
            strEsperienzeScolastiche+="<li>Grado: " + QString::fromStdString(it->getGradoScuola()) + "</li>";
            strEsperienzeScolastiche+="<li>Descrizione: " + QString::fromStdString(it->getDescrizione()) + "</li></ul></ul>";
        }
    }

    lblEsperienzeScolastiche=new QLabel(strEsperienzeScolastiche,frmScrArea);

    QString strAbilita="<br/><b><h3>Capacità extra:</h3></b>";

    if(utente->getAbilitaPosseduteSize()==0){
        strAbilita+="Dati non inseriti";
    }
    else{
        for(AbilitaPossedute::const_iterator it=utente->getAbilitaPosseduteBegin();it!=utente->getAbilitaPosseduteEnd();it++){
            strAbilita+="<ul type=disc><li><b>" + QString::fromStdString(it->second.getNomeAbilita()) + "</b>: ";
            strAbilita+=QString::fromStdString(it->second.getDescrizioneAbilita()) + "</li></ul>";
        }
    }

    lblAbilita=new QLabel(strAbilita,frmScrArea);


    QGridLayout* gLay=new QGridLayout(frmScrArea);
    gLay->addWidget(lblDatiProfilo,0,0);
    gLay->addWidget(lblUsername,1,0);
    gLay->addWidget(lblDataNascita,4,0);
    gLay->addWidget(lblResidenza,5,0);
    gLay->addWidget(lblProfessione,6,0);
    gLay->addWidget(lblTitoloStudio,7,0);
    gLay->addWidget(lblLingueParlate,8,0);
    gLay->addWidget(lblEsperinezeProfessionali,9,0);
    gLay->addWidget(lblEsperienzeScolastiche,10,0);
    gLay->addWidget(lblAbilita,11,0);
    gLay->setSizeConstraint(QLayout::SetFixedSize);
    gLay->setContentsMargins(0,0,0,0);
    gLay->setSpacing(0);

    frmScrArea->setLayout(gLay);
    this->setWidget(frmScrArea);

    this->setWidgetResizable(true);
}

ProfiloView::~ProfiloView(){}


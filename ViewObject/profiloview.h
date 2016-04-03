#ifndef PROFILOVIEW_H
#define PROFILOVIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QString>
#include <QFrame>
#include <QGridLayout>

#include "Model/utente.h"

class ProfiloView:public QScrollArea
{
    Q_OBJECT
private:
    const Utente* utente;
    QFrame* frmScrArea;
    QLabel* lblUsername;
    QLabel* lblNome;
    QLabel* lblCogneme;
    QLabel* lblDataNascita;
    QLabel* lblResidenza;
    QLabel* lblProfessione;
    QLabel* lblTitoloStudio;
    QLabel* lblLingueParlate;
    QLabel* lblEsperinezeProfessionali;
    QLabel* lblEsperienzeScolastiche;
    QLabel* lblAbilita;
public:
    ProfiloView(QWidget*,const Utente*);
    ~ProfiloView();
};

#endif // PROFILOVIEW_H

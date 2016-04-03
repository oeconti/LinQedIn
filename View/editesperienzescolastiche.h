#ifndef EDITESPERIENZESCOLASTICHE_H
#define EDITESPERIENZESCOLASTICHE_H
#include <QDialog>
#include <QStringList>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <string>

#include "Model/esperienzescolastiche.h"
#include "ViewObject/datebox.h"
#include "ViewObject/dialogmessage.h"

class EditEsperienzeScolastiche:public QDialog
{
    Q_OBJECT
private:
    QLabel* lblInsTitoloStudio;
    QLineEdit* liEdTitoloStudio;
    QLabel* lblInsNomeScuola;
    QLineEdit* liEdNomeScuola;
    QLabel* lblInsCittaScuola;
    QLineEdit* liEdInsCittaScuola;
    QLabel* lblInsProvScuola;
    QLineEdit* liEdInsProvScuola;
    QLabel* lblInsNazScuola;
    QLineEdit* liEdNazScuola;
    QLabel* lblInsGradoScuola;
    QLineEdit* liEdGradoScuola;
    QLabel* lblDescrEspScol;
    QTextEdit* txEdDescEspScol;
    QLabel* lblDataInizioEspScol;
    QLabel* lblDataFineEspScol;
    DateBox* dataInizoEspScol;
    DateBox* dataFineEspScol;
    QCheckBox* chckEspScolCorso;
    QPushButton* btnConfermaInsEspScol;
    QPushButton* btnAnnullaInsEspScol;

    EsperienzeScolastiche::const_iterator it;

    QStringList listaEsp;
    QDate inizio;
    QDate fine;

    void creaInserisciMode();
    void creaEditMode();
    void creaLayout();
    void caricaDati();
    bool controlloDati();

public:
    EditEsperienzeScolastiche(QWidget*);
    EditEsperienzeScolastiche(QWidget *,EsperienzeScolastiche::const_iterator);
    ~EditEsperienzeScolastiche();

private slots:
    void checkBoxSetFine();
    void confermaInsEspScol();
    void confermaModEspScol();
signals:
    void signalInserisciEspScol(QStringList);
    void signalModificaEspScol(EsperienzeScolastiche::const_iterator,QStringList);
};

#endif // EDITESPERIENZESCOLASTICHE_H

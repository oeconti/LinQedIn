#ifndef EDITESPERIENZEPROFESSIONALI_H
#define EDITESPERIENZEPROFESSIONALI_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStringList>

#include "ViewObject/datebox.h"
#include "ViewObject/dialogmessage.h"
#include "Model/esperienzeprofessionali.h"

class EditEsperienzeProfessionali:public QDialog
{
    Q_OBJECT
private:
    QLabel* lblInsQualifica;
    QLineEdit* liEdInsQualifica;
    QLabel* lblInsNomeAzienda;
    QLineEdit* liEdInsNomeAzienda;
    QLabel* lblCittaEspProf;
    QLineEdit* liEdCittaEspProf;
    QLabel* lblProvEspProf;
    QLineEdit* liEdProvEspProf;
    QLabel* lblNazEspProf;
    QLineEdit* liEdNazEspProf;
    QLabel* lblDataInizioEspProf;
    DateBox* dateBoxInizioEspProf;
    QLabel* lblDataFineEspProf;
    DateBox* dateBoxFineEspProf;
    QLabel* lblDescEspProf;
    QTextEdit* txEdDescEspProf;
    QPushButton* btnAnnullaInsEspProf;
    QPushButton* btnConfermaInsEspProf;
    QCheckBox* chckEspProfCorso;

    EsperienzeProfessionali::const_iterator it;


    QStringList listaEsperienza;
    QDate dataInizio;
    QDate dataFine;

    void creaInserisciMode();
    void creaEditMode();
    void creaLayout();

    bool controlloDati();
    void caricaDati();

public:
    EditEsperienzeProfessionali(QWidget*);
    EditEsperienzeProfessionali(QWidget*,EsperienzeProfessionali::const_iterator);
    ~EditEsperienzeProfessionali();
private slots:
    void checkBoxSetFine();
    void confermaInserisici();
    void confermaModifica();
signals:
    void signalInserisciEspProf(QStringList);
    void signalModificaEspProf(EsperienzeProfessionali::const_iterator,QStringList);
};

#endif // EDITESPERIENZEPROFESSIONALI_H

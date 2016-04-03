#ifndef MODIFICAPROFILOVIEW_H
#define MODIFICAPROFILOVIEW_H
#include <QDialog>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>


class ModificaProfiloView:public QDialog
{
    Q_OBJECT
private:
    QLabel* lblSeleziona;
    QRadioButton* rdBtnDatiAnagrafici;
    QRadioButton* rdBtnLingueParlate;
    QRadioButton* rdBtnAbilita;
    QRadioButton* rdBtnEspProf;
    QRadioButton* rdBtnEspScol;
    QPushButton* btnConferma;
    QPushButton* btnAnnulla;
    void setView();
public:
    ModificaProfiloView(QWidget*);
    ~ModificaProfiloView();

private slots:
    void selezionaModifica();
signals:
    void signalModificaDatiAnagrafici();
    void signalModificaLingueParlate();
    void signalModificaEsperienzeProfessionali();
    void signalModificaEsperienzeScolastiche();
    void signalModificaAbilita();

};

#endif // MODIFICAPROFILOVIEW_H

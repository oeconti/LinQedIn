#ifndef MODIFICAESPERIENZEPROFESSIONALIVIEW_H
#define MODIFICAESPERIENZEPROFESSIONALIVIEW_H
#include <QDialog>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStringList>

#include "Model/utente.h"
#include "ViewObject/datebox.h"
#include "ViewObject/dialogmessage.h"
#include "View/editesperienzeprofessionali.h"

class ModificaEsperienzeProfessionaliView:public QDialog
{
    Q_OBJECT
private:
    Utente* utente;

    QTableWidget* tableWidgetEspProf;
    QTableWidgetItem* tableItemInizio;
    QTableWidgetItem* tableItemFine;
    QTableWidgetItem* tableItemQualifica;
    QTableWidgetItem* tableItemNomeAzienda;
    QPushButton* btnModifica;
    QPushButton* btnElimina;
    QPushButton* btnAnnulla;

    EditEsperienzeProfessionali* editEspProfV;

    QDialog* dialElimina;
    QLabel* lblConfermaElimina;
    QPushButton* btnConfermaElimina;
    QPushButton* btnAnnullaElimina;

    EsperienzeProfessionali::const_iterator getEsperienza();

public:
    ModificaEsperienzeProfessionaliView(QWidget*,Utente*);
    ~ModificaEsperienzeProfessionaliView();
private slots:
    void ModificaView();
    void confermaModifica(EsperienzeProfessionali::const_iterator,QStringList);
    void confermaElimina();
    void eliminaEsp();
signals:
    void signalModificaEspProf(EsperienzeProfessionali::const_iterator,QStringList);
    void signalEliminaEspProf(EsperienzeProfessionali::const_iterator);
};

#endif // MODIFICAESPERIENZEPROFESSIONALIVIEW_H

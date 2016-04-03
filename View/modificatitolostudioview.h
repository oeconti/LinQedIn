#ifndef MODIFICATITOLOSTUDIOVIEW_H
#define MODIFICATITOLOSTUDIOVIEW_H
#include <QDialog>
#include <QLabel>
#include <QStringList>
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
#include "View/editesperienzescolastiche.h"

class ModificaTitoloStudioView:public QDialog
{
    Q_OBJECT
private:
    Utente* utente;
    QTableWidget* tableWidgetTitoloStudio;
    QTableWidgetItem* tableItemInizio;
    QTableWidgetItem* tableItemFine;
    QTableWidgetItem* tableItemNomeScuola;
    QTableWidgetItem* tableItemTitolo;
    QPushButton* btnModifica;
    QPushButton* btnElimina;
    QPushButton* btnAnnulla;

    EditEsperienzeScolastiche* editEspScolV;

    QDialog* dialElimina;
    QLabel* lblConfermaElimina;
    QPushButton* btnConfermaElimina;
    QPushButton* btnAnnullaElimina;

    EsperienzeScolastiche::const_iterator getEsperienza();
public:
    ModificaTitoloStudioView(QWidget*,Utente*);
    ~ModificaTitoloStudioView();
private slots:
    void ModificaView();
    void confermaModifica(EsperienzeScolastiche::const_iterator,QStringList);
    void confermaElimina();
    void eliminaEspScol();
signals:
    void signalModificaEspScol(EsperienzeScolastiche::const_iterator,QStringList);
    void signalEliminaEspScol(EsperienzeScolastiche::const_iterator);
};

#endif // MODIFICATITOLOSTUDIOVIEW_H

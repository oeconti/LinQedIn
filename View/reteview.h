#ifndef RETEVIEW_H
#define RETEVIEW_H
#include <algorithm>
#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QHeaderView>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QFrame>
#include <QGroupBox>
#include <QString>
#include <string>

#include "Model/utente.h"
#include "Model/smartutente.h"
#include "ViewObject/dialogmessage.h"
#include "ViewObject/profiloview.h"

class ReteView:public QDialog
{
    Q_OBJECT
private:
    Utente* utente;

    QFrame* frmTable;
    QTableWidget* tbWcontatti;
    QTableWidgetItem* tbItUsername;
    QTableWidgetItem* tbItNome;
    QTableWidgetItem* tbItCognome;

    QGroupBox* grBoxFiltra;
    QLineEdit* liEdFiltra;
    QPushButton* btnReset;

    QGroupBox* grBoxAzioni;
    QPushButton* btnVisualizza;
    QPushButton* btnElimina;

    QGroupBox* grBoxIndietro;
    QPushButton* btnIndietro;

    QDialog* dialContatto;
    ProfiloView* profV;

    QDialog* dialElimina;
    QLabel* lblElimina;
    QPushButton* btnAnnullaElimina;
    QPushButton* btnConfermaElimina;


    void creaTabella();
    void creaFiltraBox();
    void creaAzioniBox();
    void creaIndietroBox();

    bool comparatore(std::string,std::string);
    std::string getSelectedUsername();

public:
    ReteView(QWidget*,Utente*);
    ~ReteView();

private slots:
    void filtraContatti(QString);
    void creaContattoView();
    void creaEliminaView();

    void eliminaContatto();

signals:
    void signalRimuoviContattoRete(std::string);
};

#endif // RETEVIEW_H

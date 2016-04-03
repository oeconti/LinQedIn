#ifndef CERCAVIEW_H
#define CERCAVIEW_H
#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QString>
#include <QStringList>
#include <QGridLayout>
#include <QFrame>
#include <QHeaderView>
#include <map>
#include <vector>

#include "Model/utente.h"
#include "ViewObject/dialogmessage.h"
#include "ViewObject/profiloview.h"


class CercaView:public QDialog
{
    Q_OBJECT
private:
    Utente* utente;
    std::map<std::string,Utente*> risRicerca;

    QFrame* frmTable;
    QTableWidget* tbWrisRicerca;
    QTableWidgetItem* tbItUsername;
    QTableWidgetItem* tbItNome;
    QTableWidgetItem* tbItCognome;

    QGroupBox* grBxCercaUtente;
    QLabel* lblCerca;
    QLineEdit* liEdCerca;
    QPushButton* btnCerca;

    QGroupBox* grBxTipoRicerca;
    QLabel* lblDescrizioneRicerca;

    QGroupBox* grBxVisualizzaProfilo;
    QPushButton* btnVisualizzaProfilo;
    QPushButton* btnAggiungiContatto;

    QGroupBox* grBxIndietro;
    QPushButton* btnIndietro;

    QDialog* dialContatto;
    ProfiloView* profiloV;

    void creaTabella();
    void creaCercaBox();
    void creaTipoCercaBox();
    void creaVisualizzaBox();
    void creaIndietroBox();

    std::string getSelectedUsername();
public:
    CercaView(QWidget*,Utente*);
    ~CercaView();
private slots:
    void cerca();
    void visualizzaProfilo();
    void aggiungiContatto();
signals:
    std::map<std::string,Utente*> signalCerca(std::string)const;
    void signalAggiungiContatto(std::string);
};

#endif // CERCAVIEW_H

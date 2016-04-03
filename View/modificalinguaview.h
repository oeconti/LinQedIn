#ifndef MODIFICALINGUAVIEW_H
#define MODIFICALINGUAVIEW_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <string>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QGridLayout>
#include <QHeaderView>

#include "Model/utente.h"
#include "View/editlinguaparlata.h"
#include "ViewObject/dialogmessage.h"

class ModificaLinguaView:public QDialog
{
    Q_OBJECT
private:
    Utente* utente;

    QTableWidget* tableWidgetLingue;
    QTableWidgetItem* tableItemlingua;
    QTableWidgetItem* tableItemLivLingua;
    QPushButton* btnModificaLingua;
    QPushButton* btnEliminaLingua;
    QPushButton* btnAnnulaModificheLingua;

    EditLinguaParlata* modLinguaV;

    QDialog* dialElimina;
    QLabel* lblConfermaElimina;
    QPushButton* btnConfermaElimina;
    QPushButton* btnAnnullaElimina;

    std::string getSelectedLingua();
    std::string getSelectedLivello();

public:
    ModificaLinguaView(QWidget*,Utente*);
    ~ModificaLinguaView();
private slots:
    void modificaLingua();
    void confermaModifica(QStringList);

    void eliminaLingua();
    void confermaElimina();
signals:
    void signalModificaLingua(QStringList);
    void signalEliminaLingua(std::string);
};

#endif // MODIFICALINGUAVIEW_H

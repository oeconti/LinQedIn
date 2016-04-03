#ifndef MODIFICAABITLIAVIEW_H
#define MODIFICAABITLIAVIEW_H
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QHeaderView>

#include "Model/utente.h"
#include "ViewObject/dialogmessage.h"
#include "View/editabilita.h"

class ModificaAbitliaView: public QDialog
{
    Q_OBJECT
private:
    Utente* utente;
    QTableWidget* tableWidgetAbilita;
    QPushButton* btnModifica;
    QPushButton* btnElimina;
    QPushButton* btnAnnulla;

    QTableWidgetItem* tableItemNome;
    QTableWidgetItem* tableItemDescrizione;

    QDialog* dialElimina;
    QLabel* lblConfermaElimina;
    QPushButton* btnConfermaElimina;
    QPushButton* btnAnnullaElimina;

    EditAbilita* editAbV;

    std::string getSelectedAbilita();
    std::string getSelectedDescrizione();



public:
    ModificaAbitliaView(QWidget*,Utente*);
    ~ModificaAbitliaView();
private slots:
    void modificaView();
    void confermaModifica(QStringList);

    void eliminaAbilita();
    void confermaElimina();
signals:
    void signlaModificaAbilita(QStringList);
    void signalEliminaAbilita(std::string);
};

#endif // MODIFICAABITLIAVIEW_H

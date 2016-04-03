#ifndef EDITLINGUAPARLATA_H
#define EDITLINGUAPARLATA_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStringList>
#include <string>

#include "ViewObject/dialogmessage.h"

class EditLinguaParlata:public QDialog
{
    Q_OBJECT
private:
    QLabel* lblInsLingua;
    QLabel* lblInsLivLingua;
    QLineEdit* liEdInsLingua;
    QComboBox* boxInsLivLingua;
    QPushButton* btnConfermaInsLingua;
    QPushButton* btnAnnulaInsLingua;

    std::string vLingua;
    std::string vLivello;

    std::string nLingua;
    std::string nLivello;

    QStringList listaLingua;

    void creaInserisciMode();
    void creaEditMode();
    void creaLayout();
    void caricaDati();
    bool controlloDati();

public:
    EditLinguaParlata(QWidget*);
    EditLinguaParlata(QWidget *,std::string,std::string);
    ~EditLinguaParlata();
private slots:
    void confermaInsLingua();
    void confermaModLingua();
signals:
    void signalInserisciLingua(QStringList);
    void signalModificaLingua(QStringList);
};

#endif // EDITLINGUAPARLATA_H

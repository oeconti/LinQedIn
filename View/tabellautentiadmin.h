#ifndef TABELLAUTENTIADMIN_H
#define TABELLAUTENTIADMIN_H
#include <typeinfo>
#include <QTableWidget>
#include <QStringList>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QString>
#include <string>
#include "Model/amministratore.h"

class TabellaUtentiAdmin:public QTableWidget
{
    Q_OBJECT
private:
    Amministratore* adminModel;

    void setView();
    void caricaEntryTabella();

    QTableWidgetItem* username;
    QTableWidgetItem* password;
    QTableWidgetItem* tipoUtente;

    static bool comparatore(std::string,std::string);
    std::string getTipoUtente(std::string);

public:
    TabellaUtentiAdmin(Amministratore*,QWidget *parent=0);
    ~TabellaUtentiAdmin();

    std::string getSelectedUsername()const;
    std::string getSelectedType()const;
public slots:
    void filtraUsername(QString);

};

#endif // TABELLAUTENTIADMIN_H

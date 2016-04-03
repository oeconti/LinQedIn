#ifndef DATEBOX_H
#define DATEBOX_H
#include <string>
#include <sstream>
#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QString>
#include <QHBoxLayout>
#include <QDate>
#include <sstream>

class DateBox:public QWidget{
    Q_OBJECT
private:
    QComboBox* giorno;
    QComboBox* mese;
    QComboBox* anno;
    int annoInizio;
    int annoFine;
    static void generaNumeri(QComboBox*,int,int);
    static QString intToQString(int);
public:
    DateBox(QWidget*,int,int);
    DateBox(QWidget*,int,int,QDate);
    ~DateBox();
    QDate getDate()const;

    void refresh(int,int,bool);

private slots:
    void aggiornaGiorni();
};

#endif // DATEBOX_H

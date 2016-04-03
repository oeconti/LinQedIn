#ifndef SCHERMATAINIZIALEVIEW_H
#define SCHERMATAINIZIALEVIEW_H
#include <QWidget>
#include <QApplication>
#include <QDesktopWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>


class SchermataInizialeView: public QWidget
{
    Q_OBJECT
private:
    QLabel *labelIniziale;
    QPushButton *buttonAdmin;
    QPushButton *buttonUser;

    void centraFinestra(int,int);

public:
    SchermataInizialeView();
    ~SchermataInizialeView();
private slots:
    void caricaAmministratore();
    void caricaUtente();
signals:
    void signalAmministratore();
    void signalUtente();

};

#endif // SCHERMATAINIZIALEVIEW_H

#include <QApplication>
#include "Controller/controller.h"
#include "Model/database.h"

#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller c;
    return a.exec();
}

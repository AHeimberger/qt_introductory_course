#include <QCoreApplication>
#include <QDebug>
#include "header.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        Hans hans;
        ChildOfHans childOfHans(&hans);

        qDebug() << "Has hans children?" << (hans.children().isEmpty() ? "No" : "Yes");
        qDebug() << "Has child of Hans children?" << (childOfHans.children().isEmpty() ? "No" : "Yes");
    }

    qDebug() << "";

    Hans *hans2 = new Hans();
    ChildOfHans *childOfHans2 = new ChildOfHans(hans2);

    qDebug() << "Has hans children?" << (hans2->children().isEmpty() ? "No" : "Yes");
    qDebug() << "Has child of Hans children?" << (childOfHans2->children().isEmpty() ? "No" : "Yes");
    delete hans2;

    return a.exec();
}

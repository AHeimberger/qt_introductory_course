#include <QCoreApplication>
#include "header.h"

void peopleSayHansHasSaid(const QString &value) {
    qDebug() << "people say, hans has said:" << value;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Hans hans;
    Peter peter;

    // signal - way to notify an observer that something ha happend (emit, Q_EMIT)
    // slot - function that will be executed after a signal has been emitted
    // - signals can be connect to other signals or slots
    // - many-to-many
    // - parameter types must match
    // - slot may omit any number of trailing parameters


// connecting

    // old: string based connection, still used to connecting to slots in qml
    QObject::connect(&hans, SIGNAL(hansSays(const QString &)), &peter, SLOT(hansHasSayd(const QString &)));

    // new : pointer to member functions, benefit compile time check
    QObject::connect(&hans, &Hans::hansSays, &peter, &Peter::hansHasSayd);

    // new : non member functions
    QObject::connect(&hans, &Hans::hansSays, &peopleSayHansHasSaid);

    // new : using lambdas requires c++11
    QObject::connect(&hans, &Hans::hansSays, [](const QString &value){
        qDebug() << "lambda said:" << value;
    });

    emit hans.hansSays("hello world");
    qDebug() << "";

    // if you have only c++11, thats the way how to use signal slots with overloaded functions
    QObject::connect(&hans, static_cast<void (Hans::*)(int)>(&Hans::hansOpinion), &peter,
                     static_cast<void (Peter::*)(int)>(&Peter::hansHasMultipleOpinions));
    QObject::connect(&hans, static_cast<void (Hans::*)(const QString &)>(&Hans::hansOpinion), &peter,
                     static_cast<void (Peter::*)(const QString &)>(&Peter::hansHasMultipleOpinions));

    // new : overloaded functions requires c++14, see CMakeLists.txt
    QObject::connect(&hans, qOverload<int>(&Hans::hansOpinion), &peter,
                     qOverload<int>(&Peter::hansHasMultipleOpinions));
    QObject::connect(&hans, qOverload<const QString &>(&Hans::hansOpinion), &peter,
                     qOverload<const QString &>(&Peter::hansHasMultipleOpinions));

    emit hans.hansOpinion(12);
    emit hans.hansOpinion("twelve");
    qDebug() << "";


// disconnecting signals

    QObject::disconnect(&hans, 0, 0, 0); // disconnects all signals from object
    QObject::disconnect(&hans, &Hans::hansSays, 0, 0); // disconnects only signals hansSays
    QObject::disconnect(&hans, 0, &peter, 0); // disconnects only specifi receiver
    QObject::connect(&hans, &Hans::hansSays, &peter, &Peter::hansHasSayd); // disconnects specific connection


// connecting with fifth parameter : connection type

    QObject::connect(&hans, &Hans::hansSays, &peter, &Peter::hansHasSayd, Qt::UniqueConnection);
    QObject::connect(&hans, &Hans::hansSays, &peter, &Peter::hansHasSayd, Qt::UniqueConnection);

    // although connected twice signal will only be emitted once
    emit hans.hansSays("hello world");
    qDebug() << "";


    return a.exec();
}

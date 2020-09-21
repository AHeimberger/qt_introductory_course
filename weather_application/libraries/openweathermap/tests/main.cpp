#include <QtTest>
#include <QCoreApplication>

#include "test_requests.h"
#include "test_replies.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    TestReplies testReplies;
    TestRequests testRequests;

    int status = 0;
    auto runTest = [&status, argc, argv](QObject* obj) {
        QString objectName = obj->objectName();
        qDebug() << "\nStart test:" << obj->objectName();

        QStringList arguments;
        for (int i = 0; i < argc; i++) {
            QString argument = argv[i];
            if (argument.contains(".xml")) {
                argument.replace(".xml", QString("_%1.xml").arg(objectName));
            }

            arguments.push_back(argument.toUtf8().data());
        }

        status |= QTest::qExec(obj, arguments);
    };

    runTest(&testReplies);
    runTest(&testRequests);

    return 0;
}

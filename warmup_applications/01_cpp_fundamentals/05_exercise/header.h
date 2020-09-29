#include <QObject>
#include <QDebug>

class Hans : public QObject {
    Q_OBJECT

public:
    Hans() {}

public slots:
    void onTimeout() {
        qDebug() << "hans says hello";
    }
};

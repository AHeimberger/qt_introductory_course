#include <QObject>
#include <QDebug>

class Hans: public QObject
{
    Q_OBJECT

public:
    Hans() {
        setObjectName("Hans");
        qDebug() << objectName();
    }
    ~Hans() {
        qDebug() << "~" << objectName();
    }
};


class ChildOfHans: public QObject
{
public:
    ChildOfHans(QObject *parent) {
        setParent(parent);
        setObjectName("ChildOfHans");
        qDebug() << objectName();
    }
    ~ChildOfHans() {
        qDebug() << "~" << objectName();
    }
};

#include <QObject>
#include <QDebug>

class Hans: public QObject
{
    Q_OBJECT

public:
    Hans() { setObjectName("Hans"); }
};

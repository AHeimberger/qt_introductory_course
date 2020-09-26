#include <QObject>
#include <QDebug>

class Hans: public QObject
{
    Q_OBJECT

public:
    Hans(){}

signals:
    void hansSays(const QString &someWords);

    void hansOpinion(const QString &opinion);

    void hansOpinion(int x);
};

class Peter: public QObject
{
    Q_OBJECT

public:
    Peter(){}

public slots:
    void hansHasSayd(const QString &someWords) {
        qDebug() << "hans has said:" << someWords;
    }

    void hansHasMultipleOpinions(const QString &opinion) {
        qDebug() << "overload:" << opinion;
    }

    void hansHasMultipleOpinions(int opinion) {
        qDebug() << "overload:" << opinion;
    }
};

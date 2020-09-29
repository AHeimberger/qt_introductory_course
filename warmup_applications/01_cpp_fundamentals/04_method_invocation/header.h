#include <QObject>
#include <QDebug>

class Person: public QObject
{
    Q_OBJECT

public:
    Person() {
    }

    QString getName() const { return _name; }
    uint getAge() const { return _age; }


    Q_INVOKABLE void setName(const QString &name) {
        _name = name;
    }

public slots:
    void setAge(const uint age) {
        _age = age;
    }

private:
    QString _name;
    uint _age;
};

#ifndef HEADER_H
#define HEADER_H

#include <QObject>
#include <QDebug>

class Person : public QObject {
    Q_OBJECT

    Q_PROPERTY (QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY (uint age READ getAge WRITE setAge NOTIFY ageChanged)

public:
    Person() {}
    ~Person() {}

    void setName(const QString &name) {
        if (name == _name)
            return;

        qDebug() << "setName:" << name;
        _name = name;
        emit nameChanged();
    }

    QString getName() const {
        return _name;
    }

    void setAge(const uint age) {
        if (_age == age)
            return;

        qDebug() << "setAge:" << age;
        _age = age;
        emit ageChanged();
    }

    uint getAge() const {
        return _age;
    }

signals:
    void nameChanged();
    void ageChanged();

private:
    QString _name;
    uint _age;
};

#endif // HEADER_H

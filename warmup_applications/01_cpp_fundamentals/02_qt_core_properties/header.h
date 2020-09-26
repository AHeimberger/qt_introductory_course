#include <QObject>

class Hans: public QObject
{
    Q_OBJECT

    // open via F1
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)

public:
    Hans(){}

    int getAge() {
        return _age;
    }

    void setAge(const int &age) {
        _age = age;
        emit ageChanged();
    }

signals:
    void ageChanged();

private:
    int _age = 0;
};

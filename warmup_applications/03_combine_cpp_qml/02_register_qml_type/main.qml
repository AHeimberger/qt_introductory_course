import QtQuick 2.1
import QtQuick.Window 2.12
import PersonUri 1.0

Window {
    width: 100; height: 100
    visible: true

    Person {
        id: personAnton
        name: "anton"
        age: 10
    }

    Person {
        id: personPeter
        name: "peter"
        age: 20
    }
}

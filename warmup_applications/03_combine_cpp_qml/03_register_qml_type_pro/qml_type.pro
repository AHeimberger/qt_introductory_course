QT += quick

CONFIG += c++11

CONFIG += qmltypes
QML_IMPORT_NAME = com.bbvch.qmlcomponents
QML_IMPORT_MAJOR_VERSION = 1

HEADERS += \
    myqmltype.h
SOURCES += main.cpp
RESOURCES += qml.qrc


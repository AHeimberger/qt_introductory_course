#ifndef MYQMLTYPE_H
#define MYQMLTYPE_H

#include <QQuickPaintedItem>
#include <QPainterPath>
#include <QPainter>
#include <QtQml>

class MyQmlType: public QQuickPaintedItem {
    Q_OBJECT
    QML_ELEMENT

public:
    MyQmlType(QQuickItem *parent = nullptr) : QQuickPaintedItem(parent) {}

    void paint(QPainter *painter) {
        QBrush brush(QColor("blue"));

        painter->setBrush(brush);
        painter->setPen(Qt::NoPen);
        painter->setRenderHint(QPainter::Antialiasing);

        QSizeF itemSize = size();
        painter->drawRect(0, 0, itemSize.width(), itemSize.height());
    }
};

#endif // MYQMLTYPE_H

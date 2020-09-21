#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <QString>


class QApplication;

class StyleSheet
{
public:
    StyleSheet() = default;

    bool load(const QString& file_name);

    const QString& getStyleSheet() const;

private:
    QString prepare(const QString& style_sheet);

    QString _style_sheet;
};

#endif // STYLESHEET_H

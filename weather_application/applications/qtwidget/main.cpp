#include <QApplication>
#include <QCoreApplication>
#include <QTranslator>
#include <QScreen>
#include <QDebug>
#include "main_window.h"
#include "style_sheet.h"

int main(int argc, char *argv[])
{
    qDebug() << "OpenWeatherMapp AppID:" << OPENWEATHERMAP_APPID;

    QApplication a(argc, argv);

    QTranslator* translator = new QTranslator;
    translator->load(":/translations/de.qm");
    QCoreApplication::installTranslator(translator);

    StyleSheet style_sheet;
    if (style_sheet.load(":/css/stylesheet.css")) {
        a.setStyleSheet(style_sheet.getStyleSheet());
    }

    MainWindow window;
    QRect desktop = QApplication::primaryScreen()->geometry();
    QRect window_rect(0, 0, 360, 640);
    window_rect.moveCenter(desktop.center());
    window.setGeometry(window_rect);
    window.show();

    return a.exec();
}

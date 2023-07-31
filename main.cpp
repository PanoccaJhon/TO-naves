#include "mainwindow.h"
#include "info.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TOnaves_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    Info i;
    QRect screenrect = a.primaryScreen()->geometry();
    i.move(screenrect.top(), screenrect.left());
    i.show();
    //i.hide();

    Info i2;

    i2.move(screenrect.top(), screenrect.left());
    i2.show();
    i2.hide();
    return a.exec();
}

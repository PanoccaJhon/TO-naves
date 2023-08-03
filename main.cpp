#include "mainwindow.h"
#include "info.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <SFML/Audio.hpp>

int main(int argc, char *argv[])
{
    sf::Music music;
    if (!music.openFromFile("D:/master/TO_naves_master/Sonidos/music.ogg"))
    {
        // Manejo de error si no se pudo cargar el archivo de música
        return 1;
    }
    music.setLoop(true);
    music.setVolume(20);
    music.play();

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
    return a.exec();
}

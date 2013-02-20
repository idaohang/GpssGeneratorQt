#include <QApplication>
#include <QTranslator>
#include <QMessageBox>

#include "mainwindow.h"

using GeneratorGpss::MainWindow;

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load("qt_en");
    a.installTranslator(&qtTranslator);

    QTranslator myTranslator;
    myTranslator.load("GeneratorGpssQt_en",a.applicationDirPath());

    a.installTranslator(&myTranslator);

    MainWindow w;
    w.show();
    return a.exec();
}

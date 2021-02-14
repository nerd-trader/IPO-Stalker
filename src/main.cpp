#include <QApplication>

#include "mainwindow.hpp"
#include "runguard.hpp"
#include "data-sources/ipo-cal-appspot.hpp"

#define UNIQUE_STRING "9SzFd77+9Nljvv73TqO"

QString getUserName()
{
    QString name = qgetenv("USER");

    if (name.isEmpty()) {
        name = qgetenv("USERNAME");
    }

    return name;
}

int main(int argc, char **argv)
{
    RunGuard guard(TARGET "-" UNIQUE_STRING "-" + getUserName());

    if (!guard.tryToRun()) {
        return 1;
    }

    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    IpoCalAppSpot *dataSourceJapan = new IpoCalAppSpot();

    dataSourceJapan->query();

    return a.exec();
}

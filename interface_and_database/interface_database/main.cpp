#include "mainwindow_db.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow_db w;
    w.show();
    //write(serial_port, "s", sizeof(char));
    return a.exec();
}

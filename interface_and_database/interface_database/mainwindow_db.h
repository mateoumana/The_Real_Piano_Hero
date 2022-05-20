#ifndef MAINWINDOW_DB_H
#define MAINWINDOW_DB_H

#include <QMainWindow>
#include <QProcess>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <iostream>
#include <unistd.h>
#include <string>
#include "tty_lib2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_db; }
QT_END_NAMESPACE

class MainWindow_db : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_db(QWidget *parent = nullptr);
    ~MainWindow_db();

private slots:
    void on_add_clicked();

    void on_find_clicked();

    void on_play_clicked();

private:
    Ui::MainWindow_db *ui;
};
#endif // MAINWINDOW_DB_H

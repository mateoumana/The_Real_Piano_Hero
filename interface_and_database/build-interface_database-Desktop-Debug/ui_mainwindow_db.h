/********************************************************************************
** Form generated from reading UI file 'mainwindow_db.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_DB_H
#define UI_MAINWINDOW_DB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_db
{
public:
    QWidget *centralwidget;
    QTextEdit *window_name;
    QPushButton *add;
    QTextEdit *window_carnet;
    QTextEdit *find_carnet;
    QPushButton *find;
    QLabel *label;
    QLabel *carnet;
    QLabel *name;
    QLabel *score;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *name_db;
    QTextEdit *carnet_db;
    QTextEdit *score_db;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_6;
    QLabel *label_8;
    QFrame *line_7;
    QPushButton *play;
    QTextEdit *player_carnet;
    QLabel *label_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_db)
    {
        if (MainWindow_db->objectName().isEmpty())
            MainWindow_db->setObjectName(QString::fromUtf8("MainWindow_db"));
        MainWindow_db->resize(530, 419);
        centralwidget = new QWidget(MainWindow_db);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        window_name = new QTextEdit(centralwidget);
        window_name->setObjectName(QString::fromUtf8("window_name"));
        window_name->setGeometry(QRect(20, 60, 171, 31));
        add = new QPushButton(centralwidget);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(340, 60, 89, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Dyuthi"));
        font.setPointSize(13);
        font.setBold(true);
        font.setItalic(true);
        add->setFont(font);
        add->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(85, 87, 83);"));
        window_carnet = new QTextEdit(centralwidget);
        window_carnet->setObjectName(QString::fromUtf8("window_carnet"));
        window_carnet->setGeometry(QRect(213, 60, 111, 31));
        find_carnet = new QTextEdit(centralwidget);
        find_carnet->setObjectName(QString::fromUtf8("find_carnet"));
        find_carnet->setGeometry(QRect(30, 270, 151, 31));
        find = new QPushButton(centralwidget);
        find->setObjectName(QString::fromUtf8("find"));
        find->setGeometry(QRect(190, 270, 89, 31));
        find->setFont(font);
        find->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 250, 201, 21));
        label->setFont(font);
        carnet = new QLabel(centralwidget);
        carnet->setObjectName(QString::fromUtf8("carnet"));
        carnet->setGeometry(QRect(30, 310, 91, 17));
        carnet->setFont(font);
        name = new QLabel(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(150, 310, 141, 17));
        name->setFont(font);
        score = new QLabel(centralwidget);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(340, 310, 171, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Dyuthi"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(true);
        score->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 131, 17));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 40, 67, 17));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 10, 241, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Dyuthi"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setItalic(true);
        label_4->setFont(font2);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(150, 210, 251, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Dyuthi"));
        font3.setPointSize(17);
        font3.setBold(true);
        font3.setItalic(true);
        label_5->setFont(font3);
        name_db = new QTextEdit(centralwidget);
        name_db->setObjectName(QString::fromUtf8("name_db"));
        name_db->setGeometry(QRect(150, 330, 171, 31));
        carnet_db = new QTextEdit(centralwidget);
        carnet_db->setObjectName(QString::fromUtf8("carnet_db"));
        carnet_db->setGeometry(QRect(30, 330, 111, 31));
        score_db = new QTextEdit(centralwidget);
        score_db->setObjectName(QString::fromUtf8("score_db"));
        score_db->setGeometry(QRect(340, 330, 171, 31));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 90, 511, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(10, 360, 511, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(10, 0, 511, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 10, 20, 361));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(509, 10, 31, 361));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 10, 511, 361));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/piano_flame2.jpg")));
        label_6->setScaledContents(true);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(390, 100, 131, 111));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/piano_hero.jpeg")));
        label_7->setScaledContents(true);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(10, 370, 511, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 140, 241, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Dyuthi"));
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setItalic(true);
        label_8->setFont(font4);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(30, 200, 511, 20));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        play = new QPushButton(centralwidget);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(290, 160, 89, 31));
        play->setFont(font);
        play->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"color: rgb(255, 255, 255);"));
        player_carnet = new QTextEdit(centralwidget);
        player_carnet->setObjectName(QString::fromUtf8("player_carnet"));
        player_carnet->setGeometry(QRect(30, 160, 241, 31));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(130, 100, 251, 41));
        label_9->setFont(font3);
        MainWindow_db->setCentralWidget(centralwidget);
        label_6->raise();
        window_name->raise();
        add->raise();
        window_carnet->raise();
        find_carnet->raise();
        find->raise();
        label->raise();
        carnet->raise();
        name->raise();
        score->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        name_db->raise();
        carnet_db->raise();
        score_db->raise();
        line->raise();
        line_2->raise();
        line_3->raise();
        line_4->raise();
        line_5->raise();
        label_7->raise();
        line_6->raise();
        label_8->raise();
        line_7->raise();
        play->raise();
        player_carnet->raise();
        label_9->raise();
        menubar = new QMenuBar(MainWindow_db);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 530, 22));
        MainWindow_db->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_db);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow_db->setStatusBar(statusbar);

        retranslateUi(MainWindow_db);

        QMetaObject::connectSlotsByName(MainWindow_db);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_db)
    {
        MainWindow_db->setWindowTitle(QApplication::translate("MainWindow_db", "MainWindow_db", nullptr));
        add->setText(QApplication::translate("MainWindow_db", "A\303\261adir", nullptr));
        find->setText(QApplication::translate("MainWindow_db", "Buscar", nullptr));
        label->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p><span style=\" color:#efefef;\">C\303\263digo de carnet a buscar</span></p></body></html>", nullptr));
        carnet->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p><span style=\" color:#efefef;\">No. Carnet</span></p></body></html>", nullptr));
        name->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p><span style=\" color:#efefef;\">Nombre y apellido</span></p></body></html>", nullptr));
        score->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p><span style=\" color:#efefef;\">Puntaje (notas acertadas)</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p><span style=\" color:#efefef;\">Nombre y apellido</span></p></body></html>", nullptr));
        label_3->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p><span style=\" color:#efefef;\">Carnet</span></p></body></html>", nullptr));
        label_4->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p><span style=\" color:#0a2797;\">Inscripci\303\263n de participantes</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p><span style=\" color:#0a2797;\">Consulta de participantes</span></p></body></html>", nullptr));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p><span style=\" color:#efefef;\">Carnet de participante a jugar</span></p></body></html>", nullptr));
        play->setText(QApplication::translate("MainWindow_db", "Jugar", nullptr));
        label_9->setText(QApplication::translate("MainWindow_db", "<html><head/><body><p align=\"center\"><span style=\" color:#0a2797;\">Jugador</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_db: public Ui_MainWindow_db {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_DB_H

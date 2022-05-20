#include "mainwindow_db.h"
#include "ui_mainwindow_db.h"
#include "tty_lib2.h"
#define BAUD_RATE B9600

MainWindow_db::MainWindow_db(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_db)
{
    ui->setupUi(this);
    ui->name_db->setReadOnly(true);
    ui->carnet_db->setReadOnly(true);
    ui->score_db->setReadOnly(true);

}

MainWindow_db::~MainWindow_db()
{
    delete ui;
}

QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

void MainWindow_db::on_add_clicked()
{
    QString ruta_db = "/home/umana/Documentos/sysd/proyect/db_participants.db";

    db.setDatabaseName(ruta_db);
    db.open();

    QSqlQuery consulta;

    qDebug() << ui->window_carnet->toPlainText();

    //las columnas de la database son: carnet (text)| name (text)| score (integer)
    consulta.exec("INSERT INTO participants (carnet, name, score) VALUES ('" + ui->window_carnet->toPlainText() + "', '" + ui->window_name->toPlainText() + "', 0)");

    db.close();

    ui->window_carnet->clear();
    ui->window_name->clear();
}

void MainWindow_db::on_find_clicked()
{
    ui->carnet_db->clear();
    ui->name_db->clear();
    ui->score_db->clear();
    QString ruta_db = "/home/umana/Documentos/sysd/proyect/db_participants.db";

    db.setDatabaseName(ruta_db);
    db.open();

    QSqlQuery consulta;

    qDebug() << ui->find_carnet->toPlainText();
    //las columnas de la database son: carnet (text)| name (text)| score (integer)
    consulta.exec("SELECT * FROM participants WHERE carnet = " + ui->find_carnet->toPlainText());
    while (consulta.next()) {
        ui->carnet_db->append(consulta.value(0).toString());
        ui->name_db->append(consulta.value(1).toString());
        ui->score_db->append(consulta.value(2).toString());
    }
    db.close();
    ui->find_carnet->clear();//Borrar el texto del nombre de la db
}


void MainWindow_db::on_play_clicked() //remplaza el boton del arduino
{
    int serial_port, num_bytes;
    struct termios tty;
    char read_buf;
    int score;

    config_tty ("/dev/ttyACM0", &tty, BAUD_RATE, &serial_port);
    sleep(5);
    write(serial_port, "w", sizeof(char));
    sleep(1);
    num_bytes = read(serial_port, &read_buf, sizeof(read_buf));     //read_buf contiene el caracter recibido por rx

    while(read_buf == 'P'){//P = esta jugando, N = libre el arduino
        num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
    }
    while(read_buf == 'N'){ //esperar a que el puerto serial envie el score del participante que jugó
        num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
    }

    QString ruta_db = "/home/umana/Documentos/sysd/proyect/db_participants.db";

    db.setDatabaseName(ruta_db);
    db.open();

    QSqlQuery consulta;
    score = int(read_buf);
    qDebug() << score;
    //las columnas de la database son: carnet (text)| name (text)| score (integer)
    consulta.exec("UPDATE participants SET score = " + QString("%1").arg(score,0) + " WHERE carnet = '" + ui->player_carnet->toPlainText() + "'");
    //QString("%1").arg(score,0): se hace para que QString no pase score a hexa
    db.close();
    //::close(serial_port);
    ui->player_carnet->clear();//Borrar el texto del carnet del jugardor actual
}


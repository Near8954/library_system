#include "secondinputform.h"
#include "ui_secondinputform.h"
#include <mainwindow.h>
#include "QSql"
//#include <MainWindow>
//#include ‹QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
//#include "QSQLite"


SecondInputForm::SecondInputForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondInputForm)
{
    ui->setupUi(this);
    // QString path;
    // #ifdef __APPLE__
    // path = "/Users/ker1l/library_system/main.db";
    // #else
    // path = "./../library_system/main.db";
    // #endif

    // db = QSqlDatabase::addDatabase("QSQLITE");
    // //setStyleSheet(MainWindow->mainwindow{rgb: 55 55 55});
    // db.setDatabaseName(path);
    // if (db.open()) {
    //     qDebug("open");
    // } else {
    //     qDebug("not open");
    // }
    q = new QSqlQuery(db);
    // students = new QSqlTableModel(this, db);
    // students->setTable("students");
    // students->select();
}

SecondInputForm::~SecondInputForm()
{
    delete ui;
}


void SecondInputForm::on_pushButton_clicked()
{
    q->exec("INSERT INTO students VALUES(16, 'a', 'a', 'a', '1');");
    // QString a = ui->comboBox->currentText();
    // q->exec("INSERT INTO students(1, 'a', 'a', 'a', '1');");

    close();
}


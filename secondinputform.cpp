#include "secondinputform.h"
#include "ui_secondinputform.h"
#include <mainwindow.h>
#include "QSql"
//#include <MainWindow>
//#include ‹QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
//#include "QSQLite"

using namespace std;

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


long long id = 5;

void SecondInputForm::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString last_name = ui->lineEdit_2->text();
    QString middle_name = ui->lineEdit_3->text();

    q->prepare("INSERT INTO students VALUES(?, ?, ?, ?, '1');");
    //q->prepare("INSERT INTO ")
    q->addBindValue(id++);
    q->addBindValue(name);
    q->addBindValue(last_name);
    q->addBindValue(middle_name);
    q->exec();
    close();
}


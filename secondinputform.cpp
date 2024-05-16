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
    q = new QSqlQuery(db);
}

SecondInputForm::~SecondInputForm()
{
    delete ui;
}




void SecondInputForm::on_pushButton_clicked()
{
    QString name = ui->lineEdit_2->text();
    name = name.toLower();
    QString tmp = name;
    name[0] = tmp[0].toUpper();
    QString last_name = ui->lineEdit->text();
    tmp = last_name;
    last_name[0] = tmp[0].toUpper();
    QString middle_name = ui->lineEdit_3->text();
    tmp = middle_name;
    middle_name[0] = tmp[0].toUpper();
    QString grade = ui->lineEdit_4->text();

    q->prepare("INSERT INTO students (last_name, name, middle_name, grade) VALUES(?, ?, ?, ?);");

    q->addBindValue(name);
    q->addBindValue(last_name);
    q->addBindValue(middle_name);
    q->addBindValue(grade);
    q->exec();
    close();
}


#include "bookinputform.h"
#include "ui_bookinputform.h"
#include <mainwindow.h>
#include <QDebug>
#include <QSqlQuery>

BookInputForm::BookInputForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BookInputForm)
{
    ui->setupUi(this);
    q = new QSqlQuery(db);
}

BookInputForm::~BookInputForm()
{
    delete ui;
}

int64_t book_id = 5;

void BookInputForm::on_pushButton_clicked()
{
    QString author_name = ui->lineEdit->text();
    QString book_name = ui->lineEdit_2->text();
    QString jenre = ui->lineEdit_3->text();
    QString type = ui->lineEdit_4->text();
    QString publisher = ui->lineEdit_5->text();
    QString number = ui->lineEdit_6->text();
    q->prepare("INSERT INTO books VALUES(?, ?, ?, ?, ?, ?, ?);");
    q->addBindValue(book_id++);
    q->addBindValue(number.toInt());
    q->addBindValue(author_name);
    q->addBindValue(book_name);
    q->addBindValue(type);
    q->addBindValue(jenre);
    q->addBindValue(publisher);
    q->exec();
    close();
}


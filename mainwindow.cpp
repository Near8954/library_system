#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../library_system/main.db");
    if (db.open()) {
        qDebug("open");
    } else {
        qDebug("not open");
    }
    q = new QSqlQuery(db);
    operations = new QSqlTableModel(this, db);
    operations->setTable("operations");
    operations->select();
    students = new QSqlTableModel(this, db);
    students->setTable("students");
    students->select();
    books = new QSqlTableModel(this, db);
    books->setTable("books");
    books->select();
    ui->tableView->setModel(operations);
    ui->tableView_2->setModel(students);
    ui->tableView_3->setModel(books);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    operations->insertRow(operations->rowCount());
}


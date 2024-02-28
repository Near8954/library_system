#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputform.h"
#include "QComboBox"
#include "qcombobox.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString path;
    #ifdef __APPLE__
    path = "/Users/ker1l/library_system/main.db";
    #else
    path = "./../library_system/main.db";
    #endif

    db = QSqlDatabase::addDatabase("QSQLITE");
    //setStyleSheet(MainWindow->mainwindow{rgb: 55 55 55});
    db.setDatabaseName(path);
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
    InputForm form;
    form.setModal(true);
    form.exec();
}


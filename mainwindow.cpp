#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputform.h"
#include "bookinputform.h"
#include "QComboBox"
#include "qcombobox.h"
#include "secondinputform.h"
#include "iostream"
#include "QInputDialog"
#include "QMessageBox"
#include "QDir"

using namespace std;




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


void MainWindow::on_pushButton_3_clicked()
{

    SecondInputForm form;
    form.setModal(true);
    form.exec();
    students->select();

}



void MainWindow::on_pushButton_clicked()
{
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Введите id ученика:"), QLineEdit::Normal);

    if (true) {
        q->prepare("DELETE FROM students WHERE id = ?");
        q->addBindValue(text.toInt());
        q->exec();
        students->select();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Некорректный id");
        msgBox.exec();
    }

}


void MainWindow::on_pushButton_4_clicked()
{
    BookInputForm form;
    form.setModal(true);
    form.exec();
    books->select();
}


void MainWindow::on_pushButton_5_clicked()
{
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Введите id книги:"), QLineEdit::Normal);
    if (true) {
        q->prepare("DELETE FROM books WHERE id = ?");
        q->addBindValue(text.toInt());
        q->exec();
        books->select();
    } else {
        QMessageBox msgBox;
        msgBox.setText("Некорректный id");
        msgBox.exec();
    }
}


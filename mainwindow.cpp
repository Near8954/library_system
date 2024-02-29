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

    setStyleSheet("QMainWindow {background-color: rgb(255, 240, 239)}, QTabWidget {text-color: rgb(0, 0, 0)}");

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
    operations->setHeaderData(2, Qt::Horizontal, "Действие");
    students = new QSqlTableModel(this, db);
    students->setTable("students");
    students->select();
    students->setHeaderData(1, Qt::Horizontal, "Фамилия");
    students->setHeaderData(2, Qt::Horizontal, "Имя");
    students->setHeaderData(3, Qt::Horizontal, "Отчество");
    students->setHeaderData(4, Qt::Horizontal, "Класс");
    books = new QSqlTableModel(this, db);
    books->setTable("books");
    books->select();
    books->setHeaderData(1, Qt::Horizontal, "Количество");
    books->setHeaderData(2, Qt::Horizontal, "Автор");
    books->setHeaderData(3, Qt::Horizontal, "Название");
    books->setHeaderData(4, Qt::Horizontal, "Тип");
    books->setHeaderData(5, Qt::Horizontal, "Жанр");
    books->setHeaderData(6, Qt::Horizontal, "Издательство");
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


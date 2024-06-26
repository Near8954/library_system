#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <cstdlib>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE

class QCloseEvent;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_delete_operation_clicked();

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event);
    QSqlDatabase db;
    QSqlQuery *q;
    QSqlTableModel *operations;
    QSqlTableModel *students;
    QSqlTableModel *books;

};

#endif // MAINWINDOW_H

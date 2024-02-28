#ifndef SECONDINPUTFORM_H
#define SECONDINPUTFORM_H

#include <QDialog>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <cstdlib>

namespace Ui {
class SecondInputForm;
}

class SecondInputForm : public QDialog
{
    Q_OBJECT

public:
    explicit SecondInputForm(QWidget *parent = nullptr);
    ~SecondInputForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecondInputForm *ui;
    QSqlDatabase db;
    QSqlQuery *q;

    QSqlTableModel *students;

};

#endif // SECONDINPUTFORM_H

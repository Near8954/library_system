#ifndef BOOKINPUTFORM_H
#define BOOKINPUTFORM_H

#include <QDialog>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <cstdlib>

namespace Ui {
class BookInputForm;
}

class BookInputForm : public QDialog
{
    Q_OBJECT

public:
    explicit BookInputForm(QWidget *parent = nullptr);
    ~BookInputForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BookInputForm *ui;
    QSqlDatabase db;
    QSqlQuery *q;
    QSqlTableModel *books;
};

#endif // BOOKINPUTFORM_H

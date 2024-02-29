#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QDialog>
#include <QCompleter>
#include "QKeyEvent"
#include "QComboBox"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <cstdlib>

namespace Ui {
class InputForm;
}

class InputForm : public QDialog
{
    Q_OBJECT

public:
    explicit InputForm(QWidget *parent = nullptr);
    ~InputForm();

private slots:

    void on_pushButton_clicked();

private:
    Ui::InputForm *ui;
    QSqlDatabase db;
    QSqlQuery *q;
    QSqlTableModel *operations;
    QSqlTableModel *students;
    QSqlTableModel *books;

};

#endif // INPUTFORM_H

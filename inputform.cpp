#include "inputform.h"
#include "ui_inputform.h"
#include "QKeyEvent"
#include "QCompleter"
#include "QAbstractProxyModel"
#include "QIdentityProxyModel"
#include "QSortFilterProxyModel"
#include "QSqlQueryModel"
#include "QTableView"


InputForm::InputForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputForm)
{
    ui->setupUi(this);
    q = new QSqlQuery(db);

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT id, last_name, name, middle_name, grade FROM students");
    model->setHeaderData(0, Qt::Horizontal, tr("id"));
    model->setHeaderData(1, Qt::Horizontal, tr("last_name"));
    model->setHeaderData(2, Qt::Horizontal, tr("name"));
    model->setHeaderData(3, Qt::Horizontal, tr("middle_name"));
    model->setHeaderData(4, Qt::Horizontal, tr("grade"));
    QTableView *view = new QTableView;
    ui->comboBox->setModel(model);
    ui->comboBox->setView(view); //Переносим данные из studets в combobox

    QSqlQueryModel *model2 = new QSqlQueryModel;
    model2->setQuery("SELECT id, author, name, genre, publisher FROM books");
    model2->setHeaderData(0, Qt::Horizontal, tr("id"));
    model2->setHeaderData(1, Qt::Horizontal, tr("author"));
    model2->setHeaderData(2, Qt::Horizontal, tr("name"));
    model2->setHeaderData(3, Qt::Horizontal, tr("genre"));
    model2->setHeaderData(4, Qt::Horizontal, tr("publisher"));
    QTableView *view2 = new QTableView;
    ui->comboBox_2->setModel(model2);
    ui->comboBox_2->setView(view2); //Перносим данные из books в combobox

}

InputForm::~InputForm()
{
    delete ui;
}

// void InputForm::on_lineEdit_customContextMenuRequested(const QPoint &pos)
// {

// }

// void MyComboBox::addEntry(QString loginName, QString name)
// {
//     addItem(loginName);
//     // Store the name in a member variable, eg a map between names and login names
//     namesMap.insert(name, loginName);
// }

void QComboBox::keyPressEvent(QKeyEvent *e)
{

}

void InputForm::on_pushButton_clicked()
{
    QString a = ui->comboBox->currentText();
    QString b = ui->comboBox_2->currentText();
    QString c = ui->comboBox_3->currentText();
    if (c == "Книга возвращена") {
        q->prepare("INSERT INTO operations (book_id, status, student_id) VALUES (?, ?, ?)");
        q->addBindValue(a.toInt());
        q->addBindValue(c);
        q->addBindValue(b.toInt());
//        int n = q->prepare("SELECT number FROM books WHERE id = ?");
//        q->addBindValue(b.toInt());
//        q->exec();
//        q->prepare("UPDATE books SET number = ? WHERE id = ?");
//        q->addBindValue(n + 1);
//        q->addBindValue(b.toInt());
        q->exec();
        close();
    } else {
        q->prepare("INSERT INTO operations (book_id, status, student_id) VALUES (?, ?, ?)");
        q->addBindValue(a.toInt());
        q->addBindValue(c);
        q->addBindValue(b.toInt());
//        int n = q->prepare("SELECT number FROM books WHERE id = ?");
//        q->addBindValue(b.toInt());
//        q->exec();
//        q->prepare("UPDATE books SET number = ? WHERE id = ?");
//        q->addBindValue(n - 1);
//        q->addBindValue(b.toInt());
        q->exec();
        close();
    }
}


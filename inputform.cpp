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


    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT last_name, name, middle_name, grade, id FROM students");

    model->setHeaderData(0, Qt::Horizontal, tr("last_name"));
    model->setHeaderData(1, Qt::Horizontal, tr("name"));
    model->setHeaderData(2, Qt::Horizontal, tr("middle_name"));
    model->setHeaderData(3, Qt::Horizontal, tr("grade"));
    model->setHeaderData(4, Qt::Horizontal, tr("id"));
    // model->setHeaderData(2, Qt::Horizontal, tr("middle_name"));
    // model->setHeaderData(3, Qt::Horizontal, tr("id"));

    QTableView *view = new QTableView;

    //QComboBox *cb = new QComboBox();
    ui->comboBox->setModel(model);
    ui->comboBox->setView(view);

    // QSortFilterProxyModel proxyModel = new

    // QCompleter *mycompletear = new QCompleter(this);
    // mycompletear->setCaseSensitivity(Qt::CaseInsensitive);
    // //mycompletear->setModel(proxyModel);
    // mycompletear->setCompletionColumn(1);
    // mycompletear->setCompletionMode(QCompleter::UnfilteredPopupCompletion);
    // ui->comboBox->setCompleter(mycompletear);
    //ui->comboBox->setCompleter(InlineCompletion);
    //QComboBox->comboBox->addItems({ "one", "two", "three", "four" });
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

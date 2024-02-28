#include "inputform.h"
#include "ui_inputform.h"
#include "QKeyEvent"
#include "QCompleter"
#include "QAbstractProxyModel"
#include "QIdentityProxyModel"
#include "QSortFilterProxyModel"
#include "QSqlQueryModel"



InputForm::InputForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputForm)
{
    ui->setupUi(this);

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

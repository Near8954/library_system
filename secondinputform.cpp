#include "secondinputform.h"
#include "ui_secondinputform.h"

SecondInputForm::SecondInputForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SecondInputForm)
{
    ui->setupUi(this);
}

SecondInputForm::~SecondInputForm()
{
    delete ui;
}

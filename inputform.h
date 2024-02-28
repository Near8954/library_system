#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QDialog>
#include <QCompleter>
#include "QKeyEvent"
#include "QComboBox"
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

private:
    Ui::InputForm *ui;

};

#endif // INPUTFORM_H

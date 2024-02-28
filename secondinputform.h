#ifndef SECONDINPUTFORM_H
#define SECONDINPUTFORM_H

#include <QDialog>

namespace Ui {
class SecondInputForm;
}

class SecondInputForm : public QDialog
{
    Q_OBJECT

public:
    explicit SecondInputForm(QWidget *parent = nullptr);
    ~SecondInputForm();

private:
    Ui::SecondInputForm *ui;
};

#endif // SECONDINPUTFORM_H

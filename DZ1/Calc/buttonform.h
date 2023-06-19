#ifndef BUTTONFORM_H
#define BUTTONFORM_H

#include <QWidget>

namespace Ui {
class ButtonForm;
}

class ButtonForm : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonForm(QWidget *parent = 0);
    ~ButtonForm();

private:
    Ui::ButtonForm *ui;
};

#endif // BUTTONFORM_H

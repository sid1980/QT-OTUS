#include "buttonform.h"
#include "ui_buttonform.h"

ButtonForm::ButtonForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonForm)
{
    ui->setupUi(this);
}

ButtonForm::~ButtonForm()
{
    delete ui;
}

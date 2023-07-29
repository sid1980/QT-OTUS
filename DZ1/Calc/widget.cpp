#include "widget.h"
#include "ui_widget.h"

#include "buttonform.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->widgetButtons->setLayout(new QGridLayout());
    ui->widgetButtons->layout()->addWidget(&m_buttonsForm);

}

Widget::~Widget()
{
    delete ui;
}

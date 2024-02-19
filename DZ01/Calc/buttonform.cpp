#include "buttonform.h"
#include "ui_buttonform.h"

#include <QDebug>


ButtonForm::ButtonForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonForm)
{
    ui->setupUi(this);
    connect(ui->btn0, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btn1, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btn2, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btn3, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btn4, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btn5, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btn6, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btn7, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btn8, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btn9, &QPushButton::clicked, this, &ButtonForm::numClicked);
    connect(ui->btnPoint, &QPushButton::clicked, this, &ButtonForm::numClicked);

    connect(ui->btnPlus, &QPushButton::clicked, this, &ButtonForm::operationPlus);
//    connect(ui->btnPlus, &QPushButton::clicked, this, &ButtonForm::operationPlus);

}

ButtonForm::~ButtonForm()
{
    delete ui;
}

void ButtonForm::execute()
{
    QScriptValue inputVal = m_engine.newQObject( m_operandFirst );
    m_engine.globalObject().setProperty( "input", inputVal );

}

void ButtonForm::numClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    qDebug() << btn->text();

    //! TODO: проверить на недопустимое выражение.
    m_inputValue += btn->text();
    qDebug() << m_inputValue;
}

void ButtonForm::operationPlus()
{
    bool OK{false};
    //! TODO: проверить некорректное значение.
    m_operandFirst = m_inputValue.toDouble(&OK);
    m_inputValue = QString();
    m_operand = QString("+");
}


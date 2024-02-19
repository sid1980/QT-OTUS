#ifndef BUTTONFORM_H
#define BUTTONFORM_H

#include <QWidget>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>


namespace Ui {
class ButtonForm;
}

class ButtonForm : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonForm(QWidget *parent = 0);
    ~ButtonForm();

    void execute();

private slots:
    void numClicked();
    void operationPlus();

private:
    Ui::ButtonForm *ui;

    QString m_inputValue;

    double m_operandFirst{0};
    double m_operandSecond{0};
    QString m_operand;

    QScriptEngine m_engine;
};

#endif // BUTTONFORM_H

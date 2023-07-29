#ifndef CALCULATE_H
#define CALCULATE_H

#include <QObject>

class Calculate : public QObject
{
    Q_OBJECT
public:
    explicit Calculate(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CALCULATE_H
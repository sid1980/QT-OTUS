#ifndef MODEL_H
#define MODEL_H

#include <QStandardItemModel>
#include <QObject>

class Model : public QStandardItemModel
{
    Q_OBJECT

public:
    explicit Model(QObject *parent = nullptr);

public:
    virtual QVariant data(const QModelIndex &index, int role) const override;

};

#endif // MODEL_H

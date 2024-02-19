#include "model.h"

Model::Model(QObject *parent)
    : QStandardItemModel{parent}
{

}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole
         && (index.column() == 1 || index.column() == 2))
    {
        return Qt::AlignCenter;
    }

    return QStandardItemModel::data(index, role);
}

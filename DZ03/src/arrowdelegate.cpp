#include "arrowdelegate.h"

#include <QPainter>
#include <QDebug>
#include <QPixmap>

ArrowDelegate::ArrowDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
    initIcons();
}

void ArrowDelegate::paint(QPainter *painter
                          , const QStyleOptionViewItem &option
                          , const QModelIndex &index) const
{

    if ((index.column() == 1 || index.column() == 2))
    {
        double result{0};

        if (index.row() == 0) {
            result = 0;
        }
        else {
            QModelIndex const beforeIndex { index.sibling(index.row()-1, index.column()) };
            double const  price { index.model()->data(index).toDouble() };
            double const  beforePrice {index.model()->data(beforeIndex).toDouble() };
            result = price - beforePrice;
        }

        painter->save();

        QRect const rec = option.rect;
        if (result > 0) {
            painter->drawPixmap(rec.x(), rec.y(), upIcon);
        }
        else if (result < 0) {
            painter->drawPixmap(rec.x(), rec.y(), downIcon);
        }
        else if (result == 0) {
            painter->drawPixmap(rec.x(), rec.y(), flatIcon);
        }

        painter->restore();
    }

    QStyledItemDelegate::paint(painter,option,index);
}

void ArrowDelegate::initIcons()
{
    int scale {20};
    upIcon = QPixmap(":/img/up.png").scaled(scale, scale);
    downIcon = QPixmap(":/img/down.png").scaled(scale, scale);
    flatIcon = QPixmap(":/img/flat.png").scaled(scale, scale);
}

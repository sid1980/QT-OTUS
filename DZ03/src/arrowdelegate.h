#ifndef ARROWDELEGATE_H
#define ARROWDELEGATE_H


#include <QStyledItemDelegate>
#include <QObject>

class ArrowDelegate : public QStyledItemDelegate
{
    Q_OBJECT

    using BaseClass = QStyledItemDelegate;

public:
    ArrowDelegate(QObject* parent = nullptr);

    virtual void paint(QPainter *painter
                       , const QStyleOptionViewItem &option
                       , const QModelIndex &index) const override;

    void initIcons();
public:
    QPixmap upIcon;
    QPixmap downIcon;
    QPixmap flatIcon;
};

#endif // ARROWDELEGATE_H

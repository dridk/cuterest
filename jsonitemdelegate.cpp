#include "jsonitemdelegate.h"

JsonItemDelegate::JsonItemDelegate(QObject * parent):
    QStyledItemDelegate(parent)
{

}

JsonItemDelegate::~JsonItemDelegate()
{

}

QSize JsonItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(100,20);
}


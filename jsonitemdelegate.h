#ifndef JSONITEMDELETE_H
#define JSONITEMDELETE_H
 #include <QStyledItemDelegate>

class JsonItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    JsonItemDelegate(QObject * parent = 0);
    ~JsonItemDelegate();

protected:
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

};



#endif // JSONITEMDELETE_H

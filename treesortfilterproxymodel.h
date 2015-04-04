#ifndef TREESORTFILTERPROXYMODEL_H
#define TREESORTFILTERPROXYMODEL_H
#include <QSortFilterProxyModel>

class TreeSortFilterProxyModel : public QSortFilterProxyModel
{
public:
    TreeSortFilterProxyModel(QObject * parent = 0);
    ~TreeSortFilterProxyModel();
    virtual bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

};

#endif // TREESORTFILTERPROXYMODEL_H

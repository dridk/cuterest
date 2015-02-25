#ifndef FAVORITETREEVIEW_H
#define FAVORITETREEVIEW_H

#include <QTreeView>
#include <QtWidgets>
#include "favoritemodel.h"
class FavoriteTreeView : public QTreeView
{
    Q_OBJECT
public:
    FavoriteTreeView(QWidget * parent = 0);
    ~FavoriteTreeView();

    FavoriteModel *favoriteModel();

protected slots:
    void renameFavorite();
    void editFavorite();
    void deleteFavorite();
    void doubleClickedReceived(const QModelIndex& index);
    void clickedReceived(const QModelIndex& index);


protected :
    virtual void contextMenuEvent(QContextMenuEvent * event);

signals:
    void doubleClicked(const Request& request);
    void clicked(const Request& request);


private:
    FavoriteModel * mModel;
    QAction * mRenameAction;
    QAction * mEditAction;
    QAction * mDeleteAction;


};

#endif // FAVORITETREEVIEW_H

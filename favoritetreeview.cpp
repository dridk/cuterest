#include "favoritetreeview.h"
#include <QMenu>
#include <QDebug>
#include <QStandardPaths>
FavoriteTreeView::FavoriteTreeView(QWidget * parent)
    :QTreeView(parent)
{

    mModel = new FavoriteModel();
    setModel(mModel);

    setEditTriggers(QAbstractItemView::EditKeyPressed);
    header()->hide();
    mRenameAction = new QAction(tr("Rename"),this);
    mEditAction= new QAction(tr("Edit Favorite"),this);
    mDeleteAction= new QAction(tr("Delete"),this);

    connect(mRenameAction,SIGNAL(triggered()),this,SLOT(renameFavorite()));
    connect(mDeleteAction,SIGNAL(triggered()),this,SLOT(deleteFavorite()));
    connect(this,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickedReceived(QModelIndex)));

    mModel->load(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator() + "favorite.json");

}

FavoriteTreeView::~FavoriteTreeView()
{
    mModel->save(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + QDir::separator() + "favorite.json");

}

FavoriteModel *FavoriteTreeView::favoriteModel()
{
    return mModel;
}

void FavoriteTreeView::renameFavorite()
{

    QModelIndex index = currentIndex();
    if (index.parent().isValid()) {

        edit(index);
    }
}

void FavoriteTreeView::editFavorite()
{

}

void FavoriteTreeView::deleteFavorite()
{
    QModelIndex index = currentIndex();
    if (index.parent().isValid()) {

        mModel->remove(index);
    }

}

void FavoriteTreeView::doubleClickedReceived(const QModelIndex &index)
{
    //Avoid root parent selection... thos who have no parent
    if (index.parent().isValid())
    {

        emit doubleClicked(mModel->request(index));


    }
}

void FavoriteTreeView::contextMenuEvent(QContextMenuEvent *event)
{


    if (indexAt(event->pos()).parent().isValid())
    {
        QMenu menu(this);
        menu.addAction(mRenameAction);
        menu.addAction(mEditAction);
        menu.addAction(mDeleteAction);
        menu.exec(event->globalPos());
    }



}


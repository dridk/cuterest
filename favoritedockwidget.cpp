#include "favoritedockwidget.h"
#include <QHeaderView>
#include <QStandardPaths>
FavoriteDockWidget::FavoriteDockWidget(QWidget * parent)
    :QDockWidget(parent)
{

    mModel = new FavoriteModel;
    mView = new QTreeView;
    mView->setModel(mModel);
    setWidget(mView);

    mView->header()->hide();


    //   mModel->load("/home/sacha/favorite.json");

    connect(mView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickedReceived(QModelIndex)));
}

FavoriteDockWidget::~FavoriteDockWidget()
{
    delete mModel;
    delete mView;

}

void FavoriteDockWidget::append(const Request &request)
{
    mModel->append(request);
}



void FavoriteDockWidget::doubleClickedReceived(const QModelIndex &index)
{
    // Avoid root parent selection... thos who have no parent
    if (index.parent().isValid())
    {

        emit doubleClicked(mModel->request(index));


    }


}


#include "favoritedockwidget.h"
#include <QHeaderView>
#include <QStandardPaths>
FavoriteDockWidget::FavoriteDockWidget(QWidget * parent)
    :QDockWidget(parent, Qt::Window | Qt::CustomizeWindowHint )
{

    mModel = new FavoriteModel;
    mView = new QTreeView;
    mView->setModel(mModel);
    setWidget(mView);

    mView->header()->hide();
    //For stylesheet
    mView->setObjectName("Favorite");

    setFeatures(QDockWidget::NoDockWidgetFeatures);

    //hide titleBar
    setTitleBarWidget(new QWidget());

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

void FavoriteDockWidget::importFavorite(const QString &path)
{
    mModel->load(path);
}

void FavoriteDockWidget::exportFavorite(const QString &path)
{
    mModel->save(path);
}



void FavoriteDockWidget::doubleClickedReceived(const QModelIndex &index)
{
    // Avoid root parent selection... thos who have no parent
    if (index.parent().isValid())
    {

        emit doubleClicked(mModel->request(index));


    }


}


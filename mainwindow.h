#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "manager.h"
#include "responsetabwidget.h"
#include "favoritedockwidget.h"
#include "historydockwidget.h"
#include "consoledockwidget.h"
#include "statusbar.h"
#include "controlbar.h"
#include "settingsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void exportFavorite();
    void importFavorite();
    void setStyle();
    void showSettings();

private:
    Ui::MainWindow *ui;

    Manager * mManager;
    ResponseTabWidget * mResponseWidget;
    FavoriteDockWidget * mFavoriteDock;
    HistoryDockWidget * mHistoryDock;
    ConsoleDockWidget * mConsoleDockWidget;
    ControlBar * mSearchBar;

    QString mStyleFileName;

};

#endif // MAINWINDOW_H

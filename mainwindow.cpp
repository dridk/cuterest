#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "requestserializer.h"
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mManager = new Manager(this);

    mResponseWidget = new ResponseTabWidget;
    mFavoriteDock   = new FavoriteDockWidget;
    mHistoryDock    = new HistoryDockWidget;
    mSearchBar      = new ControlBar;


    addToolBar(Qt::TopToolBarArea,mSearchBar);
    setCentralWidget(mResponseWidget);
    addDockWidget(Qt::BottomDockWidgetArea, mHistoryDock);
    addDockWidget(Qt::RightDockWidgetArea,mFavoriteDock);

    mHistoryDock->hide();
    mFavoriteDock->hide();



    connect(mSearchBar,SIGNAL(requestTrigger(Request)),mManager,SLOT(sendRequest(Request)));
    connect(mSearchBar,SIGNAL(favoriteTrigger(Request)),mFavoriteDock,SLOT(append(Request)));
    connect(mSearchBar,SIGNAL(backTrigger()),mHistoryDock,SLOT(setBack()));
    connect(mSearchBar,SIGNAL(forwardTrigger()),mHistoryDock,SLOT(setForward()));
    connect(mSearchBar,SIGNAL(panelTrigger(bool)),mFavoriteDock,SLOT(setVisible(bool)));
    connect(mSearchBar,SIGNAL(panelTrigger(bool)),mHistoryDock,SLOT(setVisible(bool)));

    connect(mManager,SIGNAL(received(Response)),mResponseWidget, SLOT(setResponse(Response)));
    connect(mManager,SIGNAL(received(Response)),mHistoryDock,SLOT(append(Response)));
    connect(mFavoriteDock,SIGNAL(doubleClicked(Request)),mSearchBar,SLOT(setRequest(Request)));
    connect(mHistoryDock,SIGNAL(doubleClicked(Request)),mSearchBar,SLOT(setRequest(Request)));
    connect(mResponseWidget,SIGNAL(requestTrigger(Request)),mSearchBar,SLOT(setRequest(Request)));

    connect(mSearchBar,SIGNAL(exportTrigger()),this,SLOT(exportFavorite()));
    connect(mSearchBar,SIGNAL(importTrigger()),this,SLOT(importFavorite()));
    connect(mSearchBar,SIGNAL(proxyTrigger()),this,SLOT(showSettings()));


    resize(1024,640);





    QAction * styleAction = new QAction(this);
    styleAction->setShortcut(Qt::Key_F12);

    addAction(styleAction);

    connect(styleAction,SIGNAL(triggered()),this,SLOT(setStyle()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exportFavorite()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Export favorite"),"",tr("Json file (*.json)"));
    mFavoriteDock->exportFavorite(filename);


}

void MainWindow::importFavorite()
{
    QString filename = QFileDialog::getOpenFileName(this,"Import favorite","",tr("Json file (*.json)"));
    mFavoriteDock->exportFavorite(filename);
}

void MainWindow::setStyle()
{



    if (!QFile::exists(mStyleFileName))
        mStyleFileName = QFileDialog::getOpenFileName(this,"qss file","","stylesheet (*.qss)");

    QFile styleFile(mStyleFileName );
    styleFile.open( QFile::ReadOnly );

    QString style( styleFile.readAll() );
    qApp->setStyleSheet(style);







}

void MainWindow::showSettings()
{
    SettingsDialog dialog(mManager,this);
    dialog.exec();
}

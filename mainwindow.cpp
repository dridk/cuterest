#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mManager = new Manager(this);

    mResponseWidget = new ResponseTabWidget;
    mFavoriteDock   = new FavoriteDockWidget;
    mHistoryDock    = new HistoryDockWidget;
    mSearchBar      = new SearchBar;


    addToolBar(Qt::TopToolBarArea,mSearchBar);
    setCentralWidget(mResponseWidget);
    addDockWidget(Qt::BottomDockWidgetArea, mHistoryDock);
    addDockWidget(Qt::LeftDockWidgetArea,mFavoriteDock);



    connect(mSearchBar,SIGNAL(triggerRequest(Request)),mManager,SLOT(sendRequest(Request)));
    connect(mManager,SIGNAL(received(Response)),mResponseWidget, SLOT(setResponse(Response)));
    connect(mManager,SIGNAL(received(Response)),mHistoryDock,SLOT(append(Response)));

    resize(1024,640);
}

MainWindow::~MainWindow()
{
    delete ui;
}

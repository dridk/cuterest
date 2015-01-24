#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QWidget>
#include <QStatusBar>
class StatusBar : public QStatusBar
{
public:
    StatusBar(QWidget * parent=0);
    ~StatusBar();
};

#endif // STATUSBAR_H

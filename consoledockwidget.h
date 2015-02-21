#ifndef CONSOLEDOCKWIDGET_H
#define CONSOLEDOCKWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include <QTextEdit>

class ConsoleDockWidget : public QDockWidget
{
public:
    ConsoleDockWidget(QWidget * parent = 0);
    ~ConsoleDockWidget();


private:
    QTextEdit * mTextEdit;
};

#endif // CONSOLEDOCKWIDGET_H

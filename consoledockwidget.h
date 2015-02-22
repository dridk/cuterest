#ifndef CONSOLEDOCKWIDGET_H
#define CONSOLEDOCKWIDGET_H

#include <QWidget>
#include <QDockWidget>
#include <QPlainTextEdit>
#include "response.h"
class ConsoleDockWidget : public QDockWidget
{
    Q_OBJECT
public:
    ConsoleDockWidget(QWidget * parent = 0);
    ~ConsoleDockWidget();
public slots:
    void append(const Response& rep);
    void append(const Request& rep);


    void out(const QString& message, bool rich = false);

private:
    QPlainTextEdit * mTextEdit;
};

#endif // CONSOLEDOCKWIDGET_H

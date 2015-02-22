#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QtWidgets>
#include <QStatusBar>
#include "response.h"
class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    StatusBar(QWidget * parent=0);
    ~StatusBar();

public slots:
    void setLoading(bool loading);
    void setResponse(const Response& response);

private:
    QLabel * mLoadingLabel;
};

#endif // STATUSBAR_H

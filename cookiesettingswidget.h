#ifndef COOKIEPROXYWIDGET_H
#define COOKIEPROXYWIDGET_H

#include <QtWidgets>
#include "abstractsettingswidget.h"
class CookieSettingsWidget : public AbstractSettingsWidget
{
    Q_OBJECT
public:
    CookieSettingsWidget(QWidget * parent=0);
    ~CookieSettingsWidget();

    bool save();
    bool load();

public slots:
    void clear();

private:
    QStandardItemModel *mModel;
    QTableView * mView;
    QPushButton * mClearButton;

};

#endif // COOKIEPROXYWIDGET_H

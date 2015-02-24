#include "consoledockwidget.h"
#include <QHostInfo>
#include <QDateTime>
#include <QAction>
ConsoleDockWidget::ConsoleDockWidget(QWidget * parent)
    :QDockWidget(parent)
{
    setWindowTitle("Console");
    setFeatures(QDockWidget::NoDockWidgetFeatures);

    mTextEdit = new QPlainTextEdit;
    mTextEdit->setReadOnly(true);

    setTitleBarWidget(new QWidget());

    setWidget(mTextEdit);

    QAction * clearAction = new QAction("Clear",this);

    addAction(clearAction);
}

ConsoleDockWidget::~ConsoleDockWidget()
{
    delete mTextEdit;
}

void ConsoleDockWidget::append(const Response &rep)
{

    out(QString("<b>>>Response[%3] code %1 in %2sec</b>").arg(rep.statusCode())
                                                   .arg(rep.time().toString("ss"))
                                                   .arg(QDateTime::currentDateTime().toString("hh:mm:ss")),true);

    foreach (QByteArray key , rep.rawHeaderList()) {
        out(QString("  %1 : %2").arg(QString(key)).arg(QString(rep.rawHeader(key))));
    }




}

void ConsoleDockWidget::append(const Request &req)
{

    out(QString("<b>&lt;&lt;Request[%3] %1 %2</b>").arg(req.verb())
                                                   .arg(req.url().toString())
                                                   .arg(QDateTime::currentDateTime().toString("hh:mm:ss")), true);

    foreach (QByteArray key , req.rawHeaderList()) {
        out(QString("  %1 : %2").arg(QString(key)).arg(QString(req.rawHeader(key))));
    }

    out(QString(req.paramToJson()));




}

void ConsoleDockWidget::out(const QString &message, bool rich)
{
    if (!rich)
        mTextEdit->appendPlainText(message);
    else
        mTextEdit->appendHtml(message);



}


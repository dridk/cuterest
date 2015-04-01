#ifndef TEXTRESPONSEWIDGET_H
#define TEXTRESPONSEWIDGET_H
#include "abstractresponsewidget.h"
#include <QTextEdit>
#include "jsonsyntaxhighlighter.h"
#include "xmlsyntaxhighlighter.h"
class TextResponseWidget : public AbstractResponseWidget
{
    Q_OBJECT
public:
    TextResponseWidget(QWidget * parent=0);
    ~TextResponseWidget();

public slots:
    void setResponse(const Response& rep);
    void setSyntaxHighlighter(const QString& key);
    void saveAs();

protected :
    void addSyntaxHighlighter(const QString& key, QSyntaxHighlighter* highlighter);



private:
    QTextEdit * mEdit;
    QComboBox * mSyntaxBox;
    QToolBar * mToolBar;

    QHash<QString, QSyntaxHighlighter*> mHighlighters;

};

#endif // TEXTRESPONSEWIDGET_H

#include "headerrequestwidget.h"

HeaderRequestWidget::HeaderRequestWidget(QWidget *parent) :
    AbstractRequestWidget(parent)
{

    mEditor = new DictEditorWidget;


    QVBoxLayout * ll = new QVBoxLayout;
    ll->addWidget(mEditor);

    setLayout(ll);

    setWindowTitle(tr("Headers"));

    mEditor->setLabel(tr("Header type:  "),tr("Header value:  "));


    QStringList list;
    list<<"Accept"
       <<"Accept-Charset"
      <<"Accept-Encoding"
     <<"Accept-Language"
    <<"Accept-Datetime"
    <<"Authorization"
    <<"Cache-Control"
    <<"Connection"
    <<"Cookie"
    <<"Content-Length"
    <<"Content-MD5"
    <<"Content-Type"
    <<"Date"
    <<"Expect"
    <<"From"
    <<"Host"
    <<"If-Match"
    <<"If-Modified-Since"
    <<"If-None-Match"
    <<"If-Range"
    <<"If-Unmodified-Since"
    <<"Max-Forwards"
    <<"Origin"
    <<"Pragma"
    <<"Proxy-Authorization"
    <<"Range"
    <<"Referer"
    <<"TE"
    <<"User-Agent"
    <<"Upgrade"
    <<"Via";

    mEditor->setCompleter(list);




}

HeaderRequestWidget::~HeaderRequestWidget()
{

}

void HeaderRequestWidget::load(Request &request)
{

    mEditor->clear();

    foreach (QByteArray header, request.rawHeaderList()){
        mEditor->insert(header, request.rawHeader(header));

    }


}

void HeaderRequestWidget::save(Request &request)
{

    for (int row=0; row < mEditor->count(); row++){

        qDebug()<<mEditor->key(row);

        request.setRawHeader(mEditor->key(row).toUtf8(), mEditor->value(row).toByteArray());
    }

}


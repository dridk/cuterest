#include "requestdialog.h"

RequestDialog::RequestDialog(const Request& request, QWidget * parent)
    :QDialog(parent)
{
    mTabWidget = new QTabWidget;
    mButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok|
                                      QDialogButtonBox::Cancel|
                                      QDialogButtonBox::RestoreDefaults);


    QVBoxLayout * mainLayout =  new QVBoxLayout;
    mainLayout->addWidget(mTabWidget);
    mainLayout->addWidget(mButtonBox);

    setLayout(mainLayout);


    connect(mButtonBox,SIGNAL(accepted()),this, SLOT(save()));
    connect(mButtonBox,SIGNAL(rejected()),this,SLOT(reject()));


    resize(600, 500);
    addRequestWidget(new HeaderRequestWidget);
    addRequestWidget(new ParamRequestWidget);



    setRequest(request);


}

RequestDialog::~RequestDialog()
{

}

void RequestDialog::addRequestWidget(AbstractRequestWidget *widget)
{
    mTabWidget->addTab(widget,widget->windowIcon(), widget->windowTitle());
    mWidgets.append(widget);
}
const Request& RequestDialog::request() const
{
    return mRequest;
}

void RequestDialog::setRequest(const Request &request)
{

    mRequest = request;
    load();
}

void RequestDialog::save()
{

    foreach (AbstractRequestWidget * widget, mWidgets){
        widget->save(mRequest);
    }

    emit accept();
}

void RequestDialog::load()
{
    foreach (AbstractRequestWidget * widget, mWidgets){
        widget->load(mRequest);

    }
}



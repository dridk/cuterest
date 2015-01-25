#include "requestdialog.h"

RequestDialog::RequestDialog(const Request& request, QWidget * parent)
    :QDialog(parent)
{
    mTabWidget = new QTabWidget;
    mButtonBox = new QDialogButtonBox(QDialogButtonBox::Ok|
                                      QDialogButtonBox::Cancel|
                                      QDialogButtonBox::RestoreDefaults);
    mEdit = new QLineEdit;
    mVerbCombo = new VerbComboBox;


    QHBoxLayout * lineLayout = new QHBoxLayout;
    lineLayout->addWidget(mVerbCombo);
    lineLayout->addWidget(mEdit);

    QVBoxLayout * mainLayout =  new QVBoxLayout;
    mainLayout->addItem(lineLayout);
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
    mEdit->setText(mRequest.url().toString());
    mVerbCombo->setCurrentText(mRequest.verb());
    load();
}

void RequestDialog::save()
{
    mRequest.setUrl(QUrl(mEdit->text()));
    mRequest.setVerb(mVerbCombo->currentText());
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



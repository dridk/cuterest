#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget * parent)
    :QDialog(parent)
{
    mButtonBox = new QDialogButtonBox();

    mButtonBox->addButton(tr("Credits"), QDialogButtonBox::HelpRole);
    mButtonBox->addButton(QDialogButtonBox::Ok);
    mContentLabel = new AboutLabel;
    mContentLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);

    mContentLabel->setText("Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod"
                           "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,"
                           "quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo"
                           "consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse"
                           "cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non"
                           "proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
                           "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod"
                           "tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,"
                           " uis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo"
                           "consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse"
                           "cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non"
                           "proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");


    QVBoxLayout * v = new QVBoxLayout;

    v->addWidget(mContentLabel);
    v->addWidget(mButtonBox);

    v->setContentsMargins(0,0,0,0);
    mButtonBox->setContentsMargins(10,10,10,10);
    setLayout(v);

    setFixedWidth(mContentLabel->width());
    setFixedHeight(500);

}

AboutDialog::~AboutDialog()
{

}


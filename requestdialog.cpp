/*
* Copyright (c) 2015 CuteRest
* CuteRest, a json REST viewer [https://github.com/dridk/cuterest]
* This file is part of CuteRest Project.
* CuteRest is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
    connect(mButtonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(clicked(QAbstractButton*)));


    resize(600, 500);
    addRequestWidget(new HeaderRequestWidget);
    addRequestWidget(new ParamRequestWidget);



    setRequest(request);

    setWindowTitle(tr("Custom request"));


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

void RequestDialog::reset()
{
    foreach (AbstractRequestWidget * widget, mWidgets){
        widget->reset();

    }
}

void RequestDialog::clicked(QAbstractButton *button)
{

    if (mButtonBox->buttonRole(button) ==  QDialogButtonBox::RestoreDefaults)
        reset();


}



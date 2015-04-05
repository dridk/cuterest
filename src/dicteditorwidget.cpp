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

#include "dicteditorwidget.h"
#include "QtAwesome/QtAwesome.h"
DictEditorWidget::DictEditorWidget(QWidget *parent)
    : QWidget(parent)
{

    mView = new QTableView;
    mModel = new DictEditorModel;
    mKeyEdit = new QComboBox;
    mValueEdit = new QLineEdit;
    mAddButton = new QToolButton;
    mRemButton = new QToolButton;
    mTypeLabel = new QLabel("type");
    mValueLabel = new QLabel("value");

    mAddButton->setIcon(QtAwesome::instance()->icon("plus"));
    mRemButton->setIcon(QtAwesome::instance()->icon("minus"));



    mView->setModel(mModel);
    mView->verticalHeader()->hide();
    mView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mView->setSelectionBehavior(QAbstractItemView::SelectRows);




    QFormLayout * formLayout = new QFormLayout;
    formLayout->addRow(mTypeLabel,mKeyEdit);
    formLayout->addRow(mValueLabel,mValueEdit);
    formLayout->setVerticalSpacing(5);
    formLayout->setFormAlignment(Qt::AlignCenter);

    QVBoxLayout * vLayout = new QVBoxLayout;

    vLayout->addItem(formLayout);
    vLayout->addWidget(mView);


    QHBoxLayout * buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(mAddButton);
    buttonLayout->addWidget(mRemButton);
    buttonLayout->addStretch();

    vLayout->addLayout(buttonLayout);

    setLayout(vLayout);

    mKeyEdit->setEditable(true);


    connect(mAddButton,SIGNAL(clicked()),this,SLOT(addClicked()));
    connect(mRemButton,SIGNAL(clicked()),this,SLOT(removeClicked()));

}

DictEditorWidget::~DictEditorWidget()
{
    delete mView ;
    delete mModel;
    delete mKeyEdit;
    delete mValueEdit;
    delete mAddButton;
    delete mRemButton;
    delete mTypeLabel;
    delete mValueLabel;
}

void DictEditorWidget::setCompleter(const QStringList &keys)
{

    mKeyEdit->addItems(keys);

}

void DictEditorWidget::insert(const QString &key, const QVariant &value)
{
    mModel->insert(key, value);
}

const QString &DictEditorWidget::key(int row) const
{
    return mModel->key(row);
}

const QVariant &DictEditorWidget::value(int row) const
{
    return mModel->value(row);
}

int DictEditorWidget::count() const
{
    return mModel->rowCount();
}


void DictEditorWidget::clear()
{
    mModel->clear();
}

void DictEditorWidget::setLabel(const QString &typeName, const QString &valueName)
{
    mTypeLabel->setText(typeName);
    mValueLabel->setText(valueName);

}

void DictEditorWidget::addClicked()
{
    mModel->insert( mKeyEdit->currentText(),mValueEdit->text());
}

void DictEditorWidget::removeClicked()
{


    mModel->remove(mView->currentIndex().row());


}


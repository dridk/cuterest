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

#include "aboutdialog.h"
#include "QtAwesome/QtAwesome.h"
#include <QDesktopServices>

AboutDialog::AboutDialog(QWidget * parent)
    :QDialog(parent)
{
    mButtonBox = new QDialogButtonBox();


    mTwitterButton = new QPushButton(QtAwesome::instance()->icon(0xf099), tr("Twitter"));
    mGithubButton = new QPushButton(QtAwesome::instance()->icon(0xf09b), tr("Github"));

    mButtonBox->addButton(mTwitterButton, QDialogButtonBox::HelpRole);
    mButtonBox->addButton(mGithubButton, QDialogButtonBox::HelpRole);
    mButtonBox->addButton(QDialogButtonBox::Ok);
    mContentLabel = new AboutLabel;
    mContentLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mContentLabel->setTextFormat(Qt::RichText);
    mContentLabel->setText("CuteRest is an OpenSource App made with Qt which provide JSON REST API feature\n"
                           "Copyright © 2015\n"
                           "Created by Sacha Schutz and Eugene Trounev\n"
                           "dridk.me - sacha@labsquare.org\n\n"
                           "This program is free software: you can redistribute it and/or modify"
                           "it under the terms of the GNU General Public License as published by"
                           "the Free Software Foundation, either version 3 of the License, or"
                           "(at your option) any later version."
                           "This program is distributed in the hope that it will be useful,"
                           "but WITHOUT ANY WARRANTY; without even the implied warranty of"
                           "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the"
                           "GNU General Public License for more details."
                           "You should have received a copy of the GNU General Public License"
                           "along with this program. If not, see <http://www.gnu.org/licenses/>.\n\n"

                           "You are welcome to help this project by submitting any issues from github"
                           );

    mContentLabel->setTitle(qApp->applicationName(), QString("version %1").arg(qApp->applicationVersion()));


    QVBoxLayout * v = new QVBoxLayout;

    v->addWidget(mContentLabel);
    v->addWidget(mButtonBox);

    v->setContentsMargins(0,0,0,0);
    mButtonBox->setContentsMargins(10,10,10,10);
    setLayout(v);

    setFixedWidth(mContentLabel->width());
    setFixedHeight(500);

    setWindowTitle(tr("About Cuterest"));

    connect(mButtonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(buttonClicked(QAbstractButton*)));

}

AboutDialog::~AboutDialog()
{
    delete mButtonBox;
    delete mContentLabel;
}

void AboutDialog::buttonClicked(QAbstractButton *button)
{
    if (button == mGithubButton)
        QDesktopServices::openUrl(QUrl("https://github.com/dridk/cuterest", QUrl::TolerantMode));

    if (button == mTwitterButton)
        QDesktopServices::openUrl(QUrl("https://twitter.com/dridk", QUrl::TolerantMode));




}


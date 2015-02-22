#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "aboutlabel.h"



class AboutDialog : public QDialog
{
    Q_OBJECT
public:
    AboutDialog(QWidget * parent = 0);
    ~AboutDialog();



private:
    QDialogButtonBox * mButtonBox;
    AboutLabel * mContentLabel;
};

#endif // ABOUTDIALOG_H

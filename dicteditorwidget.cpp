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
    delete mModel;
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


#include "dicteditorwidget.h"

DictEditorWidget::DictEditorWidget(QWidget *parent)
    : QWidget(parent)
{

    mView = new QTableView;
    mModel = new DictEditorModel;
    mKeyEdit = new QComboBox;
    mValueEdit = new QLineEdit;
    mAddButton = new QPushButton(tr("Add"));
    mRemButton = new QPushButton(tr("Remove"));


    mView->setModel(mModel);
    mView->horizontalHeader()->hide();
    mView->verticalHeader()->hide();
    mView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mView->setSelectionBehavior(QAbstractItemView::SelectRows);

    QVBoxLayout * rightLayout = new QVBoxLayout;
    rightLayout->addWidget(mAddButton);
    rightLayout->addWidget(mRemButton);
    rightLayout->addStretch();


    QHBoxLayout * hLayout = new QHBoxLayout;

    hLayout->addWidget(mKeyEdit);
    hLayout->addWidget(mValueEdit);

    QVBoxLayout * vLayout = new QVBoxLayout;

    vLayout->addItem(hLayout);
    vLayout->addWidget(mView);

    QHBoxLayout * mainLayout  = new QHBoxLayout;
    mainLayout->addItem(vLayout);
    mainLayout->addItem(rightLayout);

    setLayout(mainLayout);

    mainLayout->setContentsMargins(0,0,0,0);
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

void DictEditorWidget::addClicked()
{
    mModel->insert( mKeyEdit->currentText(),mValueEdit->text());
}

void DictEditorWidget::removeClicked()
{


    mModel->remove(mView->currentIndex().row());


}


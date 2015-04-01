#include <QFile>
#include <QFileDialog>
#include "textresponsewidget.h"
#include "QtAwesome/QtAwesome.h"
TextResponseWidget::TextResponseWidget(QWidget * parent)
    :AbstractResponseWidget(parent)
{

    setWindowTitle("Raw");
    mSyntaxBox = new QComboBox;
    mEdit      = new QTextEdit;
    mToolBar   = new QToolBar;




    QVBoxLayout * vLayout = new QVBoxLayout;
    vLayout->addWidget(mToolBar);
    vLayout->addWidget(mEdit);

    QWidget * mainWidget = new QWidget;
    mainWidget->setLayout(vLayout);
    vLayout->setContentsMargins(0,0,0,0);
    vLayout->setSpacing(0);


    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    mToolBar->setIconSize(QSize(16,16));
    QAction * saveAction =  mToolBar->addAction(QtAwesome::instance()->icon(0xf0c7), tr("Save as..."));

    mToolBar->addWidget(spacer);
    mToolBar->addWidget(mSyntaxBox);


    mEdit->setAcceptRichText(false);
    mEdit->setReadOnly(false);
    setWidget(mainWidget);



    addSyntaxHighlighter("json",new JsonSyntaxHighlighter());
    addSyntaxHighlighter("xml", new XmlSyntaxHighlighter());

    connect(mSyntaxBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(setSyntaxHighlighter(QString)));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(saveAs()));




}

TextResponseWidget::~TextResponseWidget()
{
    delete mEdit;
}

void TextResponseWidget::setResponse(const Response &rep)
{
    mEdit->clear();
    mEdit->setPlainText(rep.body());


   if (rep.rawHeader("Content-Type").contains("json"))
       setSyntaxHighlighter("json");

   if (rep.rawHeader("Content-Type").contains("javascript"))
       setSyntaxHighlighter("json");

   if (rep.rawHeader("Content-Type").contains("xml"))
       setSyntaxHighlighter("xml");


}

void TextResponseWidget::addSyntaxHighlighter(const QString& key, QSyntaxHighlighter * highlighter)
{

    mHighlighters[key] = highlighter;
    mSyntaxBox->addItem(key);




}

void TextResponseWidget::setSyntaxHighlighter(const QString& key)
{
    if (!mHighlighters.contains(key))
        return;

    mSyntaxBox->setCurrentText(key);

    QSyntaxHighlighter * s = mHighlighters.value(key);
    s->setDocument(mEdit->document());



}

void TextResponseWidget::saveAs()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save as..."));

    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {

        file.write(mEdit->toPlainText().toUtf8());


    }

    file.close();

}


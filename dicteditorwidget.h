#ifndef DICTEDITORWIDGET_H
#define DICTEDITORWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include "dicteditormodel.h"
class DictEditorWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DictEditorWidget(QWidget *parent = 0);
    ~DictEditorWidget();

    void setCompleter(const QStringList& keys);
    void insert(const QString& key, const QVariant& value);
    const QString &key(int row) const;
    const QVariant &value(int row) const;
    int count() const;
    void clear();


public slots:
    void addClicked();
    void removeClicked();

private:
    QTableView *mView;
    DictEditorModel * mModel;
    QComboBox * mKeyEdit;
    QLineEdit * mValueEdit;
    QPushButton* mAddButton;
    QPushButton* mRemButton;
};

#endif // DICTEDITORWIDGET_H
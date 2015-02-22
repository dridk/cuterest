#include "abstractsettingswidget.h"

AbstractSettingsWidget::AbstractSettingsWidget( QWidget * parent )
    :QWidget(parent)
{


}

AbstractSettingsWidget::~AbstractSettingsWidget()
{

}

void AbstractSettingsWidget::setManager(Manager *manager)
{
    mManager = manager;
}

Manager *AbstractSettingsWidget::manager()
{
    return mManager;
}


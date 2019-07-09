#include "dirhelper.h"

#include <QStandardPaths>

DirHelper::DirHelper()
{

    m_appDataDir =  QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

}

DirHelper *DirHelper::getInstance()
{
    static DirHelper dirHelper;
    return &dirHelper;
}

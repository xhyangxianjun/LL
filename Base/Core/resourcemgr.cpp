#include "resourcemgr.h"

#include <QDir>
#include <QFileInfo>
#include <QResource>
#include <QApplication>

ResourceMgr *ResourceMgr::instance()
{
    static ResourceMgr instance;
    return &instance;
}

void ResourceMgr::setStyle(ResourceMgr::StyleType type)
{
    //目前就一种的样式，不切换
    if(QResource::registerResource(m_theme_white_qrc_file))
        setStyleSheet();
}

ResourceMgr::ResourceMgr()
{
    QString dir = QDir::toNativeSeparators(QCoreApplication::applicationDirPath());
    m_theme_white_qrc_file = QString("%1/white.rcc").arg(dir);
}

void ResourceMgr::setStyleSheet()
{
    QString styleSheet;
    QDir dir(":/qss");
    QStringList nameFilters;
    nameFilters << "*.qss";

    QFileInfoList fileInfoList = dir.entryInfoList(nameFilters,QDir::Files,QDir::Name);
    for(int i = 0; i < fileInfoList.size(); ++i)
    {
        QFile qss(fileInfoList.at(i).filePath());
        qss.open(QFile::ReadOnly);
        styleSheet += qss.readAll();
        qss.close();
    }
    qApp->setStyleSheet(styleSheet);
}

#ifndef RESOURCEMGR_H
#define RESOURCEMGR_H

#include <QString>
#include "core_global.h"

/**
 * @brief 资源管理，包括样式管理
 */
class CORESHARED_EXPORT ResourceMgr
{
public:
    enum StyleType{
        No_Style = 0,
        White_Style = 1,
        Black_Style = 2
    };
    static ResourceMgr *instance();

    void setStyle(StyleType type);

protected:
    ResourceMgr();

private:
    void setStyleSheet();

    QString m_theme_white_qrc_file;
};

#endif // RESOURCEMGR_H

#ifndef HOSTINFO_H
#define HOSTINFO_H

#include <QString>
#include "core_global.h"
/**
 * @brief 主机信息管理
 */
class CORESHARED_EXPORT HostInfo
{
public:
    static HostInfo *instance();

    QString macAdress() const {return m_macAddress;}
    QString ipAdress() const {return m_ipAddress;}

    QString productName() const{return m_productName;}

protected:
    HostInfo();

private:
    QString  getHostMacAddress();  //获取Mac地址
    QString  getIpAddress();//获取Ip地址

private:
    QString m_macAddress;
    QString m_ipAddress;
    QString m_productName;
};

#endif // HOSTINFO_H

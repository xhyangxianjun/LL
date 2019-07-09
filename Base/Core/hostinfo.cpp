#include "HostInfo.h"

#include <QHostInfo>
#include <QNetworkInterface>
#include <QSysInfo>

#include <QDebug>

HostInfo *HostInfo::instance()
{
    static HostInfo hostInfo;
    return &hostInfo;
}

HostInfo::HostInfo()
{
    m_macAddress = getHostMacAddress();
    m_ipAddress     = getIpAddress();
    m_productName  = QSysInfo::prettyProductName();//系统版本号
}

QString HostInfo::getHostMacAddress()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有物理接口列表
    int nCnt = nets.count();
    QString strMacAddr = "";

    for(int i = 0; i < nCnt; i ++)
    {
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    return strMacAddr;
}

QString HostInfo::getIpAddress()
{
    QString ipaddress;
    QList<QHostAddress> addrs = QNetworkInterface::allAddresses();// 获取所有网络接口列表
    for(int i=0;i<addrs.size();i++){
        if(addrs[i].protocol() == QAbstractSocket::IPv4Protocol &&  addrs[i] != QHostAddress::LocalHost)
            ipaddress = addrs[i].toString();
    }
    return  ipaddress;
}

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <functional>
#include <QtCore>

#include "httpdefs.h"
#include "network_global.h"

//一般http请求项

class QNetworkReply;
class  NETWORKSHARED_EXPORT  HttpRequest : public QObject
{
    Q_OBJECT
public:
    HttpRequest(QObject *parent = 0);

    HttpRequest(HttpCallBack *callback, QObject *parent = 0);

    ~HttpRequest();

    void setHttpCallback(HttpCallBack* callback);
     //是否正在运行
    bool isRunning(){return m_reqId != INVALID_REQID;}
    //取消-放弃请求
    void abort();

    ReqId reqId()const {return m_reqId;}

    //请求
    ReqId  get(const QString& url);
    //发送

protected slots:
    void slotReadyRead();
    void slotFinished();

private:
    void initSignalSlot();
    static ReqId genReqId(){return (sReqId+1) == MAX_UINT32?0:++sReqId;}

    HttpCallBack  *m_callBack;
    QNetworkReply       *m_reply;
    QByteArray               m_byteArray;
    ReqId                        m_reqId = INVALID_REQID;

    //全局ReqId
    static ReqId             sReqId;
};

#endif // HTTPREQUEST_H

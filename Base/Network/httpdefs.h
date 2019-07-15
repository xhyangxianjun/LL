#ifndef HTTPDEFS_H
#define HTTPDEFS_H

#include "typedefines.h"
#include <functional>
#include <QByteArray>

//Http请求回调
class HttpCallBack
{
public:
    virtual  void finished(ReqId,const QByteArray& data,ErrorCode code = 0) = 0; //必选
    virtual void progress(ReqId reqId,qint64 bytesReceived, qint64 bytesTotal){}//进度-下载/上传文件，等耗时请求需要
};

#endif // HTTPDEFS_H

#ifndef HTTPITEM_H
#define HTTPITEM_H

#include <functional>
#include <QtCore>

#include "typedefines.h"

//数据请求回调
struct HttpClientCallBack
{
    std::function<void(qint64,const QByteArray&)> finishedFun = nullptr;
    std::function<void(qint64,qint64,qint64)> progressFun = nullptr;
    std::function<void(qint64,ErrorCode networkErrorCode)> errorFun = nullptr;
};


class HttpItem
{
public:
    HttpItem();
};

#endif // HTTPITEM_H

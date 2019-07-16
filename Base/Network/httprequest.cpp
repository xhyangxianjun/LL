#include "httprequest.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>

#include "httpclient.h"

ReqId HttpRequest::sReqId = 0;
HttpRequest::HttpRequest(QObject *parent)
    :QObject(parent),m_reply(0),m_reqId(INVALID_REQID)
{
}

HttpRequest::HttpRequest(HttpCallBack *callback, QObject *parent)
    :m_reply(0),m_callBack(callback),
      QObject(parent),m_reqId(INVALID_REQID)
{
}

HttpRequest::~HttpRequest()
{
    if(m_reply)
        m_reply->abort();
}

void HttpRequest::setHttpCallback(HttpCallBack *callback)
{
    m_callBack = callback;
}

void HttpRequest::abort()
{
    m_reply->abort();
}

ReqId HttpRequest::get(const QString &url)
{
    if(!prepare()) return INVALID_REQID;

    m_reply = HttpClient::instance()->get(url);
    initSignalSlot();
    return  m_reqId;
}

void HttpRequest::slotReadyRead()
{
    m_byteArray.append(m_reply->readAll());
}

void HttpRequest::slotFinished()
{
    if(m_callBack)
        m_callBack->finished(m_reqId,m_byteArray,m_reply->error());

    HttpClient::instance()->removeReply(m_reply);

    m_reply->deleteLater();
    //清理当前请求
    m_reqId = INVALID_REQID;
}

void HttpRequest::initSignalSlot()
{
    connect(m_reply,&QNetworkReply::readyRead,this,&HttpRequest::slotReadyRead);
    //完成回调
    connect(m_reply,&QNetworkReply::finished,this,&HttpRequest::slotFinished);
}

bool HttpRequest::prepare()
{
    //一个请求同时只进行一次
    if(m_reqId != INVALID_REQID){
        return false;
    }
    m_byteArray.clear();
    m_reqId = genReqId();
    return true;
}

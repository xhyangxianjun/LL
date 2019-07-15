#include "httpclient.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

HttpClient::HttpClient(QObject *parent)
    :QObject(parent)
{
    m_manager = new QNetworkAccessManager(this);
}

HttpClient *HttpClient::instance()
{
    static HttpClient httpClient;
    return &httpClient;
}

void HttpClient::unInit()
{
    //取消当前请求
    foreach (QNetworkReply *reply, m_replyList) {
        reply->abort();
    }

    if(m_manager)
        delete m_manager;
}

QNetworkReply *HttpClient::get(const QString &url)
{
    QNetworkRequest request(url);
    QSslConfiguration sslConfig;
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(sslConfig);

    QNetworkReply *reply = m_manager->get(request);
    m_replyList.append(reply);
    return reply;
}

bool HttpClient::removeReply(QNetworkReply *reply)
{
    return m_replyList.removeOne(reply);
}







#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "network_global.h"
#include <QObject>
/**
 * @brief The HttpClient ,QNetworkAccessManager 单例，按照文档：一个App使用一个QNetworkAccessManager就够了
 *
 */
class QNetworkAccessManager;
class QNetworkReply;
class   NETWORKSHARED_EXPORT HttpClient : public QObject
{
    Q_OBJECT
public:
    static HttpClient* instance();

    void unInit();

    QNetworkReply  *get(const QString& url);

    bool removeReply(QNetworkReply *reply);
protected:
    HttpClient(QObject *parent = 0);

private:
    QNetworkAccessManager       *m_manager;
    QList<QNetworkReply *>          m_replyList;
};

#endif // HTTPCLIENT_H

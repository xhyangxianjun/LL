#include "test.h"

#include <QDebug>
#include <QTime>
#include <QApplication>
#include <QJsonObject>
#include <QJsonDocument>


#include "Network/httprequest.h"

Test::Test()
{

}

void Test::testHttp()
{
    HttpRequest *request = new HttpRequest(this);
    request->get("http://localhost:8080/test/hello");
    //        QTime t;
    //        t.start();
    //        while(t.elapsed()<2000){
    //            QApplication::processEvents();
    //        }
    //       delete request;
}

void Test::finished(ReqId  reqId, const QByteArray &data, ErrorCode code)
{
    qDebug()<<reqId<<"finished:"<<code;

    QJsonDocument doc =QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();
    qDebug()<<obj;
}

#include "test.h"

#include <QDebug>
#include <QTime>
#include <QApplication>

#include "Network/httprequest.h"

Test::Test()
{

}

void Test::testHttp()
{
    HttpRequest *request = new HttpRequest(this);
    request->get("http://10.341.1.73:9900/dmp_list?Analyzed=0");
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
}

#ifndef TEST_H
#define TEST_H

#include <QTimer>

#include "Network/httpdefs.h"

class Test : public HttpCallBack
{
public:
    Test();

    void testHttp();

protected:
    void  finished(ReqId  reqId,const QByteArray& data,ErrorCode code);

private:
    QTimer m_timer;
};

#endif // TEST_H

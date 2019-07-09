#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "network_global.h"
#include "typedefines.h"

class NETWORKSHARED_EXPORT HttpClient
{
public:
    static HttpClient* instance();

    void cancel(ReqId reqId);


protected:
    HttpClient();

};

#endif // HTTPCLIENT_H

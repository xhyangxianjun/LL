#include "httpclient.h"


HttpClient *HttpClient::instance()
{
    static HttpClient httpClient;
    return &httpClient;
}

HttpClient::HttpClient()
{

}

#include "mainapplication.h"

#include <QDebug>

#include <QSharedMemory>
#include "Network/httpclient.h"

MainApplication::MainApplication(int &argc, char **argv)
    :Application(argc,argv)
{

}

int MainApplication::onInit()
{
    //单例启动
    QSharedMemory shared_memory;
    shared_memory.setKey("student_order");
    if(shared_memory.attach())
        return -1;

    if(!shared_memory.create(1))
        return -1;

    return this->exec();
}

int MainApplication::onExit()
{
    //清理依赖Application
    HttpClient::instance()->unInit();
    return 0;
}


int MainApplication::afterExit()
{
    return 0;
}

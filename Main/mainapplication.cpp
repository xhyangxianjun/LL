#include "mainapplication.h"

#include <QSharedMemory>
#include <QApplication>

#include "mainwindow.h"
#include "Network/httpclient.h"

//test
#include "test.h"

MainApplication::MainApplication()
{

}


int MainApplication::onInit(QApplication *app)
{
    //单例启动
    QSharedMemory shared_memory;
    shared_memory.setKey("student_order");
    if(shared_memory.attach())
        return -1;

    if(!shared_memory.create(1))
        return -1;

    //初始化程序--------------------
    MainWindow w;
    w.show();

    Test t;
    t.testHttp();

    return app->exec();
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

#include "mainapplication.h"

#include <QSharedMemory>
#include <QApplication>

#include "mainwindow.h"

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

    return app->exec();
}

int MainApplication::onExit()
{
    return 0;
}


int MainApplication::afterExit()
{
    return 0;
}

#include "application.h"

#include <QApplication>
#include <QDebug>

#include "event.h"


QMap<QString,QObject* > Application::sObjectMap = QMap<QString,QObject* >();
Application::Application(int &argc, char **argv)
    :QApplication(argc,argv)
{
    connect(this,SIGNAL(aboutToQuit()),this,SLOT(slotAboutToQuit()));
}

int Application::initApp()
{
    //调用初始化函数，用于用户数据初始化
    int ret  = onInit();
    if(ret != 0)
        return ret;

    return afterExit();
}

void Application::registerObject(const QString &key, QObject *object)
{
    sObjectMap.insert(key,object);
}

bool Application::send(const QString &objName, Event *event)
{
    QObject *obj = sObjectMap.value(objName);
    if(obj){
     return  Application::sendEvent(obj,event);
    }
    return true;
}

void Application::post(const QString &objName, Event *event)
{
    QObject *obj = sObjectMap.value(objName);
    if(obj){
        Application::postEvent(obj,event);
    }
}

void Application::slotAboutToQuit()
{
    onExit();
}

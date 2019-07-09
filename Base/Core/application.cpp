#include "application.h"

#include <QApplication>

Application::Application(QObject *parent)
    :QObject(parent),m_app(0)
{

}

Application::~Application()
{
    if(m_app){
        delete m_app;
        m_app = NULL;
    }
}

int Application::initApp(int argc, char *argv[])
{
    //创建 APP实例，绑定退出事件
    m_app = new QApplication(argc,argv);
    connect(m_app,SIGNAL(aboutToQuit()),this,SLOT(slotAboutToQuit()));

    //调用初始化函数，用于用户数据初始化
    int ret  = onInit(m_app);
    if(ret != 0)
        return ret;

    return afterExit();
}

void Application::slotAboutToQuit()
{
    onExit();
}

#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>

#include "core_global.h"

/**
 * @brief 自定义应用,支持注册消息对象，分发消息事件
 */
class QApplication;
class  CORESHARED_EXPORT Application : public QObject
{
    Q_OBJECT
public:
    Application(QObject *parent = 0);
    ~Application();

//    static void postEvent();

    int initApp(int argc, char *argv[]);

protected slots:
    void slotAboutToQuit();

protected:
    virtual int onInit(QApplication *app){return 0;}   //初始化
    virtual int onExit(){return 0;} //正在退出
    virtual int afterExit(){return 0;}//app 退出后

private:
    QApplication *m_app;
};

#endif // APPLICATION_H

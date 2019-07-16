#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMap>
#include <QApplication>
#include "core_global.h"

#include "event.h"
#include "Constants/strings.h"

/**
 * @brief 自定义应用,支持注册消息对象，分发消息事件
 */


class  CORESHARED_EXPORT Application : public QApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);
    //初始化应用
    int initApp();
    //注册对象
    static void registerObject(const QString& key,QObject *object);

    //发送自定义消息
    static bool send(const QString& objName,Event *event);
    static void  post(const QString& objName,Event *event);
protected slots:
    void slotAboutToQuit();

protected:
    virtual int onInit(){return 0;}   //初始化
    virtual int onExit(){return 0;} //正在退出
    virtual int afterExit(){return 0;}//app 退出后

private:
    static QMap<QString,QObject* >  sObjectMap; //对象map-用于消息通信
};

#endif // APPLICATION_H

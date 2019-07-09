#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "Base/Core/application.h"

class MainApplication : public Application
{
public:
    MainApplication();

protected:
    virtual int onInit(QApplication *app) ;   //初始化
    virtual int onExit() ; //正在退出
    virtual int afterExit()  ;//app 退出后
};

#endif // MAINAPPLICATION_H

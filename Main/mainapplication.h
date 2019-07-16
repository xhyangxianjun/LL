#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include "Base/Core/application.h"

class MainApplication : public Application
{
public:
    MainApplication(int &argc, char **argv);

protected:
    virtual int onInit() ;   //初始化
    virtual int onExit() ; //正在退出
    virtual int afterExit()  ;//app 退出后
};

#endif // MAINAPPLICATION_H

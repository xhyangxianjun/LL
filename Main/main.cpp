#include "mainapplication.h"

#include <QDebug>
#include "mainapplication.h"
#include "mainwindow.h"
#include "Core/resourcemgr.h"

int main(int argc, char *argv[])
{
    MainApplication a(argc,argv);

    ResourceMgr::instance()->setStyle(ResourceMgr::White_Style);

    //初始化程序--------------------
    MainWindow w;
    w.resize(800,480);
    w.show();

    return a.initApp();
}

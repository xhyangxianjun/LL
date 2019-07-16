#include "mainwindow.h"

#include <QDebug>

#include <QBoxLayout>

#include "Core/application.h"
#include "maincomponent/maintitlebar.h"

MainWindow::MainWindow(QWidget *parent) :
    FrameLessWidget(parent)
{
    createWg();

    Application::registerObject(Strings::String_MainWindow,this);
}

MainWindow::~MainWindow()
{

}

void MainWindow::createWg()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0,0,0,0);
    //标题栏
    MainTitleBar    *titleBar = new MainTitleBar(this);
    mainLayout->addWidget(titleBar);

    mainLayout->addStretch(1);
}



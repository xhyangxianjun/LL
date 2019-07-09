#include "framelesswidget.h"

//FrameLessWidget------------------------------------
FrameLessWidget::FrameLessWidget(QWidget *parent,const QString& instName)
    :BaseWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    this->setMouseTracking(true); //界面拉伸需要这个属性
    this->setObjectName(instName);

    //无边框效果
    m_pHelper = new FrameLessHelper(this);
    m_pHelper->activateOn(this);  //激活当前窗体
    m_pHelper->setWidgetMovable(true);  //设置窗体可移动
    m_pHelper->setWidgetResizable(true);  //设置窗体可缩放
    //    m_pHelper->setRubberBandOnMove(true);  //设置橡皮筋效果-可移动
    //    m_pHelper->setRubberBandOnResize(true);  //设置橡皮筋效果-可缩放
}

FrameLessWidget::~FrameLessWidget()
{
    m_pHelper->removeFrom(this);
}

///FrameLessDialog---
FrameLessDialog::FrameLessDialog(QWidget *parent ,const QString& instName)
    :BaseDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    this->setMouseTracking(true); //界面拉伸需要这个属性
    this->setObjectName(instName);

    //无边框效果
    m_pHelper = new FrameLessHelper(this);
    m_pHelper->activateOn(this);  //激活当前窗体
    m_pHelper->setWidgetMovable(true);  //设置窗体可移动
    m_pHelper->setWidgetResizable(true);  //设置窗体可缩放
}

FrameLessDialog::~FrameLessDialog()
{
    m_pHelper->removeFrom(this);
}

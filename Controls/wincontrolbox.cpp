#include "wincontrolbox.h"

#include "wincontrolbox.h"
#include <QDesktopWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QApplication>

WinControlBox::WinControlBox(QWidget* parent,QWidget* controlWindow,QString instName)
    :BaseWidget(parent),
      m_controlWindow(controlWindow),
      m_isMaximized(false),
      m_controlFlags(WinControlBox::WindowDefaultFlags)
{
    createWidget();

    updateControlFlags();
}

WinControlBox::~WinControlBox()
{

}

void WinControlBox::SwitchExpandOrNarrow()
{
    //SwitchExpandOrNarrow(isMaximized_);
    OnMaximinzed();
}

void WinControlBox::setControlFlag(const ControlFlag &controlFlag,bool enable)
{
    if(enable)
        m_controlFlags |= controlFlag;
    else
        m_controlFlags &= ~controlFlag;

    updateControlFlags();
}

void WinControlBox::setControlFlags(const ControlFlags &controlFlags)
{
    m_controlFlags = controlFlags;
    updateControlFlags();
}

void WinControlBox::SwitchExpandOrNarrow(bool isMaximized)
{
    if(isMaximized)
        m_expandBtn->setObjectName("expandBtn");
    else
        m_expandBtn->setObjectName("narrowBtn");

    m_expandBtn->setStyle(m_expandBtn->style());
}

void WinControlBox::updateControlFlags()
{
    m_minBtn->setVisible(m_controlFlags&WindowMinimizeButton);
    m_expandBtn->setVisible(m_controlFlags&WindowMaximizeButton);
    m_closeBtn->setVisible(m_controlFlags&WindowCloseButton);
}

void WinControlBox::createWidget()
{
    m_minBtn = new QPushButton(this);
    m_expandBtn = new QPushButton(this);
    m_closeBtn = new QPushButton(this);

    m_minBtn->setObjectName("minBtn");
    m_expandBtn->setObjectName("expandBtn");
    m_closeBtn->setObjectName("closeBtn");

    m_minBtn->setFocusPolicy(Qt::NoFocus);
    m_expandBtn->setFocusPolicy(Qt::NoFocus);
    m_closeBtn->setFocusPolicy(Qt::NoFocus);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(1);
    mainLayout->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(m_minBtn);
    mainLayout->addWidget(m_expandBtn);
    mainLayout->addWidget(m_closeBtn);

    connect(m_minBtn, &QPushButton::clicked, this, &WinControlBox::OnMinimized);
    connect(m_expandBtn, &QPushButton::clicked, this, &WinControlBox::OnMaximinzed);
    connect(m_closeBtn, &QPushButton::released, this, &WinControlBox::OnClose);
}

void WinControlBox::OnMinimized()
{
    if(m_controlWindow)
    {
        m_controlWindow->showMinimized();
    }

    emit mainWndMinimized();
}

void WinControlBox::OnMaximinzed()
{
    if(m_controlWindow)
    {
        if(m_isMaximized)
        {
            m_isMaximized = false;
            m_controlWindow->showNormal();
        }
        else
        {
            m_isMaximized = true;
            m_controlWindow->showMaximized();
            m_controlWindow->setGeometry(QApplication::desktop()->availableGeometry());
            emit mainWndMaximized();
        }
    }

    //更新显示
}

void WinControlBox::onRestoreWindow()
{
    if(m_isMaximized)
    {
        m_controlWindow->showMaximized();
    }
    else
    {
        m_controlWindow->showNormal();
    }
}

void WinControlBox::updateMaximize(bool isMaximized)
{
    m_isMaximized = isMaximized;
    SwitchExpandOrNarrow(!m_isMaximized);
}

void WinControlBox::OnClose()
{
    if(m_controlWindow){
        emit mainWndClose();
        m_controlWindow->close();
    }

}

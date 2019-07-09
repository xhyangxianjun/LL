#include "titlebar.h"

#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QHBoxLayout>
#include <QEvent>

#include "wincontrolbox.h"

TitleBar::TitleBar(QWidget *parent)
    : BaseWidget(parent),m_controlBox(0)
{

}


TitleBar::~TitleBar()
{

}

void TitleBar::createTitleBar()
{
    m_pIconItem = new QPushButton(this);
    m_pIconItem->setObjectName(m_iconName);
    if(m_iconName.isEmpty())
        m_pIconItem->hide();
    m_pTitleLabel = new QLabel(QStringLiteral("untitled"),this);
    m_pTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    m_pTitleLabel->setObjectName("titleName");
    m_controlBox   =  new WinControlBox(this,(QWidget*)this->parent(),"windowcontrolbox");
    QHBoxLayout *titleLayout = new  QHBoxLayout;
    titleLayout->setContentsMargins(0,0,4,0);
    titleLayout->setSpacing(0);
    titleLayout->addSpacing(10);
    titleLayout->addWidget(m_pIconItem,0,Qt::AlignVCenter);
    titleLayout->addSpacing(8);
    titleLayout->addWidget(m_pTitleLabel);
    titleLayout->addStretch();
    titleLayout->addWidget(m_controlBox,0,Qt::AlignRight);
    this->setLayout(titleLayout);
}

void TitleBar::setControlFlag(const WinControlBox::ControlFlag &controlFlag,bool enable)
{
    m_controlBox->setControlFlag(controlFlag,enable);
}

void TitleBar::setControlFlags(const WinControlBox::ControlFlags &controlFlags)
{
    m_controlBox->setControlFlags(controlFlags);
}
void TitleBar::setWinTitle(const QString &str,Qt::Alignment align)
{
    m_pTitleLabel->setText(str);
    m_pTitleLabel->setAlignment(align);
}

void TitleBar::setIconName(const QString &iconLabeName)
{
    m_iconName = iconLabeName;
    if(m_pIconItem)
    {
        m_pIconItem->setObjectName(m_iconName);
        m_pIconItem->show();
    }
}

bool TitleBar::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type())
    {
    case QEvent::WindowTitleChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            m_pTitleLabel->setText(pWidget->windowTitle());
        }
    }
    case QEvent::WindowIconChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            QIcon icon = pWidget->windowIcon();
            // m_pIconLabel->setPixmap(icon.pixmap(m_pIconLabel->size()));
        }
    }
    default:
        break;
    }
    return BaseWidget::eventFilter(obj, event);
}

void TitleBar::onMinimized()
{
    emit mainWndMinimized();
}

void TitleBar::onMaximinzed()
{
    emit mainWndMaximized();
}

void TitleBar::onClose()
{
    emit mainWndClose();
}

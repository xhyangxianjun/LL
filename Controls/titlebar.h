#ifndef TITLEBAR_H
#define TITLEBAR_H

#include "controls_global.h"
#include "wincontrolbox.h"
#include "basewidget.h"

/**
 * @brief The TitleBar class
 * @desc 标题栏
 */
class QLabel;
class QPushButton;
class CONTROLSSHARED_EXPORT TitleBar : public BaseWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);
    ~TitleBar();

    virtual void createTitleBar();

    WinControlBox *windowControlBox(){return m_controlBox;}

    void setControlFlag(const WinControlBox::ControlFlag &controlFlag,bool enable = true);

    void setControlFlags(const WinControlBox::ControlFlags &controlFlags);

    void setWinTitle(const QString& str,Qt::Alignment align = Qt::AlignLeft | Qt::AlignVCenter);

    void setIconName(const QString& iconLabeName="");
signals:
    void mainWndMinimized();
    void mainWndMaximized();
    void mainWndClose();

protected:
    virtual bool eventFilter(QObject *obj, QEvent *event);
protected:
    // 最大化/还原
    void onMinimized();
    void onMaximinzed();
    void onClose();

protected:
    QString                      m_iconName;
    QPushButton           *m_pIconItem;
    QLabel                     *m_pTitleLabel;
    WinControlBox        *m_controlBox = nullptr;
};

#endif // TITLEBAR_H

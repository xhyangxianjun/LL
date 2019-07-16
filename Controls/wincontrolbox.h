#ifndef WINCONTROLBOX_H
#define WINCONTROLBOX_H

#include "controls_global.h"

#include "basewidget.h"

class QPushButton;
class CONTROLSSHARED_EXPORT WinControlBox : public BaseWidget
{
    Q_OBJECT
public:
    enum ControlFlag
    {
        WindowMinimizeButton = 0x01,
        WindowMaximizeButton = 0x02,
        WindowMinMaxButtons =  WindowMinimizeButton|WindowMaximizeButton,
        WindowCloseButton      = 0x08,
        WindowDefaultFlags      = WindowMinMaxButtons|WindowCloseButton
    };
    Q_DECLARE_FLAGS(ControlFlags,ControlFlag)

    explicit WinControlBox(QWidget* parent,QWidget* controlWindow,QString instName="");
    virtual ~WinControlBox();

    void SwitchExpandOrNarrow();

    void setControlFlag(const ControlFlag &controlFlag,bool enable = true);
    void setControlFlags(const ControlFlags &controlFlags);

    void OnMinimized();

    void OnMaximinzed();

    void onRestoreWindow();

    void updateMaximize(bool isMaximized);

    virtual void OnClose();

signals:
    void mainWndMinimized();
    void mainWndMaximized();
    void mainWndClose();

private:

    void SwitchExpandOrNarrow(bool isMaximized);
    void updateControlFlags();
    void createWidget();

private:
    bool          m_isMaximized;
    QWidget* m_controlWindow;  //传入可被控制的Window,如果未传入，则会激活信号

    ControlFlags m_controlFlags;

    QPushButton *m_minBtn,*m_expandBtn,*m_closeBtn;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(WinControlBox::ControlFlags)


#endif // WINCONTROLBOX_H

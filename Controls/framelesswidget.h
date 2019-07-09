#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include "basewidget.h"
#include "framelesshelper.h"
#include "controls_global.h"

class CONTROLSSHARED_EXPORT FrameLessWidget : public BaseWidget
{
    Q_OBJECT
public:
    explicit FrameLessWidget(QWidget *parent = 0,const QString& instName="");
    virtual void createWg(){}
    virtual ~FrameLessWidget();

signals:

public slots:

protected:
    FrameLessHelper *m_pHelper;
};

class CONTROLSSHARED_EXPORT FrameLessDialog : public BaseDialog
{
    Q_OBJECT
public:
    explicit FrameLessDialog(QWidget *parent = 0,const QString& instName="");
    virtual ~FrameLessDialog();

protected:
    FrameLessHelper *m_pHelper;
};

#endif // FRAMELESSWIDGET_H

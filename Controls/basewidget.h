#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include "controls_global.h"
#include <QWidget>
#include <QDialog>


//支持QSS配置的窗口的自定义基类对话框
class CONTROLSSHARED_EXPORT BaseWidget : public QWidget
{
public:
    BaseWidget(QWidget *parent = 0);
    virtual ~BaseWidget(){}


protected:
    virtual void paintEvent(QPaintEvent *e);
};


class CONTROLSSHARED_EXPORT BaseDialog : public QDialog
{
    Q_OBJECT
public:
    explicit BaseDialog(QWidget *parent = 0);
    virtual ~BaseDialog();

signals:

public slots:

protected:

    virtual void paintEvent(QPaintEvent *e);
};

#endif // BASEWIDGET_H

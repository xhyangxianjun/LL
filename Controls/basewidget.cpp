#include "basewidget.h"

#include <QPainter>
#include <QStyleOption>


BaseWidget::BaseWidget(QWidget *parent)
    :QWidget(parent)
{


}
void BaseWidget::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
    QWidget::paintEvent(e);
}




//BaseDialog----
BaseDialog::BaseDialog(QWidget *parent)
    : QDialog(parent)
{

}

BaseDialog::~BaseDialog()
{

}

void BaseDialog::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
    QDialog::paintEvent(e);
}

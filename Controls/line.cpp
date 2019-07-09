#include "line.h"
#include <QStyleOption>
#include <QPainter>

#include "dimens.h"

Line::Line(QWidget *parent,QString name)
    :m_orientation(Qt::Horizontal),QFrame(parent)
{
    createLine();
    if(!name.isEmpty())
        setObjectName(name);
}

Line::Line(Qt::Orientation orientation,QWidget *parent,QString style)
    :m_orientation(orientation),QFrame(parent)
{
    createLine();
    if(!style.isEmpty())
        setObjectName(style);
}

void Line::createLine()
{
    m_LineWidth = Dimens::Dimen_1;

    QFrame::Shape shape = m_orientation==Qt::Horizontal?QFrame::HLine:QFrame::VLine;
    this->setFrameShape(shape);
    //默认Plain样式
    this->setFrameShadow(QFrame::Plain);

    //根据方向设置边框大小
    this->setLineWidth(m_LineWidth);
    if(m_orientation == Qt::Horizontal)
    {
        this->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
        this->setFixedHeight(m_LineWidth);
    }else
    {
        this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Preferred);
        this->setFixedWidth(m_LineWidth);
    }
}

void Line::setLineWidth(const int &lineWidth)
{
    m_LineWidth  = lineWidth;
    if(m_orientation == Qt::Horizontal) {
        this->setFixedHeight(m_LineWidth);
    }else {
        this->setFixedWidth(m_LineWidth);
    }
}

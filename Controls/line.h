#ifndef LINE_H
#define LINE_H

#include "controls_global.h"
#include <QFrame>

class  CONTROLSSHARED_EXPORT Line : public QFrame
{
    Q_OBJECT
public:
    Line(QWidget *parent = 0,QString name="");
    Line(Qt::Orientation orientation ,QWidget *parent = 0,QString name="");
    ~Line(){}

    void setLineWidth(const int &lineWidth);

protected:

private:
    void createLine();

private:
    Qt::Orientation m_orientation;
    int   m_LineWidth=1;
};

#endif // LINE_H

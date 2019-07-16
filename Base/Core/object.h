#ifndef OBJECT_H
#define OBJECT_H

#include <QList>
/**
 * @brief 自定义封装类，树形结构，实现激活非激活:一般由窗口隐藏和显示实现
 */
class Object
{
public:
    Object(Object *parent);

    //激活/非激活
    virtual void active();
    virtual void deActive();

    Object *parent()const {return m_parent;}
    QList<Object *> children()const {return m_children;}
    int childCount(){return m_children.count();}
    Object *childAt(int index);

private:
    Object                *m_parent; //父对象
    QList<Object *> m_children;//子对象
};

#endif // OBJECT_H

#include "object.h"

Object::Object(Object *parent)
    :m_parent(parent)
{

}

void Object::active()
{
    foreach (Object *obj, m_children) {
        obj->active();
    }
}

void Object::deActive()
{
    foreach (Object *obj, m_children) {
        obj->deActive();
    }
}

Object *Object::childAt(int index)
{
    if(index>=0 && index <m_children.size())
        return m_children.at(index);
    return 0;
}

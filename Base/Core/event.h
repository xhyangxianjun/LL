#ifndef EVENT_H
#define EVENT_H

#include <QEvent>
#include <QVariant>

#include "core_global.h"

/**
 * @brief 自定义事件消息
 */
class CORESHARED_EXPORT Event : public QEvent
{
public:
    enum EventType{
        ET_Base = QEvent::User +1,
    };
    Event();

    void put(const QString& key,const QVariant& value){m_varmap.insert(key,value);}

    QVariant get(const QString& key) const{return m_varmap.value(key);}

    static QEvent::Type eventType;
private:
    QVariantMap   m_varmap;  //时间参数
};

#endif // EVENT_H

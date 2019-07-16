#include "event.h"

QEvent::Type Event::eventType = (QEvent::Type)QEvent::registerEventType(Event::ET_Base);

Event::Event()
  :QEvent(eventType)
{

}

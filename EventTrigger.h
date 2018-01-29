#ifndef EVENTTRIGGER_H_INCLUDED
#define EVENTTRIGGER_H_INCLUDED
#include <string>
#include <vector>
#include "XmlDomDocument.h"
typedef struct event{
    char *events;
    char *eventParameter;

}TriggerEvent;
class EventTrigger{
    private:
        std::vector<TriggerEvent*> events;
        unsigned priority;
    public:
        std::vector<TriggerEvent*>& getTriggerEvent();
        unsigned getPriority();
        void setEvent(std::vector<TriggerEvent*> eventTrigger);
        void setPriority(unsigned priority);
        ~EventTrigger();
        EventTrigger();
        void parsingEventTrigger(DOMElement *raiz);
};

#endif // EVENTTRIGGER_H_INCLUDED

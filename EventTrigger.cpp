#include "EventTrigger.h"
#include <iostream>

std::vector<TriggerEvent*>& EventTrigger::getTriggerEvent()
{
    return this->events;
}

unsigned EventTrigger::getPriority()
{
    return this->priority;
}

void EventTrigger::setEvent(std::vector<TriggerEvent* > eventTrigger)
{
    this->events = eventTrigger;
}

void EventTrigger::setPriority(unsigned priority)
{
    this->priority = priority;
}

EventTrigger::~EventTrigger()
{
    for(int i = 0; i < this->events.size(); i++){
        free(this->events.at(i)->events);
        free(this->events.at(i)->eventParameter);
        free(this->events.at(i));
    }
}
EventTrigger::EventTrigger()
{
    this->priority = 0;

}

void EventTrigger::parsingEventTrigger(DOMElement* raiz)
{

    DOMElement *element = NULL;
    for(int i = 0; i <  raiz->getElementsByTagName(XMLString::transcode("Event"))->getLength(); i++){
        TriggerEvent *et = (TriggerEvent*) malloc(sizeof(TriggerEvent));
        element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("Event"))->item(i));
        std::string s =  XMLString::transcode(element->getTextContent());
        int sz = s.size();
        et->events = (char*)malloc(sizeof(char)*sz);
        const char *c;
        c = s.c_str();
        std::cout<<"events :"<<c<<std::endl;
        strcpy(et->events, c);
        s = XMLString::transcode(element->getAttribute(XMLString::transcode("EventParameter1")));
        c = s.c_str();
        sz = s.size();
        et->eventParameter = (char*)malloc(sizeof(char)*sz);
        strcpy(et->eventParameter,c );
        this->events.push_back(et);

    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("Priority"))->item(0));
    if(element != NULL){
        this->priority = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }


}


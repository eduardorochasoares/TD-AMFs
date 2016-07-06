#include "MeasurementSchedule.h"
std::vector<MeasurementPeriod*>& MeasurementSchedule::getMeasurementPeriod()
{
    return this->measurementPeriod;
}

std::vector<EventTrigger*>& MeasurementSchedule::getEventTrigger()
{
    return this->eventTrigger;
}

TimeTrigger* MeasurementSchedule::getTimeTrigger()
{
    return this->timeTrigger;
}

ServiceStartTrigger* MeasurementSchedule::getServiceStart()
{
    return this->serviceStart;
}

void MeasurementSchedule::setMeasurementPeriod(std::vector<MeasurementPeriod* > mp)
{
    this->measurementPeriod = mp;
}

void MeasurementSchedule::setEventTrigger(std::vector<EventTrigger* > eventTrigger)
{
    this->eventTrigger = eventTrigger;
}

void MeasurementSchedule::setTimeTrigger(TimeTrigger* tt)
{
    this->timeTrigger = tt;
}

void MeasurementSchedule::setServiceStartTrigger(ServiceStartTrigger* sst)
{
    this->serviceStart = sst;
}

MeasurementSchedule::~MeasurementSchedule()
{
    for(int i = 0; i < this->eventTrigger.size(); i++)
        delete this->eventTrigger.at(i);

    for(int i = 0; i < this->measurementPeriod.size(); i++ )
        delete this->measurementPeriod.at(i);

    delete this->timeTrigger;

    delete this->serviceStart;

}

MeasurementSchedule::MeasurementSchedule()
{
    this->serviceStart = NULL;
    this->timeTrigger = NULL;

}


void MeasurementSchedule::parsingMeasurementSchedule(DOMElement* raiz)
{
    DOMElement *element = NULL;
    for(int i = 0 ; i < raiz->getElementsByTagName(XMLString::transcode("MeasurementPeriod"))->getLength(); i++){
        element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
            XMLString::transcode("MeasurementPeriod"))->item(i));
        MeasurementPeriod *mp = new MeasurementPeriod();
        mp->parsingMeasurementPeriod(element, false);
        this->measurementPeriod.push_back(mp);
    }

    for(int i = 0; i < raiz->getElementsByTagName(XMLString::transcode("EventTrigger"))->getLength(); i++){
        element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
            XMLString::transcode("EventTrigger"))->item(i));
        EventTrigger *eventTrigger = new EventTrigger();
        eventTrigger->parsingEventTrigger(element);
        this->eventTrigger.push_back(eventTrigger);

    }

    element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(XMLString::transcode("TimeTrigger"))->item(0));
    if(element != NULL){
        this->timeTrigger = new TimeTrigger();
        this->timeTrigger->parsingTimeTrigger(element);
    }

    element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
        XMLString::transcode("ServiceStartTrigger"))->item(0));
    if(element != NULL){
        this->serviceStart = new ServiceStartTrigger();
        this->serviceStart->parsingServiceStartTrigger(element);
    }

}



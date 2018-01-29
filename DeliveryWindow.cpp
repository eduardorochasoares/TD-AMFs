#include "DeliveryWindow.h"
#include "stdlib.h"
#include "Algoritmos.h"
struct tm* DeliveryWindow::getStartTime()
{
   return this->startTime;
}

struct tm* DeliveryWindow::getEndTime()
{
    return this->endTime;
}

void DeliveryWindow::setStartTime(struct tm* s)
{
    this->startTime = s;
}

void DeliveryWindow::setEndTime(struct tm* e)
{
    this->endTime  = e;
}

DeliveryWindow::~DeliveryWindow()
{
    free(this->endTime);
    free(this->startTime);
}

DeliveryWindow::DeliveryWindow()
{
    this->endTime = NULL;
    this->startTime = NULL;
}

void DeliveryWindow::parsingDeliveryWindow(DOMElement* raiz, bool isDefault)
{
    string start, endT;
    if(isDefault){
        start = "DefaultStartDeliveryWindowTime";
        endT  = "DefaultEndDeliveryWindowTime";
    }else{
        start = "StartDeliveryWindowTime";
        endT = "EndDeliveryWindowTime";
    }
    DOMElement *element = NULL;
    string value;
    element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(XMLString::transcode(start.c_str()))->item(0));
    if(element != NULL){
        this->startTime = (struct tm*)malloc(sizeof(struct tm));
        value = XMLString::transcode(element->getTextContent());
        setTimeAndDate(this->startTime, value);
    }
    element  = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode(endT.c_str()))->item(0));
    if(element != NULL){
        this->endTime = (struct tm*)malloc(sizeof(struct tm));
        value = XMLString::transcode(element->getTextContent());
        setTimeAndDate(this->endTime, value);
    }
}


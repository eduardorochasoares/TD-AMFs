#include "MeasurementDeliverySched.h"

MeasurementDeliverySched::~MeasurementDeliverySched()
{
    delete this->immediatePush;
    delete this->delayedDelivery;

}
ImmediatePush::ImmediatePush()
{
    this->maxTimeBetweenDelivery = 0;
    this->measurementReportNumbByPush = 0;
}

DelayedDelivery::DelayedDelivery()
{
    this->hybrid = false;
}

MeasurementDeliverySched::MeasurementDeliverySched()
{
    this->delayedDelivery = NULL;
    this->pull = false;
    this->retransmitNumb = 0;
    this->storeCongestPolicy = 0;
    this->immediatePush = NULL;
    this->delayedPullandPush = NULL;
}

std::vector<std::string> MeasurementDeliverySched::getDeliveryAddress()
{
    return this->deliveryAddress;
}

unsigned MeasurementDeliverySched::getRetransmitNumb()
{
    return this->retransmitNumb;
}

short MeasurementDeliverySched::getStoreCongestPolicy()
{
    return this->storeCongestPolicy;
}

ImmediatePush* MeasurementDeliverySched::getImmediatePush()
{
    return this->immediatePush;
}

DelayedDelivery* MeasurementDeliverySched::getDelayedDelivery()
{
    return this->delayedDelivery;
}

bool MeasurementDeliverySched::getPull()
{
    return this->pull;
}

void MeasurementDeliverySched::setDeliveryAddress(std::vector<std::string> deliveryAddress)
{
    this->deliveryAddress = deliveryAddress;
}

void MeasurementDeliverySched::setRetransmitNumber(unsigned retransmit)
{
    this->retransmitNumb = retransmit;
}

void MeasurementDeliverySched::setStorageCongestPolicy(short policy)
{
    this->storeCongestPolicy  = policy;
}

void MeasurementDeliverySched::setImmediatePush(ImmediatePush* immediate)
{
    this->immediatePush = immediate;
}

void MeasurementDeliverySched::setDelayedDelivery(DelayedDelivery* delayedDelivery)
{
    this->delayedDelivery = delayedDelivery;
}

void MeasurementDeliverySched::setPull(bool pull)
{
    this->pull = pull;
}

unsigned ImmediatePush::getMeasurementReportNumbByPush()
{
    return this->measurementReportNumbByPush;
}

unsigned ImmediatePush::getMaxTimeBetweenDelivery()
{
    return this->maxTimeBetweenDelivery;
}

void ImmediatePush::setMeasurementReportNumbByPush(unsigned num)
{
    this->measurementReportNumbByPush = num;
}

void ImmediatePush::setMaxTimeBetweenDelivery(unsigned seconds)
{
    this->maxTimeBetweenDelivery = seconds;
}

std::vector<DeliveryWindow*>& DelayedDelivery::getDeliveryWindow()
{
    return this->deliveryWindow;
}

bool DelayedDelivery::getHybrid()
{
    return this->hybrid;
}

void DelayedDelivery::setHybrid(bool hybrid)
{
    this->hybrid = hybrid;
}

void DelayedDelivery::setDeliveryWindow(std::vector<DeliveryWindow* > deliveryWindow)
{
    this->deliveryWindow = deliveryWindow;
}

DelayedDelivery::~DelayedDelivery()
{
    for(int i = 0; i < this->deliveryWindow.size(); i++)
        delete this->deliveryWindow.at(i);
}

void MeasurementDeliverySched::parsingDeliverySched(DOMElement* raiz)
{
    DOMElement *element = NULL;
    for(int  i = 0; i < raiz->getElementsByTagName(XMLString::transcode("DeliveryAddress"))->getLength(); i++){
        element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
            XMLString::transcode("DeliveryAddress"))->item(i));
        this->deliveryAddress.push_back(XMLString::transcode(element->getTextContent()));
    }
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("RetransmitNumber"))->item(0));
    if(element != NULL){
        this->retransmitNumb = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("StorageCongestionPolicy"))->item(0));
    if(element != NULL){
        this->storeCongestPolicy = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("ImmediatePush"))->item(0));
    if(element != NULL){
       this->immediatePush = new ImmediatePush();
       this->immediatePush->parsingImmeadiatePush(element);
    }
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DelayedDelivery"))->item(0));
    if(element != NULL){
        this->delayedDelivery = new DelayedDelivery();
        this->delayedDelivery->parsingDelayedDelivery(element, false);
    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("Pull"))->item(0));
    if(element != NULL){
        this->pull = true;
    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DelayedPushAndPull"))->item(0));
    if(element != NULL){
        this->delayedPullandPush = new DelayedDelivery();
        this->delayedPullandPush->parsingDelayedDelivery(element, true);
    }

}
void ImmediatePush::parsingImmeadiatePush(DOMElement* raiz)
{
    DOMElement *element = NULL;
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("MeasurementReportNumberByPush"))->item(0));
    if(element != NULL){
        this->measurementReportNumbByPush = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("MaxTimeBetweenDelivery"))->item(0));
    if(element != NULL){
        this->maxTimeBetweenDelivery = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }


}

void DelayedDelivery::parsingDelayedDelivery(DOMElement* raiz, bool hybrid)
{
    DOMElement *element = NULL;
    this->hybrid = hybrid;
    for(int i = 0; i < raiz->getElementsByTagName(XMLString::transcode("DeliveryWindow"))->getLength(); i++){
        element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
            XMLString::transcode("DeliveryWindow"))->item(i));
        DeliveryWindow *dw = new DeliveryWindow();
        dw->parsingDeliveryWindow(element, false);
        this->deliveryWindow.push_back(dw);
    }



}
DelayedDelivery* MeasurementDeliverySched::getDelayedPullandPush()
{
    return this->delayedPullandPush;
}

void MeasurementDeliverySched::setDelayedPullandPush(DelayedDelivery* pullandPush)
{
    this->delayedPullandPush = pullandPush;
}


#include "MeasurementSet.h"
#include "Algoritmos.h"

AllContentClassExceptList* MeasurementSet::getAllContentClassExceptList()
{
    return this->defaultContentClassExceptList;
}

std::vector<MeasurementPeriod*>& MeasurementSet::getMeasurementPeriod()
{
    return this->measurementPeriods;
}

int MeasurementSet::getDefaultPeriodicity()
{
    return this->defaultPeriodicity;
}

short MeasurementSet::getDefaultNothingNewToReport()
{
    return this->defaultNothingNewToReport;
}

int MeasurementSet::getDefaultInterval()
{
    return this->defaultInterval;
}

std::vector<std::string>& MeasurementSet::getDefaultDeliveryAddress()
{
    return this->defaultDeliveryAddress;
}

int MeasurementSet::getDefaultRetransmitNumber()
{
    return this->defaultRetransmitNumber;
}

short MeasurementSet::getDefaultStorageCongestPolicy()
{
    return this->defaultStorageCongestPolicy;
}

int MeasurementSet::getDefaultMeasurementReportNumberByPush()
{
    return this->defaultMeasurementReportNumberByPush;
}

int MeasurementSet::getDefaultMaxTimeBetweenDelivery()
{
    return this->defaultMaxTimeBetweenDelivery;
}

std::vector<DeliveryWindow*>& MeasurementSet::getDeliveryWindow()
{
    return this->deliveryWindow;
}

MeasurementSet::~MeasurementSet()
{
    for(int i = 0; i < deliveryWindow.size(); i++)
        delete this->deliveryWindow.at(i);

    for(int i = 0; i < measurementPeriods.size(); i++)
        delete this->measurementPeriods.at(i);

    delete this->defaultContentClassExceptList;

    for(int i = 0; i < this->measurementRequests.size(); i++)
        delete this->measurementRequests.at(i);
}

void MeasurementSet::setAllContentClassExcpt(AllContentClassExceptList* a)
{
    this->defaultContentClassExceptList = a;
}

void MeasurementSet::setMeasurementPeriod(std::vector<MeasurementPeriod*> mp)
{
    this->measurementPeriods = mp;
}

void MeasurementSet::setDefaultPeriodicity(int periodicity)
{
    this->defaultPeriodicity = periodicity;
}

void MeasurementSet::setDefaultNothingNewToReport(short n)
{
    this->defaultNothingNewToReport = n;
}

void MeasurementSet::setDefaultInterval(int interval)
{
    this->defaultInterval = interval;
}

void MeasurementSet::setDefaultAddress(std::vector<std::string> address)
{
    this->defaultDeliveryAddress = address;
}

void MeasurementSet::setDefaultRetransmitNumber(int retransmit)
{
    this->defaultRetransmitNumber = retransmit;
}

void MeasurementSet::setDefaultStorageCongestPolicy(short policy)
{
    this->defaultStorageCongestPolicy = policy;
}

void MeasurementSet::setDefaultMeasurementReportNumberByPush(int n)
{
    this->defaultMeasurementReportNumberByPush = n;
}

void MeasurementSet::setDeliveryWindow(std::vector<DeliveryWindow* > d)
{
    this->deliveryWindow = d;
}

void MeasurementSet::setMeasurementRequest(std::vector<MeasurementRequest* > mr)
{
    this->measurementRequests = mr;
}

MeasurementSet::MeasurementSet()
{
    this->defaultContentClassExceptList = NULL;
    this->defaultInterval = 0;
    this->defaultMaxTimeBetweenDelivery = 0;
    this->defaultMeasurementReportNumberByPush = 1;
    this->defaultNothingNewToReport = 0;
    this->defaultPeriodicity = 0;
    this->defaultRetransmitNumber = 0;
    this->defaultStorageCongestPolicy = 1;

}

void MeasurementSet::parsingMeasurementSet(DOMElement *raiz)
{
    DOMElement *element  = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DefaultAllContentClassExceptList"))->item(0));
    if(element != NULL){
        this->defaultContentClassExceptList = new AllContentClassExceptList();
        this->defaultContentClassExceptList->parsingExceptList(element);
    }
    for(int i = 0 ; i < raiz->getElementsByTagName(XMLString::transcode("DefaultMeasurementPeriod"))->getLength();i++){
         element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
            XMLString::transcode("DefaultMeasurementPeriod"))->item(i));
            MeasurementPeriod *mp = new MeasurementPeriod();
            mp->parsingMeasurementPeriod(element, true);
            this->measurementPeriods.push_back(mp);
    }

    element  = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DefaultTimeDrivenMeasurementPeriodicity"))->item(0));
    if(element != NULL){
        this->defaultPeriodicity = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DefaultNothingNewReportMode"))->item(0));
    if(element != NULL){
        this->defaultNothingNewToReport = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DefaultInterval"))->item(0));
    if(element != NULL){
        this->defaultInterval = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    for(int i = 0; i < raiz->getElementsByTagName(XMLString::transcode("DefaultDeliveryAddress"))->getLength(); i++){
        element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
            XMLString::transcode("DefaultDeliveryAddress"))->item(i));
        this->defaultDeliveryAddress.push_back(XMLString::transcode(element->getTextContent()));
    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DefaultStorageCongestionPolicy"))->item(0));
    if(element != NULL){
        this->defaultStorageCongestPolicy = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    element  = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DefaultRetransmitNumber"))->item(0));
    if(element != NULL){
        this->defaultRetransmitNumber = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DefaultMeasurementReportNumberByPush"))->item(0));
    if(element != NULL){
        this->defaultMeasurementReportNumberByPush = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("DefaultMaxTimeBetweenDelivery"))->item(0));
    if(element != NULL){
        this->defaultMaxTimeBetweenDelivery = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    for(int i = 0; i < raiz->getElementsByTagName(XMLString::transcode("DefaultDeliveryWindow"))->getLength(); i++){
        element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
            XMLString::transcode("DefaultDeliveryWindow"))->item(i));
        DeliveryWindow *dw = new DeliveryWindow();
        dw->parsingDeliveryWindow(element, true);
        this->deliveryWindow.push_back(dw);
    }

    for(int i = 0; i < raiz->getElementsByTagName(XMLString::transcode("MeasurementRequest"))->getLength(); i++){
        element  = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
            XMLString::transcode("MeasurementRequest"))->item(i));
        MeasurementRequest *mr = new MeasurementRequest();
        mr->parsingMeasurementRequest(element);
        this->measurementRequests.push_back(mr);

    }
}

std::vector<MeasurementRequest*>& MeasurementSet::getMeasurementRequests()
{
    return this->measurementRequests;
}

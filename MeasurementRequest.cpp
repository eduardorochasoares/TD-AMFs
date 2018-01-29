#include "MeasurementRequest.h"
#include "Algoritmos.h"

MeasurementRequest::~MeasurementRequest()
{
    delete this->deliverySched;
    delete this->ltvq;

    for(int i = 0; i < this->measurementSched.size(); i++)
        delete this->measurementSched.at(i);
}

unsigned MeasurementRequest::getMeasurementRequestID()
{
    return this->measurementRequestID;
}

LinearTVQualififer* MeasurementRequest::getLinearTvQualifier()
{
    return this->ltvq;
}

std::vector<MeasurementSchedule*>& MeasurementRequest::getMeasurementSched()
{
    return this->measurementSched;
}

MeasurementDeliverySched* MeasurementRequest::getMeasurementDeliverySched()
{
    return this->deliverySched;
}

void MeasurementRequest::setMeasurementID(unsigned id)
{
    this->measurementRequestID = id;
}

void MeasurementRequest::setLinearTvQualifier(LinearTVQualififer* ltq)
{
    this->ltvq = ltq;
}

void MeasurementRequest::setMeasurementSched(std::vector<MeasurementSchedule*> ms)
{
    this->measurementSched  = ms;
}

void MeasurementRequest::setMeasurementDelivery(MeasurementDeliverySched* mds)
{
    this->deliverySched = mds;
}

MeasurementRequest::MeasurementRequest()
{
    this->deliverySched = NULL;
    this->ltvq = NULL;
    this->measurementRequestID = 0;
    this->classExceptList = NULL;
}

AllContentClassExceptList* MeasurementRequest::getClassExceptList()
{
    return this->classExceptList;
}

void MeasurementRequest::setClassExceptList(AllContentClassExceptList* all)
{
    this->classExceptList = all;
}

void MeasurementRequest::parsingMeasurementRequest(DOMElement* raiz)
{
    DOMElement *element = NULL;

    element  = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("MeasurementRequestID"))->item(0));
    if(element != NULL){
        this->measurementRequestID = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("LinearTVQualifier"))->item(0));
    if(element != NULL){
        this->ltvq = new LinearTVQualififer();
        ltvq->parsingLinearTVQualififer(element);

    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("AllContentClassExceptList"))->item(0));
    if(element != NULL){
        this->classExceptList = new AllContentClassExceptList();
        this->classExceptList->parsingExceptList(element);
    }

    for(int i = 0 ; i < raiz->getElementsByTagName(XMLString::transcode("MeasurementSchedule"))->getLength(); i++){
        element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
            XMLString::transcode("MeasurementSchedule"))->item(i));
        MeasurementSchedule *ms =  new MeasurementSchedule();
        ms->parsingMeasurementSchedule(element);
        this->measurementSched.push_back(ms);



    }

}

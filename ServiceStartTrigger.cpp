#include "ServiceStartTrigger.h"

unsigned ServiceStartTrigger::getInterval()
{
    return this->interval;
}

std::vector<SampleSet*>& ServiceStartTrigger::getSampleSet()
{
    return this->sampleSet;
}

unsigned ServiceStartTrigger::getPriority()
{
    return this->priority;
}

void ServiceStartTrigger::setInterval(unsigned interval)
{
    this->interval = interval;
}

void ServiceStartTrigger::setSampleSet(std::vector<SampleSet* > sampleSet)
{
    this->sampleSet = sampleSet;
}

void ServiceStartTrigger::setPriority(unsigned priority)
{
    this->priority = priority;
}

ServiceStartTrigger::~ServiceStartTrigger()
{
    for(int i = 0; i < this->sampleSet.size(); i++)
        delete this->sampleSet.at(i);
}
ServiceStartTrigger::ServiceStartTrigger()
{
    this->interval = 0;
    this->priority = 0;
}
void ServiceStartTrigger::parsingServiceStartTrigger(DOMElement* raiz)
{
    DOMElement *element = NULL;
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("Interval"))->item(0));
    if(element != NULL){
        this->interval = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    for(int i = 0; i < raiz->getElementsByTagName(XMLString::transcode("SampleSet"))->getLength(); i++){
        element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("SampleSet"))->item(i));
        SampleSet *sampleS = new SampleSet();
        sampleS->setSampleId(XMLString::transcode(element->getElementsByTagName(
            XMLString::transcode("SampleSetIdentifier"))->item(0)->getTextContent()));
        for(int j = 0; j < element->getElementsByTagName(XMLString::transcode("SampleSetQualifier"))->getLength(); j++){
            sampleS->getSampleSetQualifier().push_back(XMLString::transcode(element->getElementsByTagName(
                XMLString::transcode("SampleSetQualifier"))->item(j)->getTextContent()));
        }

    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("Priority"))->item(0));
    if(element != NULL){
        this->priority = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }
}



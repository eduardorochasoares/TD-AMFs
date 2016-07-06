#include "TimeTrigger.h"
#include <iostream>
std::string SampleSet::getSampleSetId()
{
    return this->sampleSetId;
}

std::vector<std::string> SampleSet::getSampleSetQualifier()
{
    return this->sampleSetQualifier;
}

void SampleSet::setSampleId(std::string id)
{
    this->sampleSetId = id;
}

void SampleSet::setSampleSetQualifier(std::vector<std::string> qualifier)
{
    this->sampleSetQualifier = qualifier;
}

std::vector<SampleSet*>& TimeTrigger::getSampleSet()
{
    return this->sampleSet;
}

unsigned TimeTrigger::getPeriodicity()
{
    return this->periodicity;
}

unsigned TimeTrigger::getPriority()
{
    return this->priority;
}

short TimeTrigger::getNothingNew()
{
    return this->nothingNew;
}

void TimeTrigger::setSampleSet(std::vector<SampleSet* > sampleSet)
{
    this->sampleSet = sampleSet;
}

void TimeTrigger::setPeriodicity(unsigned periodicity)
{
    this->periodicity = periodicity;
}

void TimeTrigger::setPriority(unsigned priority)
{
    this->priority = priority;
}

void TimeTrigger::setNothingNew(short nothingNew)
{
    this->nothingNew = nothingNew;
}

TimeTrigger::~TimeTrigger()
{
    for(int i = 0; i < this->getSampleSet().size(); i++)
        delete this->getSampleSet().at(i);
}
TimeTrigger::TimeTrigger()
{
    this->nothingNew = 0;
    this->periodicity = 0;
    this->priority = 0 ;
}
void TimeTrigger::parsingTimeTrigger(DOMElement* raiz)
{
    DOMElement *element = NULL;
    for(int i = 0 ; i < raiz->getElementsByTagName(XMLString::transcode("SampleSet"))->getLength(); i++){
        element  = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
            XMLString::transcode("SampleSet"))->item(i));
        SampleSet *sampleS = new SampleSet();
        sampleS->setSampleId(XMLString::transcode(element->getElementsByTagName(
            XMLString::transcode("SampleSetIdentifier"))->item(0)->getTextContent()));
        std::cout<<"SampleSetIdentifier: "<<sampleS->getSampleSetId()<<std::endl;
        for(int j = 0; j < element->getElementsByTagName(XMLString::transcode("SampleSetQualifier"))->getLength(); j++){
            sampleS->getSampleSetQualifier().push_back(XMLString::transcode(element->getElementsByTagName(
                XMLString::transcode("SampleSetQualifier"))->item(j)->getTextContent()));
        }
        this->sampleSet.push_back(sampleS);
    }
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("Periodicity"))->item(0));
    if(element != NULL){
        this->periodicity = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("Priority"))->item(0));
    if(element != NULL){
        this->priority = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("NothingNewReportMode"))->item(0));
    if(element != NULL){
        this->nothingNew = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }
}




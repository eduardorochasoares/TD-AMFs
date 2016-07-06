#include "AMFConfigPckg.h"
#include "stdlib.h"
#include "Algoritmos.h"
int AMFConfigPckg::getPackageID()
{
    return this->packageID;
}

int AMFConfigPckg::getPackageVersion()
{
    return this->packageVersion;
}

std::vector<MeasurementSet*>& AMFConfigPckg::getMeasurementSet()
{
    return this->measurementSet;
}

void AMFConfigPckg::setPackageID(int id)
{
    this->packageID = id;
}

void AMFConfigPckg::setPackageVersion(int id)
{
    this->packageVersion = id;
}

void AMFConfigPckg::setEffectiveDateTime(struct tm* effectiveDateTime)
{
    this->effectiveDateTime = effectiveDateTime;
}

void AMFConfigPckg::setMeasurementSet(std::vector<MeasurementSet*> measurementSet)
{
    this->measurementSet = measurementSet;
}

AMFConfigPckg::~AMFConfigPckg()
{
    free(this->effectiveDateTime);

    for(int i = 0; i < this->measurementSet.size(); i++){
        delete this->measurementSet.at(i);
    }
}

AMFConfigPckg::AMFConfigPckg()
{
    this->effectiveDateTime = NULL;
    this->packageID = 0;
    this->packageVersion = 0;
}
void AMFConfigPckg::parsingAmfConfigPckg(DOMElement* raiz)
{
    DOMElement *element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
        XMLString::transcode("PackageID"))->item(0));
    if(element != NULL){
        this->packageID = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);

    }
    element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
        XMLString::transcode("PackageVersion"))->item(0));
        if(element != NULL){
            this->packageVersion  = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
        }
    element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
        XMLString::transcode("EffectivityDateAndTime"))->item(0));
    if(element != NULL){
        std::string value = XMLString::transcode(element->getTextContent());
        this->effectiveDateTime = (struct tm*)malloc(sizeof(struct tm));
        setTimeAndDate(this->effectiveDateTime, value);
    }
    for(int i = 0; i < raiz->getElementsByTagName(XMLString::transcode("MeasurementRequestSet"))->getLength(); i++){
        MeasurementSet *mrs = new MeasurementSet();
        element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
            XMLString::transcode("MeasurementRequestSet"))->item(i));
        mrs->parsingMeasurementSet(element);
        this->measurementSet.push_back(mrs);
    }

}


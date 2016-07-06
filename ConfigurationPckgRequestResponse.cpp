#include "ConfigurationPckgRequestResponse.h"
#include<string>
#include <iostream>
Directive* ConfigurationPckgRequestResponse::getImmediateMeasurement()
{
    return this->immediateMeasurement;
}

Directive* ConfigurationPckgRequestResponse::getFutureMeasurement()
{
    return this->futureMeasurement;
}

int ConfigurationPckgRequestResponse::getConfigPckgCheckDelay()
{
    return this->configPckgCheckDelay;
}

void ConfigurationPckgRequestResponse::setConfigPckgCheckDelay(int configCheckDelay)
{
    this->configPckgCheckDelay = configCheckDelay;
}

void ConfigurationPckgRequestResponse::setFutureMeasurement(Directive* f)
{
    this->futureMeasurement = f;
}

void ConfigurationPckgRequestResponse::setImmeadiateMeasurement(Directive* i)
{
    this->immediateMeasurement = i;
}


ConfigurationPckgRequestResponse::~ConfigurationPckgRequestResponse()
{
    delete this->futureMeasurement;
    delete this->immediateMeasurement;
}

ConfigurationPckgRequestResponse::ConfigurationPckgRequestResponse()
{
    this->configPckgCheckDelay = 0;
    this->futureMeasurement  = NULL;
    this->immediateMeasurement = NULL;
}

void ConfigurationPckgRequestResponse::parsingConfigurationPckgRequestResponse(XmlDomDocument* doc)
{
    DOMDocument *m_doc = doc->getDOMDocument();
    DOMElement *element = dynamic_cast<DOMElement*>(m_doc->getElementsByTagName(XMLString::transcode("ConfigPackageRequestResponse"))->item(0));
    DOMElement *aux  = NULL;
    if(element != NULL){
        aux = dynamic_cast<DOMElement*>(element->getElementsByTagName(XMLString::transcode("ConfigurationPackageCheckDelay"))->item(0));
        if(aux != NULL){
            this->configPckgCheckDelay = stoi(XMLString::transcode(aux->getTextContent()),nullptr, 10);
        }
    }
    aux = dynamic_cast<DOMElement*>(element->getElementsByTagName(
        XMLString::transcode("ImmediateMeasurementDirective"))->item(0));
    if(aux != NULL){
        DOMElement *child  = dynamic_cast<DOMElement*> (aux->getElementsByTagName(XMLString::transcode("Code"))->item(0));
        if(child != NULL){
            this->immediateMeasurement = new Directive();
            this->immediateMeasurement->setCode(stoi(XMLString::transcode(child->getTextContent()),nullptr, 10));
        }
        child = dynamic_cast<DOMElement*>(aux->getElementsByTagName(XMLString::transcode("AMFConfigPackage"))->item(0));
        if(child != NULL){
            AMFConfigPckg *amf  = new AMFConfigPckg();
            this->immediateMeasurement->setAMFConfigPckg(amf);
            amf->parsingAmfConfigPckg(child);
        }

    }

    aux = dynamic_cast<DOMElement*>(element->getElementsByTagName(
        XMLString::transcode("FutureMeasurementDirective"))->item(0));
    if(aux != NULL){
        DOMElement *child = dynamic_cast<DOMElement*> (aux->getElementsByTagName(XMLString::transcode("Code"))->item(0));
        if(child != NULL){
            this->futureMeasurement = new Directive();
            this->futureMeasurement->setCode(stoi(XMLString::transcode(child->getTextContent()),nullptr, 10));
        }
        child = dynamic_cast<DOMElement*>(aux->getElementsByTagName(XMLString::transcode("AMFConfigPackage"))->item(0));
        if(child != NULL){
            AMFConfigPckg *amf  = new AMFConfigPckg();
            this->futureMeasurement->setAMFConfigPckg(amf);
            amf->parsingAmfConfigPckg(child);
        }
    }


}


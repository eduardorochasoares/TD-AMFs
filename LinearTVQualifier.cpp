#include "LinearTVQualifier.h"

short LinearTVQualififer::getNavMethod()
{
    return this->navMethod;
}

short LinearTVQualififer::getControlDevice()
{
    return this->controlDevice;
}

short LinearTVQualififer::getViewMode()
{
    return this->viewMode;
}

short LinearTVQualififer::getObscuration()
{
    return this->obscuration;
}
std::vector<std::string>& LinearTVQualififer::getChannelList(){
    return this->channelList;
}
std::vector<std::string>& LinearTVQualififer::getChannelExceptList()
{
    return this->allChannelsExceptList;
}

void LinearTVQualififer::setNavMethod(short navMethod)
{
    this->navMethod = navMethod;
}

void LinearTVQualififer::setControlDevice(short controlDev)
{
    this->controlDevice = controlDev;
}

void LinearTVQualififer::setViewMode(short viewMode)
{
    this->viewMode = viewMode;
}

void LinearTVQualififer::setObscuration(short obsc)
{
    this->obscuration = obsc;

}

LinearTVQualififer::LinearTVQualififer()
{
    this->controlDevice = 0;
    this->navMethod = 0;
    this->obscuration = 0;
    this->viewMode = 0;

}
void LinearTVQualififer::parsingLinearTVQualififer(DOMElement* raiz)
{
    DOMElement* element = NULL;

    element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
        XMLString::transcode("NavMethod"))->item(0));
    if(element != NULL){
        this->navMethod = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }
    element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
        XMLString::transcode("ControlDevice"))->item(0));
    if(element != NULL){
        this->controlDevice = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }
    element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
        XMLString::transcode("ViewMode"))->item(0));
    if(element != NULL){
        this->viewMode = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }
    element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(
        XMLString::transcode("Obscuration"))->item(0));
    if(element != NULL){
        this->obscuration = stoi(XMLString::transcode(element->getTextContent()), nullptr, 10);
    }

    element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
        XMLString::transcode("ChannelQualifier"))->item(0));
    if(element != NULL){
        DOMElement *child = NULL;
        child = dynamic_cast<DOMElement*>(element->getElementsByTagName(
            XMLString::transcode("ChannelList"))->item(0));
        if(child != NULL){
            for(int i = 0; i < child->getElementsByTagName(XMLString::transcode("ServiceIdentifier"))->getLength(); i++){
                this->channelList.push_back(XMLString::transcode(child->getElementsByTagName(
                    XMLString::transcode("ServiceIdentifier"))->item(i)->getTextContent()));
            }
        }
        child = dynamic_cast<DOMElement*> (element->getElementsByTagName(
            XMLString::transcode("AllChannelsExceptList"))->item(0));
        if(child != NULL){
            for(int i = 0; i < child->getElementsByTagName(XMLString::transcode("ServiceIdentifier"))->getLength(); i++){
                this->allChannelsExceptList.push_back(XMLString::transcode(child->getElementsByTagName(
                    XMLString::transcode("ServiceIdentifier"))->item(i)->getTextContent()));
            }
        }

    }

    delete element;
}

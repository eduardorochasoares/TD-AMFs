#include "AllContentClassExceptList.h"
AllContentClassExceptList::AllContentClassExceptList()
{

}

void AllContentClassExceptList::setContentClass(std::vector<ContentClass*> c)
{
    this->contentClass = c;
}

std::vector<ContentClass*>& AllContentClassExceptList::getContentClass()
{
    return this->contentClass;
}
AllContentClassExceptList::~AllContentClassExceptList()
{
    for(int i = 0; i < this->contentClass.size(); i++)
        delete this->contentClass.at(i);
}


void AllContentClassExceptList::parsingExceptList(DOMElement* raiz)
{
    DOMElement *element = NULL;
    DOMElement *aux = NULL;
    for(int i = 0 ; i < raiz->getElementsByTagName(XMLString::transcode("ContentClassDomain"))->getLength(); i++){
        element = dynamic_cast<DOMElement*>(raiz->getElementsByTagName(XMLString::transcode("ContentClassDomain"))->item(i));
        ContentClass *contClass = (ContentClass*)malloc(sizeof(ContentClass));
        this->contentClass.push_back(contClass);
        contClass->contentClassDomain = XMLString::transcode(element->getTextContent());
        for(int j = 0; j < element->getElementsByTagName(XMLString::transcode("ContentClassID"))->getLength(); j++){
            aux = dynamic_cast<DOMElement*>(element->getElementsByTagName(XMLString::transcode("ContentClassID"))->item(j));
            contClass->contentClassID.push_back(XMLString::transcode(aux->getTextContent()));
        }
    }
}

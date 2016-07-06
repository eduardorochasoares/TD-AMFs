#include "XmlDomDocument.h"
#include "stdio.h"

XercesDOMParser*   parser = NULL;
ErrorHandler*      errorHandler = NULL;

class XmlDomErrorHandler : public HandlerBase{
  public:
    void fatalError(const SAXParseException &exc) {
        printf("Fatal parsing error at line %d\n", (int)exc.getLineNumber());
        exit(-1);
    }
};

void createParser(){
    if (!parser)
    {
        XMLPlatformUtils::Initialize();
        parser = new XercesDOMParser();
        errorHandler = (ErrorHandler*) new XmlDomErrorHandler();
        parser->setErrorHandler(errorHandler);
    }
}

XmlDomDocument::XmlDomDocument(const char* xmlfile) : m_doc(NULL)
{
    createParser();
   // xercesc::MemBufInputSource myxml_buf((const XMLByte*)xmlfile, 4096,"myxml (in memory)", false);
    parser->parse(xmlfile);
    m_doc = parser->getDocument();
}

XmlDomDocument::~XmlDomDocument(){
     if (m_doc) m_doc->release();
}

string XmlDomDocument::getChildValue(const char* parentTag, int parentIndex, const char* childTag, int childIndex){
    XMLCh* temp = XMLString::transcode(parentTag);
    DOMNodeList* list = m_doc->getElementsByTagName(temp);
    XMLString::release(&temp);

    DOMElement* parent =
        dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMElement* child =
        dynamic_cast<DOMElement*>(parent->getElementsByTagName(
            XMLString::transcode(childTag))->item(childIndex));

    string value;
    if (child) {
        char* temp2 = XMLString::transcode(child->getTextContent());
        value = temp2;
        XMLString::release(&temp2);
    }
    else {
        value = "";
    }
    return value;
}

string XmlDomDocument::getChildAttribute(const char* parentTag, int parentIndex, int childIndex, const char* childTag, const char* attributeTag){
    XMLCh* temp = XMLString::transcode(parentTag);
    DOMNodeList* list = m_doc->getElementsByTagName(temp);
    XMLString::release(&temp);

    DOMElement* parent =
        dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMElement* child =
        dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));

    string value;
    if (child) {
        temp = XMLString::transcode(attributeTag);
        char* temp2 = XMLString::transcode(child->getAttribute(temp));
        value = temp2;
        XMLString::release(&temp2);
    }else {
        value = "";
    }
    return value;
}

int XmlDomDocument::getChildCount(const char* parentTag, int parentIndex, const char* childTag)
{
    XMLCh* temp = XMLString::transcode(parentTag);
    DOMNodeList* list = m_doc->getElementsByTagName(temp);
    XMLString::release(&temp);

    DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
    DOMNodeList* childList = parent->getElementsByTagName(XMLString::transcode(childTag));
    return (int)childList->getLength();
}


int XmlDomDocument::calculateStart(const char* parentTag, int parentIndex, const char* childTag)
{
     if(parentIndex == 0)
        return 0;
    else{
        int start = 0;
        for(int i = 0; i < parentIndex; i++){
            start += this->getChildCount(parentTag, parentIndex, childTag);
        }
        return start;
    }
}

XmlDomDocument::XmlDomDocument()
{

}

XmlDomDocument::XmlDomDocument(const XmlDomDocument&)
{


}



DOMElement* XmlDomDocument::getElementByTag(const char* tag, int parentIndex)
{
    XMLCh* temp = XMLString::transcode(tag);
    DOMNodeList* list = m_doc->getElementsByTagName(temp);
    XMLString::release(&temp);

    DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
    return parent;
}
DOMDocument* XmlDomDocument::getDOMDocument()
{
    return this->m_doc;
}



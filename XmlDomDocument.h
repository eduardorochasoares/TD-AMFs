#ifndef XMLDOMDOCUMENT_H_INCLUDED
#define XMLDOMDOCUMENT_H_INCLUDED
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <string>


using namespace std;
using namespace xercesc;

class XmlDomDocument
{
    DOMDocument* m_doc;

  public:

    XmlDomDocument(const char* xmlfile);
    ~XmlDomDocument();

    string getChildValue(const char* parentTag, int parentIndex,
                         const char* childTag, int childIndex);
    string getChildAttribute(const char* parentTag,
                             int parentIndex, int childIndex,
                             const char* childTag,
                             const char* attributeTag);
    int getChildCount(const char* parentTag, int parentIndex,
                      const char* childTag);
    int calculateStart(const char* parentTag, int parentIndex,
                    const char* childTag);
    DOMElement* getElementByTag(const char *tag, int parentIndex);
    DOMDocument *getDOMDocument();

  private:
    XmlDomDocument();
    XmlDomDocument(const XmlDomDocument&);
};


#endif // XMLDOMDOCUMENT_H_INCLUDED

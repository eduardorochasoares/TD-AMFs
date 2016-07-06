#ifndef ALLCONTENTCLASSEXCEPTLIST_H_INCLUDED
#define ALLCONTENTCLASSEXCEPTLIST_H_INCLUDED
#include "eventDefs.h"
#include "XmlDomDocument.h"
class AllContentClassExceptList{
    private :
        std::vector<ContentClass*> contentClass;

    public :
        AllContentClassExceptList();
        void setContentClass(std::vector<ContentClass*> c);
        std::vector<ContentClass*>& getContentClass();

        ~AllContentClassExceptList();
        void parsingExceptList(DOMElement* raiz);

};


#endif // ALLCONTENTCLASSEXCEPTLIST_H_INCLUDED

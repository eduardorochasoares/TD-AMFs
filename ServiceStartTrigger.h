#ifndef SERVICESTARTTRIGGER_H_INCLUDED
#define SERVICESTARTTRIGGER_H_INCLUDED
#include "TimeTrigger.h"
#include "XmlDomDocument.h"
class ServiceStartTrigger{

    private:
        unsigned interval;
        std::vector<SampleSet*> sampleSet;
        unsigned priority;

    public:
        unsigned getInterval();
        std::vector<SampleSet*>& getSampleSet();
        unsigned getPriority();

        void setInterval(unsigned interval);
        void setSampleSet(std::vector<SampleSet*> sampleSet);
        void setPriority(unsigned priority);
        ~ServiceStartTrigger();
        ServiceStartTrigger();
        void parsingServiceStartTrigger(DOMElement *raiz);
};


#endif // SERVICESTARTTRIGGER_H_INCLUDED

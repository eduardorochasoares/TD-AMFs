#ifndef TIMETRIGGER_H_INCLUDED
#define TIMETRIGGER_H_INCLUDED
#include <string>
#include <vector>
#include "XmlDomDocument.h"

class SampleSet{
    private :
        std::string sampleSetId;
        std::vector<std::string> sampleSetQualifier;
    public :
        std::string getSampleSetId();
        std::vector<std::string> getSampleSetQualifier();

        void setSampleId(std::string id);
        void setSampleSetQualifier(std::vector<std::string> qualifier);
};
class TimeTrigger{
    private:
        std::vector<SampleSet*> sampleSet;
        unsigned periodicity;
        unsigned priority;
        short nothingNew;

    public:

        std::vector<SampleSet*>& getSampleSet();
        unsigned getPeriodicity();
        unsigned getPriority();
        short getNothingNew();


        void setSampleSet(std::vector<SampleSet*> sampleSet);
        void setPeriodicity(unsigned periodicity);
        void setPriority(unsigned priority);
        void setNothingNew(short nothingNew);

        ~TimeTrigger();
        TimeTrigger();
        void parsingTimeTrigger(DOMElement *raiz);


};


#endif // TIMETRIGGER_H_INCLUDED

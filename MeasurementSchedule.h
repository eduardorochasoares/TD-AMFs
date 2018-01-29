#ifndef MEASUREMENTSCHEDULE_H_INCLUDED
#define MEASUREMENTSCHEDULE_H_INCLUDED
#include "EventTrigger.h"
#include "TimeTrigger.h"
#include "MeasurementPeriod.h"
#include "ServiceStartTrigger.h"
#include <vector>
#include "XmlDomDocument.h"
class MeasurementSchedule{
    private:
        std::vector<MeasurementPeriod*> measurementPeriod;
        std::vector<EventTrigger*> eventTrigger;
        TimeTrigger *timeTrigger;
        ServiceStartTrigger *serviceStart;

    public:
        std::vector<MeasurementPeriod*>& getMeasurementPeriod();
        std::vector<EventTrigger*>& getEventTrigger();
        TimeTrigger *getTimeTrigger();
        ServiceStartTrigger *getServiceStart();

        void setMeasurementPeriod(std::vector<MeasurementPeriod*> mp);
        void setEventTrigger(std::vector<EventTrigger*> eventTrigger);
        void setTimeTrigger(TimeTrigger *tt);
        void setServiceStartTrigger(ServiceStartTrigger *sst);
        ~MeasurementSchedule();
        MeasurementSchedule();
        void parsingMeasurementSchedule(DOMElement *raiz);

};

#endif // MEASUREMENTSCHEDULE_H_INCLUDED

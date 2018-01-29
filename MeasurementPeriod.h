#ifndef MEASUREMENTPERIOD_H_INCLUDED
#define MEASUREMENTPERIOD_H_INCLUDED
#include <vector>
#include <ctime>
#include "XmlDomDocument.h"

class MeasurementPeriod{

    private:
        std::vector<int> dayOfTheWeek;
        std::vector<struct tm*> startTime;
        std::vector<struct tm*> endTime;
    public:
        std::vector<int>& getDayOfTheWeek();
        std::vector<struct tm*>& getStartTimes();
        std::vector<struct tm*>& getEndTimes();

        void setDayOfTheWeek(std::vector<int> v);
        void setStartTimes(std::vector<struct tm*> s);
        void setEndTimes(std::vector<struct tm*> e);
        ~MeasurementPeriod();
        MeasurementPeriod();
        void parsingMeasurementPeriod(DOMElement *raiz, bool def);


};


#endif // MEASUREMENTPERIOD_H_INCLUDED

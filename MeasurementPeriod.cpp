#include "MeasurementPeriod.h"
#include "stdlib.h"
#include "Algoritmos.h"
std::vector<int>& MeasurementPeriod::getDayOfTheWeek()
{
    return this->dayOfTheWeek;
}

std::vector<struct tm*>& MeasurementPeriod::getStartTimes()
{
    return this->startTime;
}

std::vector<struct tm*>& MeasurementPeriod::getEndTimes()
{
    return this->endTime;
}

void MeasurementPeriod::setDayOfTheWeek(std::vector<int> v)
{
    this->dayOfTheWeek = v;
}

void MeasurementPeriod::setStartTimes(std::vector<struct tm* > s)
{
    this->startTime = s;
}

void MeasurementPeriod::setEndTimes(std::vector<struct tm* > e)
{
    this->endTime = e;
}

MeasurementPeriod::~MeasurementPeriod()
{
    for(int i = 0; i < this->endTime.size(); i++)
        free(this->endTime.at(i));

    for(int i = 0; i < this->startTime.size(); i++)
        free(this->startTime.at(i));
}

MeasurementPeriod::MeasurementPeriod()
{

}

void MeasurementPeriod::parsingMeasurementPeriod(DOMElement *raiz, bool def)
{
    DOMElement *element = NULL;

    std::string start, day, endd;
    if(def){
        start = "DefaultMeasurementStartTime";
        endd = "DefaultMeasurementEndTime";
        day = "DefaultDayOfTheWeek";
    }else{
        start = "StartTime";
        endd = "EndTime";
        day = "DayOfTheWeek";
    }
    for(int i = 0; i < raiz->getElementsByTagName(XMLString::transcode(day.c_str()))->getLength(); i++){
        element = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
            XMLString::transcode(day.c_str()))->item(i));


        this->dayOfTheWeek.push_back(stoi(XMLString::transcode(element->getTextContent()), nullptr, 10));

    }

    for(int i = 0;  i < raiz->getElementsByTagName(XMLString::transcode(start.c_str()))->getLength(); i++){
        element  = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
            XMLString::transcode(start.c_str()))->item(i));
        std::string value = XMLString::transcode(element->getTextContent());
        struct tm* time = (struct tm*)malloc(sizeof(struct tm));
        setTimeAndDate(time, value);
        this->startTime.push_back(time);
    }

    for(int i = 0;  i < raiz->getElementsByTagName(XMLString::transcode(endd.c_str()))->getLength(); i++){
        element  = dynamic_cast<DOMElement*> (raiz->getElementsByTagName(
            XMLString::transcode(endd.c_str()))->item(i));
        std::string value = XMLString::transcode(element->getTextContent());
        struct tm* time = (struct tm*)malloc(sizeof(struct tm));
        setTimeAndDate(time, value);
        this->endTime.push_back(time);
    }

}


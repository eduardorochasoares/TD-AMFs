#include "MeasurementTriggerMethod.h"
void MeasurementTriggerMethod::setEventTrigger(vector<MeasurementTriggerMethod::EventTrigger> evtTrigger)
{
    this->eventTrigger = evtTrigger;
}

void MeasurementTriggerMethod::setTimeSampleTrigger(vector<MeasurementTriggerMethod::TimeSampleTrigger> TTtrigger)
{
    this->timeSampleTrigger = TTtrigger;
}

void MeasurementTriggerMethod::setServiceStartTrigger(vector <MeasurementTriggerMethod::ServiceStartTrigger> serviceStartTrigger)
{
    this->serviceStartTrigger = serviceStartTrigger;
}

vector<MeasurementTriggerMethod::EventTrigger>& MeasurementTriggerMethod::getEventTrigger()
{
    return this->eventTrigger;
}

vector<MeasurementTriggerMethod::TimeSampleTrigger>& MeasurementTriggerMethod::getTimeSampleTrigger()
{
    return this->timeSampleTrigger;
}

vector<MeasurementTriggerMethod::ServiceStartTrigger>& MeasurementTriggerMethod::getServiceStartTrigger()
{
    return this->serviceStartTrigger;
}

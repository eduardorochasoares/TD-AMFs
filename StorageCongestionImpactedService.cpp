#include "StorageCongestionImpactedService.h"

void StorageCongestionImpactedService::setImpactedServiceID(int impactedServiceID)
{
    this->impactedServiceID = impactedServiceID;
}

void StorageCongestionImpactedService::setServiceStopDropped(bool s)
{
    this->serviceStopDropped = s;
}

int StorageCongestionImpactedService::getImpactedServiceID()
{
    return this->impactedServiceID;
}

bool StorageCongestionImpactedService::getServiceStopDropped()
{
    return this->serviceStopDropped;
}
StorageCongestionImpactedService::StorageCongestionImpactedService()
{
    this->impactedServiceID = 0;
    this->serviceStopDropped = false;
}



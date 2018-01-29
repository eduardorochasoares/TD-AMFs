#include "ServiceRunning.h"

ServiceRunning::ServiceRunning(std::string serviceName)
{
    this->serviceName = serviceName;
}

ServiceRunning::~ServiceRunning()
{

}

void ServiceRunning::setServiceName(std::string serviceName)
{
    this->serviceName = serviceName;
}

string ServiceRunning::getServiceName()
{
    return this->serviceName;
}


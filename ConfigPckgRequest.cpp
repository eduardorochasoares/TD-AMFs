#include "ConfigPckgRequest.h"
#include "MeasurementTriggerMethod.h"
#include <fstream>

void ConfigPkgRequest::setTerminalDeviceTypes(vector<TerminalDeviceType> t)
{
    this->terminalDeviceTypes = t;
}

void ConfigPkgRequest::setSubscriberID(string id)
{
    this->subscriberID = id;
}

void ConfigPkgRequest::setAmfCapability(AMFCapabilityProfile* amf)
{
    this->amfCapabilityProfile = amf;
}

void ConfigPkgRequest::setTerminalID(string terminalDevice)
{
    this->terminalDeviceID = terminalDevice;

}

void ConfigPkgRequest::setServiceProviderID(string id)
{
    this->serviceProviderIdentifier = id;
}

void ConfigPkgRequest::setCurrent(Measurements* current)
{
    this->current = current;
}

void ConfigPkgRequest::setFuture(Measurements* future)
{
    this->future = future;
}

vector<ConfigPkgRequest::TerminalDeviceType>& ConfigPkgRequest::getTerminalDeviceType()
{
    return this->terminalDeviceTypes;
}

string ConfigPkgRequest::getSubscriberID()
{
    return this->subscriberID;
}

AMFCapabilityProfile* ConfigPkgRequest::getAmfCapabProfile()
{
    return this->amfCapabilityProfile;
}

string ConfigPkgRequest::getTerminalID()
{
    return this->terminalDeviceID;
}

string ConfigPkgRequest::getServiceProviderID()
{
    return this->serviceProviderIdentifier;
}

Measurements* ConfigPkgRequest::getCurrentMeasurement()
{
    return this->current;
}

Measurements* ConfigPkgRequest::getFutureMeasurement()
{
    return this->future;
}

void ConfigPkgRequest::writeXML()
{
    ofstream xml("ConfigurationRequest.xml");
    if(xml.is_open()){
        xml<<"<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>"<<endl;
        xml<<"<ConfigPackageRequest>"<<endl;
        xml<<"<TerminalDeviceID>"<<this->getTerminalID()<<"</TerminalDeviceID>"<<endl;
        for(int i = 0; i < this->getTerminalDeviceType().size(); i++){
            TerminalDeviceType t = this->getTerminalDeviceType().at(i);
            xml<<"<TerminalDeviceType>"<<t<<"</TerminalDeviceType>"<<endl;
        }
        xml<<"<ServiceProviderIdentifier>"<<this->getServiceProviderID()<<"</ServiceProviderIdentifier>"<<endl;
        xml<<"<SubscriberID>"<<this->getSubscriberID()<<"</SubscriberID>"<<endl;
        if(this->getAmfCapabProfile()!= NULL){
                this->getAmfCapabProfile()->writeAMFCapab(xml);
        }
            if(this->current != NULL){
                xml<<"<CurrentMeasurement>"<<endl;
                xml<<"<PackageID>"<<this->current->packageID<<"</PackageID>"<<endl;
                xml<<"<PackageVersion>"<<this->current->packageVersion<<"</PackageVersion>"<<endl;
                xml<<"</CurrentMeasurement>"<<endl;
            }
            if(this->future != NULL){
                xml<<"<FutureMeasurement>"<<endl;
                xml<<"<PackageID>"<<this->current->packageID<<"</PackageID>"<<endl;
                xml<<"<PackageVersion>"<<this->current->packageVersion<<"</PackageVersion>"<<endl;
                xml<<"</FutureMeasurement>"<<endl;
            }
            xml<<"</ConfigPackageRequest>"<<endl;
        }

    xml.close();
}

ConfigPkgRequest::ConfigPkgRequest(vector<TerminalDeviceType> t, string subscriberID, string terminalDeviceID, string serviceProviderID, AMFCapabilityProfile* amf, Measurements* current, Measurements* future)
{
    this->terminalDeviceTypes = t;
    this->subscriberID = subscriberID;
    this->terminalDeviceID = terminalDeviceID;
    this->serviceProviderIdentifier = serviceProviderID;
    this->amfCapabilityProfile = amf;
    this->current = current;
    this->future = future;
}
ConfigPkgRequest::ConfigPkgRequest(){
    this->amfCapabilityProfile = NULL;
    this->current = NULL;
    this->future = NULL;
};
ConfigPkgRequest::~ConfigPkgRequest(){
    delete this->amfCapabilityProfile;
    delete this->current;
    delete this->future;
}

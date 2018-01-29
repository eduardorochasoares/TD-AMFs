#ifndef CONFIGPCKGREQUEST_H_INCLUDED
#define CONFIGPCKGREQUEST_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
#include "AMFCapabilityProfile.h"
using namespace std;

    typedef struct measurements{
        int packageID;
        int packageVersion;

    }Measurements;
class ConfigPkgRequest{
    public :
        enum  TerminalDeviceType{
            STB = 0, TV = 1, Mobile = 2, PC = 3, Tablet = 4, Other = 5
        };
    private : vector<TerminalDeviceType> terminalDeviceTypes;
    private : string subscriberID;
    private : string terminalDeviceID;
    private : string serviceProviderIdentifier;
    private : AMFCapabilityProfile *amfCapabilityProfile;
    private : Measurements *current;
    private : Measurements *future;

    public : ConfigPkgRequest(vector<TerminalDeviceType> t, string subscriberID, string terminalDeviceID, string serviceProviderID, AMFCapabilityProfile* amf, Measurements *current, Measurements* future);
    public :~ConfigPkgRequest();
    public : ConfigPkgRequest();
    public : void setTerminalDeviceTypes(vector<TerminalDeviceType> t);

    public : void setSubscriberID(string id);

    public : void setAmfCapability(AMFCapabilityProfile *amf);

    public : void setTerminalID(string terminalDevice);

    public : void setServiceProviderID(string id);

    public : void setCurrent(Measurements *current);

    public : void setFuture(Measurements *future);

    public : vector<TerminalDeviceType>& getTerminalDeviceType();
    public : string getSubscriberID();
    public : AMFCapabilityProfile *getAmfCapabProfile();
    public : string getTerminalID();
    public : string getServiceProviderID();
    public : Measurements *getCurrentMeasurement();
    public : Measurements *getFutureMeasurement();

    public : void writeXML();



};


#endif // CONFIGPCKGREQUEST_H_INCLUDED

#include "AMFCapabilityProfile.h"
void AMFCapabilityProfile::setTransportProtool(vector<AMFCapabilityProfile::TransportProtocolMode> transportProtocols)
{
    this->transportCapabilities = transportProtocols;
}

void AMFCapabilityProfile::setSecurityCapabibilities(vector<AMFCapabilityProfile::CryptographicProtocol> securityCapab)
{
    this->securityCapabilities = securityCapab;
}

void AMFCapabilityProfile::setPermissionModes(vector<AMFCapabilityProfile::PermissionMode> permissionMode)
{
    this->permissionOperationModes = permissionMode;
}

void AMFCapabilityProfile::setConfigMode(vector<AMFCapabilityProfile::ConfigurationMode> configMode)
{
    this->configurationPackageDelivery = configMode;
}

void AMFCapabilityProfile::setDeliveryMode(vector<AMFCapabilityProfile::DeliveryMode> deliveryMode)
{
    this->reportDeliveryModes = deliveryMode;
}

void AMFCapabilityProfile::setMeasurementTrigger(MeasurementTriggerMethod *measurementTrigger)
{
    this->measurementTriggerMethod = measurementTrigger;
}

void AMFCapabilityProfile::setCompression(vector<AMFCapabilityProfile::Compression> compression)
{
    this->compression = compression;
}


vector<AMFCapabilityProfile::TransportProtocolMode>& AMFCapabilityProfile::getTransportProtocol(){
    return this->transportCapabilities;
}

vector<AMFCapabilityProfile::CryptographicProtocol>& AMFCapabilityProfile::getSecurityCapabilities(){
    return this->securityCapabilities;
}
vector<AMFCapabilityProfile::PermissionMode>& AMFCapabilityProfile::getPermissionMode(){
    return this->permissionOperationModes;
}
vector<AMFCapabilityProfile::ConfigurationMode>& AMFCapabilityProfile::getConfigurationMode(){
    return this->configurationPackageDelivery;
}
vector<AMFCapabilityProfile::DeliveryMode>& AMFCapabilityProfile::getDeliveryMode(){
    return this->reportDeliveryModes;
}
MeasurementTriggerMethod* AMFCapabilityProfile::getMeasurementTrigger(){
    return this->measurementTriggerMethod;
}
vector<AMFCapabilityProfile::Compression>& AMFCapabilityProfile::getCompression(){
    return this->compression;
}


void AMFCapabilityProfile::setOperationalCapab(vector<OperationalManagement> operationCapab)
{
    this->operationCapab = operationCapab;
}

vector<AMFCapabilityProfile::OperationalManagement>& AMFCapabilityProfile::getOperationCapab()
{
    return this->operationCapab;
}
AMFCapabilityProfile::AMFCapabilityProfile()
{
    this->measurementTriggerMethod = NULL;
}

AMFCapabilityProfile::~AMFCapabilityProfile()
{
    delete this->measurementTriggerMethod;

}
void AMFCapabilityProfile::writeAMFCapab(ofstream &xml)
{

            xml<<"<AMFCapabilityProfile>"<<endl;
            xml<<"<TransportCapabilitiesList>"<<endl;
            string transportProtocol;
            for(int i = 0; i < this->getTransportProtocol().size(); i++){
                switch(this->getTransportProtocol().at(i)){
                    case 0:
                        transportProtocol = "TCP";
                        break;
                    case 1:
                        transportProtocol = "UDP";
                        break;
                }
                xml<<"<TransportProtocolMode>"<<transportProtocol<<"</TransportProtocolMode>"<<endl;
            }

            xml<<"</TransportCapabilitiesList>"<<endl;
            xml<<"<SecurityCapabilities>"<<endl;
            string security;
            for(int i = 0; this->getSecurityCapabilities().size(); i++){
                switch(this->getSecurityCapabilities().at(i)){
                    case AMFCapabilityProfile::HMAC:
                        security = "HMAC";
                        break;
                    case AMFCapabilityProfile::OTP:
                        security = "OTP";
                        break;
                    case AMFCapabilityProfile::TLS:
                        security = "TLS";
                        break;
                    case AMFCapabilityProfile::TLSSRP:
                        security = "TLS-SRP";
                        break;
                }
                xml<<"<CryptographicProtocol>"<<security<<"</CryptographicProtocol>"<<endl;

            }
            xml<<"</SecurityCapabilities>"<<endl;
            xml<<"<PermissionOperationModes>"<<endl;
            string permissionMode;
            for(int i = 0; i < this->getPermissionMode().size(); i++){
                switch(this->getPermissionMode().at(i)){
                    case AMFCapabilityProfile::EXTERNAL:
                        permissionMode = "EXTERNAL";
                        break;
                    case AMFCapabilityProfile::INTERNAL:
                        permissionMode = "INTERNAL";
                        break;
                    case AMFCapabilityProfile::HYBRIDPermission:
                        permissionMode = "HYBRID";
                        break;
                }
                xml<<"<PermissionMode>"<<permissionMode<<"</PermissionMode>"<<endl;
            }
            xml<<"</PermissionOperationModes>"<<endl;
            xml<<"<ConfigurationPackageDelivery>"<<endl;
            string configMode;
            for(int i = 0; i < this->getConfigurationMode().size(); i++){
                switch(this->getConfigurationMode().at(i)){
                    case AMFCapabilityProfile::Push:
                        configMode = "PUSH";
                        break;
                    case AMFCapabilityProfile::Pull:
                        configMode = "PULL";
                        break;
                    case AMFCapabilityProfile::Hybrid:
                        configMode = "HYBRID";
                        break;
                }
                xml<<"<ConfigurationMode>"<<configMode<<"</ConfigurationMode>"<<endl;

            }
            xml<<"</ConfigurationPackageDelivery>"<<endl;
            xml<<"<MeasurementTriggerMethod>"<<endl;
            string eventTrigger;
            for(int i = 0; i < this->getMeasurementTrigger()->getEventTrigger().size(); i++){

                switch(this->getMeasurementTrigger()->getEventTrigger().at(i)){
                    case MeasurementTriggerMethod::VideoResize:
                        eventTrigger = "VideoResize";
                        break;
                    case MeasurementTriggerMethod::VideoZoom:
                        eventTrigger = "VideoZoom";
                        break;
                    case MeasurementTriggerMethod::VideoObscure:
                        eventTrigger = "VideoObscure";
                        break;
                    case MeasurementTriggerMethod::AudioVolume:
                        eventTrigger = "AudioVolume";
                        break;
                    case MeasurementTriggerMethod::ConfigurationChange:
                        eventTrigger = "ConfigurationChange";
                        break;
                    case MeasurementTriggerMethod::UserChange:
                        eventTrigger = "UserChange";
                        break;
                    case MeasurementTriggerMethod::UserInfoChange:
                        eventTrigger = "UserInfoChange";
                        break;
                    case MeasurementTriggerMethod::DisplayStatus:
                        eventTrigger = "DisplayStatus";
                        break;
                    case MeasurementTriggerMethod::AudioLanguageChange:
                        eventTrigger = "AudioLanguageChange";
                        break;
                    case MeasurementTriggerMethod::CaptionLanguageChange:
                        eventTrigger = "CaptionLanguageChange";
                        break;
                }
                xml<<"<EventTrigger>"<<eventTrigger<<"</EventTrigger>"<<endl;
            }
            string timeTrigger;
            for(int i = 0; i < this->getMeasurementTrigger()->getTimeSampleTrigger().size(); i++){
                switch(this->getMeasurementTrigger()->getTimeSampleTrigger().at(i)){
                    case MeasurementTriggerMethod::UserPresent:
                        timeTrigger = "UserPresent";
                        break;
                    case MeasurementTriggerMethod::TDLocation:
                        timeTrigger = "TDLocation";
                        break;
                    case MeasurementTriggerMethod::DeviceInfo:
                        timeTrigger = "DeviceInfo";
                        break;
                    case MeasurementTriggerMethod::UserBioInfo:
                        timeTrigger = "UserBioInfo";
                        break;
                    case MeasurementTriggerMethod::GenericUserInfo:
                        timeTrigger = "GenericUserInfo";
                        break;
                    case MeasurementTriggerMethod::EventCount:
                        timeTrigger = "EventCount";
                        break;
                    case MeasurementTriggerMethod::UserList:
                        timeTrigger = "UserList";
                        break;
                    case MeasurementTriggerMethod::PermitBlockedInfo:
                        timeTrigger = "PermitBlockedInfo";
                        break;
                    case MeasurementTriggerMethod::channelplaying:
                        timeTrigger = "ChannelPlaying";
                        break;

                }
                xml<<"<TimeSampleTrigger>"<<timeTrigger<<"</TimeSampleTrigger>"<<endl;
            }
            string serviceStartTrigger;
            for(int i = 0; i < this->getMeasurementTrigger()->getServiceStartTrigger().size(); i++){
                switch(this->getMeasurementTrigger()->getServiceStartTrigger().at(i)){
                    case MeasurementTriggerMethod::TDLocationSS:
                        serviceStartTrigger = "TDLocation";
                        break;
                    case MeasurementTriggerMethod::DeviceInfoSS:
                        serviceStartTrigger = "DeviceInfo";
                        break;
                    case MeasurementTriggerMethod::GenericUserInfoSS:
                        serviceStartTrigger = "GenericUserInfo";
                        break;
                    case MeasurementTriggerMethod::UserBioInfoSS:
                        serviceStartTrigger = "UserBioInfo";
                        break;

                    case MeasurementTriggerMethod::UserListSS:
                        serviceStartTrigger = "UserList";
                        break;
                    case MeasurementTriggerMethod::PermitBlockedInfoSS:
                        serviceStartTrigger = "PermitBlockedInfo";
                        break;


                }
                xml<<"<ServiceStartTrigger>"<<serviceStartTrigger<<"</ServiceStartTrigger>"<<endl;
            }
            xml<<"</MeasurementTriggerMethod>"<<endl;
            xml<<"<ReportDeliveryModes>"<<endl;
            string deliveryMode;
            for(int i = 0; i < this->getDeliveryMode().size(); i++){

                switch(this->getDeliveryMode().at(i)){
                    case AMFCapabilityProfile::ImmediatePush:
                        deliveryMode = "ImmediatePush";
                        break;
                    case AMFCapabilityProfile::DelayedPush:
                        deliveryMode = "DelayedPush";
                        break;
                    case AMFCapabilityProfile::PullDelivery:
                        deliveryMode = "Pull";
                        break;
                    case AMFCapabilityProfile::DelayedPushAndPull:
                        deliveryMode = "DelayedPushAndPull";
                        break;
                }
                xml<<"<DeliveryMode>"<<deliveryMode<<"</DeliveryMode>"<<endl;
            }
            xml<<"</ReportDeliveryModes>"<<endl;
            xml<<"<OperationalManagementCapabilities>"<<endl;
            string operationCapab;
            for(int i = 0; i < this->getOperationCapab().size(); i++){
                switch(this->getOperationCapab().at(i)){
                    case AMFCapabilityProfile::Acknowledgements:
                        operationCapab = "Acknowledgements";
                        break;
                    case AMFCapabilityProfile::MulticastThresholdRanges:
                        operationCapab = "MulticastThresholdRanges";
                        break;
                    case AMFCapabilityProfile::MulticastErrorReporting:
                        operationCapab = "MulticastErrorReporting";
                        break;
                    case AMFCapabilityProfile::MulticastUserInfo:
                        operationCapab = "MulticastUserInfo";
                        break;
                    case AMFCapabilityProfile::MulticastDeviceType:
                        operationCapab = "MulticastDeviceType";
                        break;
                    case AMFCapabilityProfile::MulticastMAC:
                        operationCapab = "MulticastMAC";
                        break;
                    case AMFCapabilityProfile::ContentFiltering:
                        operationCapab = "ContentFiltering";
                        break;
                    case AMFCapabilityProfile::ChannelsMeasured:
                        operationCapab = "ChannelsMeasured";
                        break;
                    case AMFCapabilityProfile::ChannelChangeFilter:
                        operationCapab = "ChannelChangeFilter";
                        break;
                    case AMFCapabilityProfile::NavMethodReporting:
                        operationCapab = "ChannelChangeFilter";
                        break;
                    case AMFCapabilityProfile::ControlDeviceReporting:
                        operationCapab = "ControlDeviceReporting";
                        break;
                }
            xml<<"<OperationalManagement>"<<operationCapab<<"</OperationalManagement>"<<endl;


        }
            xml<<"</OperationalManagementCapabilities>"<<endl;
            string compression;
            for(int i = 0; i < this->getCompression().size(); i ++){
                switch(this->getCompression().at(i)){
                    case AMFCapabilityProfile::None:
                        compression = "None";
                        break;
                    case AMFCapabilityProfile::BiM:
                        compression = "BiM";
                        break;
                    case AMFCapabilityProfile::ZLIB:
                        compression = "ZLIB";
                        break;
                    case AMFCapabilityProfile::Infoset:
                        compression = "Infoset";
                        break;
                    case AMFCapabilityProfile::EXI:
                        compression = "EXI";
                        break;

                }
                xml<<"<Compression>"<<compression<<"</Compression>"<<endl;

            }
            xml<<"</AMFCapabilityProfile>"<<endl;
}

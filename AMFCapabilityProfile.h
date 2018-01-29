#ifndef AMFCAPABILITYPROFILE_H_INCLUDED
#define AMFCAPABILITYPROFILE_H_INCLUDED
#include <vector>
#include <string>
#include "MeasurementTriggerMethod.h"
#include "TVInformation.h"
#include "StbInformation.h"
#include "PCInformation.h"
#include "IptvTVInformation.h"
#include "ImageSize.h"
#include "MobileDeviceInformation.h"
#include "AudioAmplifierInformation.h"
#include <fstream>


class AMFCapabilityProfile{
    public: enum TransportProtocolMode{
                TCP = 0, UDP
            };
    public: enum CryptographicProtocol {
        TLS, TLSSRP, OTP, HMAC
    };
    enum PermissionMode{
        EXTERNAL, INTERNAL, HYBRIDPermission
    };
    enum ConfigurationMode{
        Push ,Pull, Hybrid
    };

    enum OperationalManagement{
        Acknowledgements,MulticastThresholdRanges, MulticastErrorReporting,
        MulticastUserInfo, MulticastDeviceType, MulticastMAC,
        ContentFiltering, ChannelsMeasured,ChannelChangeFilter,
        NavMethodReporting, ControlDeviceReporting
    };
    enum DeliveryMode{
        ImmediatePush, DelayedPush,
        PullDelivery, DelayedPushAndPull
    };
    enum Compression{
        None, BiM, ZLIB, Infoset, EXI
    };
    enum VolumeDirection{
        up, down, mute, unmute
    };
    enum ControlDevice{
        STBRemoteControl = 0, STB = 1, STBKeyboard = 2,
        PC = 10, TABLET = 20, MOBILEPHONE = 30, OTHER = 40

    };
    private : std::vector<TransportProtocolMode> transportCapabilities;
    private : std::vector<OperationalManagement> operationCapab;
    private : std::vector<CryptographicProtocol> securityCapabilities;
    private : std::vector<PermissionMode> permissionOperationModes;
    private : std::vector<ConfigurationMode> configurationPackageDelivery;
    private : std::vector<DeliveryMode> reportDeliveryModes;
    private : MeasurementTriggerMethod *measurementTriggerMethod;
    private : std::vector<Compression> compression;
    public : void setOperationalCapab(std::vector<OperationalManagement> operationCapab);
    public : void setTransportProtool(std::vector<TransportProtocolMode> transportProtocols);
    public : void setSecurityCapabibilities(std::vector<CryptographicProtocol> securityCapab);
    public : void setPermissionModes(std::vector<PermissionMode> permissionMode);
    public : void setConfigMode(std::vector<ConfigurationMode> configMode);
    public : void setDeliveryMode(std::vector<DeliveryMode> deliveryMode);
    public : void setMeasurementTrigger(MeasurementTriggerMethod *measurementTrigger);
    public : void setCompression(std::vector<Compression> compression);

    public : std::vector<TransportProtocolMode>& getTransportProtocol();
    public : std::vector<CryptographicProtocol>& getSecurityCapabilities();
    public : std::vector<PermissionMode>& getPermissionMode();
    public : std::vector<ConfigurationMode>& getConfigurationMode();
    public : std::vector<DeliveryMode>& getDeliveryMode();
    public : MeasurementTriggerMethod* getMeasurementTrigger();
    public : std::vector<Compression>& getCompression();
    public : std::vector<OperationalManagement>& getOperationCapab();
    public : AMFCapabilityProfile();
    public :~AMFCapabilityProfile();
    public : void writeAMFCapab(ofstream &xml);

};


#endif // AMFCAPABILITYPROFILE_H_INCLUDED

#ifndef MEASUREMENTTRIGGERMETHOD_H_INCLUDED
#define MEASUREMENTTRIGGERMETHOD_H_INCLUDED
#include <vector>
using namespace std;

class MeasurementTriggerMethod{
    public : enum EventTrigger{
        VideoResize,VideoZoom, VideoObscure,
        AudioVolume, ConfigurationChange, UserChange,UserInfoChange,
        DisplayStatus,AudioLanguageChange,CaptionLanguageChange
    };
    public : enum TimeSampleTrigger{
        UserPresent,TDLocation, DeviceInfo,
        UserBioInfo, GenericUserInfo, EventCount,
        UserList,PermitBlockedInfo, channelplaying
    };
    public : enum ServiceStartTrigger{
        TDLocationSS, DeviceInfoSS,
        UserBioInfoSS, GenericUserInfoSS,
        UserListSS, PermitBlockedInfoSS
    };
    private : vector<EventTrigger> eventTrigger;
    private : vector<TimeSampleTrigger> timeSampleTrigger;
    private : vector<ServiceStartTrigger> serviceStartTrigger;

    public : void setEventTrigger(vector<EventTrigger> evtTrigger);
    public : void setTimeSampleTrigger(vector<TimeSampleTrigger> TTtrigger);
    public : void setServiceStartTrigger(vector <ServiceStartTrigger> serviceStartTrigger);

    public : vector<EventTrigger>& getEventTrigger();
    public : vector<TimeSampleTrigger>& getTimeSampleTrigger();
    public : vector<ServiceStartTrigger>& getServiceStartTrigger();


};

#endif // MEASUREMENTTRIGGERMETHOD_H_INCLUDED

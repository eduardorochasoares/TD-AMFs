#ifndef MEASUREMENTREPORT_H_INCLUDED
#define MEASUREMENTREPORT_H_INCLUDED
#include "eventDefs.h"
#include "ConfigurationChange.h"
#include "DeviceInformation.h"
#include "UserIdBioInfo.h"
#include "UserList.h"
#include "GenericUserInfo.h"
#include "UserInfoChange.h"
#include "PermitBlockedInfo.h"
#include "Events.h"
#include "eventDefs.h"
#include "ServiceRunning.h"
#include "ServiceStartEvent.h"

class MeasurementReport{


    private :
        int measurementRequestID;
        struct tm *measurementReportTriggerTime;
        bool displayStatus;
        AudioFocus *audioFocus;
        CaptionLanguageChange *captionChange;
        AudioLanguageChange *audioLangChange;
        AudioVolume *audioVolume;
        ConfigurationChange *configChange;
        VideoObscure *obscuration;
        VideoZoom *videoZoom;
        VideoResize *videoResize;
        vector<EventCount*> eventCount;
        DeviceInformation *deviceInformation;
        vector<UserIdBioInfo*> userBiographicInformation;
        TDLocalization *tdLocation;
        UserList *userList;
        vector<UserPresent*> userPresent;
        GenericUserInfo *genericUserInfo;
        UserInfoChange *userInfoChange;
        PermitBlockedInfo *permitBlockedInfo;
        vector<ChannelPlaying*> channelPlaying;
        ChannelStart *channelStart;
        ChannelStop *channelStop;
        VoDEvent *vodEvent;
        vector<VoDPlaying*> vodPlaying;
        ServiceRunning* serviceRunning;
        LinearChannelStart *linearChannelStart;
        NativeApplicationStart *nativeAppStart;
        InteractiveApplicationStart *iAppStart;

    public:
        void setMeasurementRequestID(int id);
        void setMeasurementReportTriggerTime(struct tm *t);
        void setDisplayStatus(bool status);
        void setAudioFocus(AudioFocus *a);
        void setCaptionChange(CaptionLanguageChange *c);
        void setAudioLanguageChange(AudioLanguageChange *a);
        void setAudioVolume(AudioVolume *a);
        void setConfigurationChange(ConfigurationChange *c);
        void setVideoObscure(VideoObscure *v);
        void setVideoZoom(VideoZoom *v);
        void setVideoResize(VideoResize *v);
        void setEventCount(vector<EventCount*> e);
        void setDeviceInformation(DeviceInformation *d);
        void setUserIdBioInfo(vector<UserIdBioInfo*> u);
        void setTDLocation(TDLocalization *t);
        void setUserList(UserList *u);
        void setUserPresent(vector<UserPresent*> u);
        void setUserInfoChange(UserInfoChange *u);
        void setPermitBlockedInfo(PermitBlockedInfo *p);
        void setChannelPlaying(vector<ChannelPlaying*>& channelPlaying);
        void setChannelStart(ChannelStart *channelStart);
        void setChannelStop(ChannelStop *channelStop);
        void setGenericUserInfo(GenericUserInfo *g);
        void setVodEvents(VoDEvent *vodEvent);
        void setVodPlaying(vector<VoDPlaying*>& vod);
        void setServiceRunning(ServiceRunning* serviceRunning);
        void setLinearChannelStart(LinearChannelStart* linearChannelStart);
        void setInteractiveAppStart(InteractiveApplicationStart* iAppStart);
        void setNativeAppStart(NativeApplicationStart* nativeAppStart);



        int getMeasurementRequestID();
        GenericUserInfo* getGenericUserInfo();
        struct tm *getMeasurementReportTriggerTime();
        bool getDisplayStatus();
        AudioFocus *getAudioFocus();
        CaptionLanguageChange *getCaptionChange();
        AudioLanguageChange *getAudioLanguageChange();
        AudioVolume *getAudioVolume();
        ConfigurationChange *getConfigurationChange();
        VideoObscure *getVideoObscure();
        VideoZoom *getVideoZoom();
        VideoResize *getVideoResize();
        VoDEvent *getVodEvents();
        vector<EventCount*>& getEventCount();
        DeviceInformation *getDeviceInformation();
        vector<UserIdBioInfo*>& getUserIdBioInfo();
        TDLocalization *getTDLocation();
        UserList *getUserList();
        vector<UserPresent*>& getUserPresent();
        UserInfoChange *getUserInfoChange();
        PermitBlockedInfo *getPermitBlockedInfo();
        vector<ChannelPlaying*>& getChannelPlaying();
        vector<VoDPlaying*>& getVodPlaying();
        ChannelStart *getChannelStart();
        ChannelStop *getChannelStop();

        ServiceRunning* getServiceRunning();
        InteractiveApplicationStart* getInteractiveApplicationStart();
        NativeApplicationStart* getNativeApplicationStart();
        LinearChannelStart* getLinearChannelStart();

        ~MeasurementReport();
        MeasurementReport();

};


#endif // MEASUREMENTREPORT_H_INCLUDED

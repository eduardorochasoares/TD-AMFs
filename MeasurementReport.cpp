#include "MeasurementReport.h"


void MeasurementReport::setMeasurementRequestID(int id)
{
    this->measurementRequestID = id;
}

void MeasurementReport::setMeasurementReportTriggerTime(struct tm* t)
{
    this->measurementReportTriggerTime = t;
}

void MeasurementReport::setAudioFocus(AudioFocus* a)
{
    this->audioFocus = a;
}

void MeasurementReport::setCaptionChange(CaptionLanguageChange* c)
{
    this->captionChange = c;
}

void MeasurementReport::setAudioLanguageChange(AudioLanguageChange* a)
{
    this->audioLangChange = a;
}

void MeasurementReport::setAudioVolume(AudioVolume* a)
{
    this->audioVolume = a;
}

void MeasurementReport::setConfigurationChange(ConfigurationChange* c)
{
    this->configChange = c;
}

void MeasurementReport::setVideoObscure(VideoObscure* v)
{
    this->obscuration = v;
}

void MeasurementReport::setVideoZoom(VideoZoom* v)
{
    this->videoZoom = v;
}

void MeasurementReport::setVideoResize(VideoResize* v)
{
    this->videoResize = v;
}

void MeasurementReport::setEventCount(vector<EventCount*> e)
{
    this->eventCount = e;
}

void MeasurementReport::setDeviceInformation(DeviceInformation* d)
{
    this->deviceInformation = d;
}

void MeasurementReport::setUserIdBioInfo(vector<UserIdBioInfo*> u)
{
    this->userBiographicInformation = u;
}

void MeasurementReport::setTDLocation(TDLocalization* t)
{
    this->tdLocation = t;
}

void MeasurementReport::setUserList(UserList* u)
{
    this->userList = u;
}

void MeasurementReport::setUserPresent(vector<UserPresent*> u)
{
    this->userPresent = u;
}

void MeasurementReport::setUserInfoChange(UserInfoChange* u)
{
    this->userInfoChange = u;
}

void MeasurementReport::setPermitBlockedInfo(PermitBlockedInfo* p)
{
    this->permitBlockedInfo = p;
}

int MeasurementReport::getMeasurementRequestID()
{
    return this->measurementRequestID;
}

struct tm* MeasurementReport::getMeasurementReportTriggerTime()
{
    return this->measurementReportTriggerTime;
}

bool MeasurementReport::getDisplayStatus()
{
    return this->displayStatus;
}

AudioFocus* MeasurementReport::getAudioFocus()
{
    return this->audioFocus;
}

CaptionLanguageChange* MeasurementReport::getCaptionChange()
{
    return this->captionChange;
}

AudioLanguageChange* MeasurementReport::getAudioLanguageChange()
{
    return this->audioLangChange;
}

AudioVolume* MeasurementReport::getAudioVolume()
{
    return this->audioVolume;
}

ConfigurationChange* MeasurementReport::getConfigurationChange()
{
    return this->configChange;
}

VideoObscure* MeasurementReport::getVideoObscure()
{
    return this->obscuration;
}

VideoZoom* MeasurementReport::getVideoZoom()
{
    return this->videoZoom;
}

VideoResize* MeasurementReport::getVideoResize()
{
    return this->videoResize;
}

vector<EventCount*>& MeasurementReport::getEventCount()
{
    return this->eventCount;
}

DeviceInformation* MeasurementReport::getDeviceInformation()
{
    return this->deviceInformation;
}

vector<UserIdBioInfo*>& MeasurementReport::getUserIdBioInfo()
{
    return this->userBiographicInformation;
}

TDLocalization* MeasurementReport::getTDLocation()
{
    return this->tdLocation;
}

UserList* MeasurementReport::getUserList()
{
    return this->userList;
}

vector<UserPresent*>& MeasurementReport::getUserPresent()
{
    return this->userPresent;
}

UserInfoChange* MeasurementReport::getUserInfoChange()
{
    return this->userInfoChange;
}

PermitBlockedInfo* MeasurementReport::getPermitBlockedInfo()
{
    return this->permitBlockedInfo;
}
void MeasurementReport::setDisplayStatus(bool status)
{
    this->displayStatus = status;
}

void MeasurementReport::setChannelPlaying(vector<ChannelPlaying*>& channelPlaying)
{
    this->channelPlaying = channelPlaying;
}

void MeasurementReport::setChannelStart(ChannelStart* channelStart)
{
    this->channelStart = channelStart;
}

void MeasurementReport::setChannelStop(ChannelStop* channelStop)
{
    this->channelStop = channelStop;
}

vector<ChannelPlaying*>& MeasurementReport::getChannelPlaying()
{
    return this->channelPlaying;
}

ChannelStart* MeasurementReport::getChannelStart()
{
    return this->channelStart;
}

ChannelStop* MeasurementReport::getChannelStop()
{
    return this->channelStop;
}


void MeasurementReport::setGenericUserInfo(GenericUserInfo* g)
{
    this->genericUserInfo = g;
}

GenericUserInfo* MeasurementReport::getGenericUserInfo()
{
    return this->genericUserInfo;
}
void MeasurementReport::setVodEvents(VoDEvent* vodEvent)
{
    this->vodEvent = vodEvent;
}

VoDEvent* MeasurementReport::getVodEvents()
{
    return this->vodEvent;
}


MeasurementReport::~MeasurementReport()
{
    /*
    if(this->permitBlockedInfo != NULL)
        delete this->permitBlockedInfo;
    if(this->audioFocus != NULL)
        delete this->audioFocus;
    if(this->audioLangChange != NULL)
        delete this->audioLangChange;
    if(this->audioVolume != NULL)
        delete this->audioVolume;
    if(this->captionChange != NULL)
        delete this->captionChange;
    if(this->configChange != NULL)
        delete this->configChange;
    if(this->deviceInformation != NULL)
        delete this->deviceInformation;

    if(this->obscuration != NULL)
        delete this->obscuration;
    if(this->tdLocation != NULL)
        delete this->tdLocation;
    if(this->userList != NULL)
        delete this->userList;
    if(this->userInfoChange != NULL)
        delete this->userInfoChange;
    if(this->videoResize != NULL)
        delete this->videoResize;
    if(this->videoZoom != NULL)
        delete this->videoZoom;
    if(this->channelStart != NULL)
        delete this->channelStart;
    if(this->channelStop != NULL)
        delete this->channelStop;
    if(this->genericUserInfo != NULL)
        delete this->genericUserInfo;
    */
     for(int i = 0; i < this->getEventCount().size(); i++){
        delete this->getEventCount().at(i);
     }

     for(int i = 0; i < this->getUserIdBioInfo().size(); i++){
        delete this->getUserIdBioInfo().at(i);
     }
     for(int i = 0; i < this->getUserPresent().size(); i++){
        delete this->getUserPresent().at(i);
     }
}

MeasurementReport::MeasurementReport()
{
    this->audioFocus = NULL;
    this->audioLangChange = NULL;
    this->audioVolume = NULL;
    this->captionChange = NULL;

    this->channelStart = NULL;
    this->channelStop = NULL;
    this->configChange = NULL;
    this->deviceInformation = NULL;
    this->displayStatus = false;
    this->genericUserInfo = NULL;
    this->measurementReportTriggerTime = NULL;
    this->measurementRequestID = 0;
    this->obscuration = NULL;
    this->permitBlockedInfo = NULL;
    this->tdLocation =  NULL;
    this->userInfoChange = NULL;
    this->userList = NULL;
    this->videoResize = NULL;
    this->videoZoom = NULL;
    this->vodEvent = NULL;

}

void MeasurementReport::setVodPlaying(vector<VoDPlaying*>& vod)
{
    this->vodPlaying = vod;
}

vector<VoDPlaying*>& MeasurementReport::getVodPlaying()
{
    return this->vodPlaying;
}


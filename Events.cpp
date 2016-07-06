#include "Events.h"
#include "AMFCapabilityProfile.h"
int Events::getServiceInstanceID()
{
    return this->serviceInstanceID;
}

void Events::setServiceInstanceID(int id)
{
    this->serviceInstanceID = id;
}

bool AudioFocus::getIptvFocus()
{
    return this->iptvFocus;
}

void AudioFocus::setIptvFocus(bool focus)
{
    this->iptvFocus = focus;
}

std::string CaptionLanguageChange::getCaptionLanguage()
{
    return this->captionLanguage;
}

void CaptionLanguageChange::setCaptionLanguage(std::string captionLang)
{
    this->captionLanguage = captionLang;
}

void AudioLanguageChange::setAudioLanguage(std::string audioLang)
{
    this->audioLanguage = audioLang;
}

std::string AudioLanguageChange::getAudioLang()
{
    return this->audioLanguage;
}

void AudioVolume::setVolumeDirection(AudioVolume::VolumeDirection volDirection)
{
    this->volumeDirection = volDirection;
}

AudioVolume::VolumeDirection AudioVolume::getVolumeDirection()
{
    return this->volumeDirection;
}

void VideoObscure::setObscuration(float obscuration)
{
    this->obscuration = obscuration;
}

float VideoObscure::getObscuration()
{
    return this->obscuration;
}

float VideoZoom::getZoomFactor()
{
    return this->zoomFactor;
}

void VideoZoom::setZoomFactor(float zoomFactor)
{
    this->zoomFactor = zoomFactor;
}

unsigned VideoResize::getImageWidth()
{
    return this->imageWidth;
}

unsigned VideoResize::getImageHeight()
{
    return this->imageHeight;
}

void VideoResize::setImageWidth(unsigned width)
{
    this->imageWidth = width;
}

void VideoResize::setImageHeight(unsigned height)
{
    this->imageHeight = height;
}

TimeStamp* EventCount::getStartTime()
{
    return this->startTime;
}

int EventCount::getEventsCounted()
{
    return this->eventsCounted;
}

void EventCount::setStartTime(TimeStamp* t)
{
    this->startTime = t;
}

void EventCount::setEventsCounted(int eventsCounted)
{
    this->eventsCounted = eventsCounted;
}
EventCount::~EventCount()
{
    delete this->startTime;
}

void ChannelStart::setControlDevice(AMFCapabilityProfile::ControlDevice ctrl)
{
    this->controlDevice = ctrl;
}

void ChannelStart::setStartNavMethod(StartNavMethod navMethod)
{
    this->startNavMethod = navMethod;
}

void ChannelStart::setPreviousServiceInstanceID(int id)
{
    this->previousServiceInstanceID = id;
}

void ChannelStart::setServiceIdentifer(std::string serviceID)
{
    this->serviceIdentifier = serviceID;
}

void ChannelStart::setViewMode(std::string v)
{
    this->viewMode = v;
}

void ChannelStart::setObscuration(float obscuration)
{
    this->obscuration = obscuration;
}

AMFCapabilityProfile::ControlDevice ChannelStart::getControlDevice()
{
    return this->controlDevice;
}

ChannelStart::StartNavMethod ChannelStart::getStartNavMethod()
{
    return this->startNavMethod;
}

int ChannelStart::getPreviousServiceInstanceID()
{
    return this->previousServiceInstanceID;
}

std::string ChannelStart::getServiceIdentifer()
{
    return this->serviceIdentifier;
}

std::string ChannelStart::getViewMode()
{
    return this->viewMode;
}



void ChannelStop::setControlDevice(AMFCapabilityProfile::ControlDevice ctrl)
{
    this->controlDevice = ctrl;
}

void ChannelStop::setStopNavMethod(StopNavMethod stopNavMethod)
{
    this->stopNavMethod = stopNavMethod;
}

AMFCapabilityProfile::ControlDevice ChannelStop::getControlDevice()
{
    return this->controlDevice;
}

ChannelStop::StopNavMethod ChannelStop::getStopNavMethod()
{
    return this->stopNavMethod;
}

void ChannelPlaying::setServiceIdentifier(std::string id)
{
    this->serviceIdentifier = id;
}

std::string ChannelPlaying::getServiceIdentifier()
{
    return this->serviceIdentifier;
}

AudioFocus::AudioFocus()
{
    this->iptvFocus = false;
    this->setServiceInstanceID(0);
}


CaptionLanguageChange::CaptionLanguageChange()
{
    this->setServiceInstanceID(0);

}



AudioLanguageChange::AudioLanguageChange()
{
    this->setServiceInstanceID(0);
}



AudioVolume::AudioVolume()
{
    this->setServiceInstanceID(0);

}

VideoObscure::VideoObscure()
{
    this->setServiceInstanceID(0);
    this->obscuration = 0;
}

VideoZoom::VideoZoom()
{
    this->setServiceInstanceID(0);
    this->zoomFactor = 0;
}

VideoResize::VideoResize()
{
    this->imageHeight = 0;
    this->imageWidth = 0;
    this->setServiceInstanceID(0);
}

EventCount::EventCount()
{
    this->eventsCounted = 0;
    this->setServiceInstanceID(0);
    this->startTime = NULL;

}




ChannelStart::ChannelStart()
{
    this->previousServiceInstanceID = 0;
    this->obscuration = 0;
    this->setServiceInstanceID(0);
    this->controlDevice = AMFCapabilityProfile::OTHER;
    this->startNavMethod = ChannelStart::unknown;
    this->viewMode = ChannelStart::Unknown;

}

ChannelStop::ChannelStop()
{
    this->controlDevice = AMFCapabilityProfile::OTHER;
    this->setServiceInstanceID(0);
    this->stopNavMethod = ChannelStop::unknown;
}

ChannelPlaying::ChannelPlaying()
{
    this->setServiceInstanceID(0);
}

AudioVolume::~AudioVolume()
{

}



float ChannelStart::getObscuration()
{
    return this->obscuration;
}

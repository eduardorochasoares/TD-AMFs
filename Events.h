#ifndef EVENTS_H_INCLUDED
#define EVENTS_H_INCLUDED
#include <string>
#include "eventDefs.h"
#include "AMFCapabilityProfile.h"


class Events{
    private:
        int serviceInstanceID;
    public :
        int getServiceInstanceID();
        void setServiceInstanceID(int id);
};

class AudioFocus : public Events{

    private :
        bool iptvFocus;
    public :
        bool getIptvFocus();
        void setIptvFocus(bool focus);
        AudioFocus();
};

class CaptionLanguageChange : public Events{
    private:
        std::string captionLanguage;
    public:
        std::string getCaptionLanguage();
        void setCaptionLanguage(std::string captionLang);
        CaptionLanguageChange();
};

class AudioLanguageChange : public Events{
    private:
        std::string audioLanguage;
    public :
        void setAudioLanguage(std::string audioLang);
        std::string getAudioLang();
        AudioLanguageChange();
};

class AudioVolume : public Events{
    public:
        enum  VolumeDirection{
            up, down, mute,unmute
        };
    private:
        VolumeDirection volumeDirection;
    public :
        void setVolumeDirection(VolumeDirection volDirection);
        VolumeDirection getVolumeDirection();
        AudioVolume();
        ~AudioVolume();
};

class VideoObscure : public Events{
    private :
        float obscuration;

    public:
        void setObscuration(float obscuration);
        float getObscuration();
        VideoObscure();

};
class VideoZoom : public Events{
    private :
        float zoomFactor;

    public:
        float getZoomFactor();
        void setZoomFactor(float zoomFactor);
        VideoZoom();

};
class VideoResize : public Events{
    private:
        unsigned imageWidth;
        unsigned imageHeight;
    public:
        unsigned getImageWidth();
        unsigned getImageHeight();
        void setImageWidth(unsigned width);
        void setImageHeight(unsigned height);
        VideoResize();

};
class EventCount : public Events{
    private :
        TimeStamp *startTime;
        int eventsCounted;

    public:
        TimeStamp *getStartTime();
        int getEventsCounted();

        void setStartTime(TimeStamp *t);
        void setEventsCounted(int eventsCounted);
        EventCount();
        ~EventCount();


};

class ChannelStart : public Events{
    public:
        enum StartNavMethod{
            UpdownArrow = 0, channelSurfing = 1,
            scheduledChannelChange = 2, EPG = 3, Last_previous = 4,
            Favourite = 5, numberEntry = 6, unknown = 7, other = 8
        };
        enum ViewMode{
            Unknown = 0,
            full_screen,
            Picture_in_Picture,
            Mosaic,
            Other
        };

    private:

        AMFCapabilityProfile::ControlDevice controlDevice;
        StartNavMethod startNavMethod;
        int previousServiceInstanceID;
        std::string serviceIdentifier;
        std::string viewMode;
        float obscuration;

    public:
        void setControlDevice(AMFCapabilityProfile::ControlDevice ctrl);
        void setStartNavMethod(StartNavMethod navMethod);
        void setPreviousServiceInstanceID(int id);
        void setServiceIdentifer(std::string serviceID);
        void setViewMode(std::string viewMode);
        void setObscuration(float obscuration);
        ChannelStart();

        AMFCapabilityProfile::ControlDevice getControlDevice();
        StartNavMethod getStartNavMethod();
        int getPreviousServiceInstanceID();
        std::string getServiceIdentifer();
        std::string getViewMode();
        float getObscuration();

};

class ChannelStop : public Events{
    public:
        enum StopNavMethod{
            UpDownArrow = 0, channel_surfing, scheduled_channel_change,
            EPG, Last_previous, Favourite, number_entry, unknown ,other ,
            turn_off_terminal_device = 999
        };
    private:

        AMFCapabilityProfile::ControlDevice controlDevice;
        StopNavMethod stopNavMethod;

    public:
        ChannelStop();
        void setControlDevice(AMFCapabilityProfile::ControlDevice ctrl);
        void setStopNavMethod(StopNavMethod stopNavMethod);
        AMFCapabilityProfile::ControlDevice getControlDevice();
        StopNavMethod getStopNavMethod();

};

class ChannelPlaying : public Events{
    private:
        std::string serviceIdentifier;

    public :
        void setServiceIdentifier(std::string id);
        std::string getServiceIdentifier();
        ChannelPlaying();

};

class VoDEvent : public Events{
    private:
        std::string event;
        std::string serviceIdentifier;

    public:
        void setServiceIdentifier(std::string id);
        std::string getServiceIdentifier();

        void setEventName(std::string event);
        std::string getEventName();
        VoDEvent();
};

#endif // EVENTS_H_INCLUDED

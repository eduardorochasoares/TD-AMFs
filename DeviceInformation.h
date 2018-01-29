#ifndef DEVICEINFORMATION_H_INCLUDED
#define DEVICEINFORMATION_H_INCLUDED
#include "StbInformation.h"
#include "TVInformation.h"
#include "PCInformation.h"
#include "IptvTVInformation.h"
#include "AudioAmplifierInformation.h"
#include "MobileDeviceInformation.h"
#include <fstream>
using namespace std;
class DeviceInformation{
    private :
        STBinformation *stbInfo;
        TVInformation *tvInfo;
        AudioAmplifierInformation *AudioAmpliInfo;
        IptvTvInformation *iptvInfo;
        MobileDeviceInformation *mobileInfo;
        PCInformation *pcInfo;
    public :
        void setStbInfo(STBinformation *stbInfo);
        void setTvInfo(TVInformation *tvInfo);
        void setAudioAmpliInfo(AudioAmplifierInformation *audioAmpliInfo);
        void setIptvInfo(IptvTvInformation *iptvInfo);
        void setMobileDevInfo(MobileDeviceInformation *mobileDevInfo);
        void setPcInfo(PCInformation *pcInfo);
        ~DeviceInformation();
        DeviceInformation();
        STBinformation *getStbInfo();
        TVInformation *getTvInfo();
        AudioAmplifierInformation *getAudioAmpliInfo();
        IptvTvInformation *getIptvInfo();
        MobileDeviceInformation *getMobileDevInfo();
        PCInformation *getPcInfo();

        void writeXML(ofstream &xml);
};


#endif // DEVICEINFORMATION_H_INCLUDED

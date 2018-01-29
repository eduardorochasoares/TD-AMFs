#include "DeviceInformation.h"

void DeviceInformation::setStbInfo(STBinformation* stbInfo)
{
    this->stbInfo = stbInfo;
}

void DeviceInformation::setTvInfo(TVInformation* tvInfo)
{
    this->tvInfo = tvInfo;
}

void DeviceInformation::setAudioAmpliInfo(AudioAmplifierInformation* audioAmpliInfo)
{
    this->AudioAmpliInfo = audioAmpliInfo;
}

void DeviceInformation::setIptvInfo(IptvTvInformation* iptvInfo)
{
    this->iptvInfo = iptvInfo;
}

void DeviceInformation::setMobileDevInfo(MobileDeviceInformation* mobileDevInfo)
{
    this->mobileInfo = mobileDevInfo;
}

void DeviceInformation::setPcInfo(PCInformation* pcInfo)
{
    this->pcInfo = pcInfo;
}

DeviceInformation::~DeviceInformation()
{
    delete this->AudioAmpliInfo;
    delete this->iptvInfo;
    delete this->mobileInfo;
    delete this->pcInfo;
    delete this->stbInfo;
    delete this->tvInfo;
}

STBinformation* DeviceInformation::getStbInfo()
{
    return this->stbInfo;
}

TVInformation* DeviceInformation::getTvInfo()
{
    return this->tvInfo;
}

AudioAmplifierInformation* DeviceInformation::getAudioAmpliInfo()
{
    return this->AudioAmpliInfo;
}

IptvTvInformation* DeviceInformation::getIptvInfo()
{
    return this->iptvInfo;
}

MobileDeviceInformation* DeviceInformation::getMobileDevInfo()
{
    return this->mobileInfo;
}

PCInformation* DeviceInformation::getPcInfo()
{
    return this->pcInfo;
}


void DeviceInformation::writeXML(ofstream &xml)
{   xml<<"<DeviceInformation>"<<endl;
    if(this->getTvInfo() != NULL)
        this->getTvInfo()->writeTVInfo(xml);
    if(this->getAudioAmpliInfo() != NULL)
        this->getAudioAmpliInfo()->writeAudioAmplifier(xml);
    if(this->getIptvInfo() != NULL)
        this->getIptvInfo()->writeXML(xml);
    if(this->getStbInfo()!= NULL)
        this->getStbInfo()->writeXML(xml);
    if(this->getMobileDevInfo() != NULL)
        this->getMobileDevInfo()->writeXML(xml);
    if(this->getPcInfo() != NULL)
        this->getPcInfo()->writeXML(xml);

    xml<<"</DeviceInformation>"<<endl;
}
DeviceInformation::DeviceInformation()
{
    this->AudioAmpliInfo = NULL;
    this->iptvInfo = NULL;
    this->mobileInfo = NULL;
    this->pcInfo = NULL;
    this->stbInfo = NULL;
    this->tvInfo = NULL;
}



#include "ConfigurationChange.h"
void ConfigurationChange::setAMFCapab(AMFCapabilityProfile* amf)
{
    this->amfCapabilityProfile = amf;
}

void ConfigurationChange::setTVInfo(TVInformation* tvInfo)
{
    this->tvInfo = tvInfo;
}

void ConfigurationChange::setAudioAmplifier(AudioAmplifierInformation* audioAmpliInfo)
{
    this->audioAmpli = audioAmpliInfo;
}

AMFCapabilityProfile* ConfigurationChange::getAMFCapab()
{
    return this->amfCapabilityProfile;
}

TVInformation* ConfigurationChange::getTVInfo()
{
    return this->tvInfo;
}

AudioAmplifierInformation* ConfigurationChange::getAudioAmplifier()
{
    return this->audioAmpli;
}

ConfigurationChange::~ConfigurationChange()
{
    delete this->amfCapabilityProfile;
    delete this->audioAmpli;
    delete this->tvInfo;
}
ConfigurationChange::ConfigurationChange()
{
    this->amfCapabilityProfile = NULL;
    this->audioAmpli = NULL;
    this->tvInfo = NULL;
}


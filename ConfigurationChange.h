#ifndef CONFIGURATIONCHANGE_H_INCLUDED
#define CONFIGURATIONCHANGE_H_INCLUDED
#include "AMFCapabilityProfile.h"
#include "TVInformation.h"
class ConfigurationChange{
    private:
        AMFCapabilityProfile *amfCapabilityProfile;
        TVInformation *tvInfo;
        AudioAmplifierInformation *audioAmpli;

    public:

        void setAMFCapab(AMFCapabilityProfile *amf);
        void setTVInfo(TVInformation *tvInfo);
        void setAudioAmplifier(AudioAmplifierInformation *audioAmpliInfo);

        AMFCapabilityProfile *getAMFCapab();
        TVInformation *getTVInfo();
        AudioAmplifierInformation *getAudioAmplifier();

        ~ConfigurationChange();
        ConfigurationChange();


};

#endif // CONFIGURATIONCHANGE_H_INCLUDED

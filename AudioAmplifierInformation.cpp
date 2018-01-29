#include "AudioAmplifierInformation.h"

void AudioAmplifierInformation::setManuf(short manuf)
{
    this->audioAmplifierManuf = manuf;
}

void AudioAmplifierInformation::setModel(short model)
{
    this->audioAmplifierModel = model;
}

void AudioAmplifierInformation::setSerialNum(int serialNum)
{
    this->audioAmplifierSerialNum = serialNum;
}

short AudioAmplifierInformation::getManuf()
{
    return this->audioAmplifierManuf;
}

short AudioAmplifierInformation::getModel()
{
     return this->audioAmplifierModel;
}

int AudioAmplifierInformation::getSerialNum()
{
    return this->audioAmplifierSerialNum;
}

void AudioAmplifierInformation::writeAudioAmplifier(ofstream &xml)
{
    xml<<"<AudioAmplifierInformation>"<<endl;
    xml<<"<AudioAmplifierManuf>"<<this->getManuf()<<"</AudioAmplifierManuf>"<<endl;
    xml<<"<AudioAmplifierModel>"<<this->getModel()<<"</AudioAmplifierModel>"<<endl;
    xml<<"<AudioAmplifierSerialNum>"<<this->getSerialNum()<<"</AudioAmplifierSerialNum>"<<endl;
    xml<<"</AudioAmplifierInformation>"<<endl;
}

AudioAmplifierInformation::AudioAmplifierInformation()
{
    this->audioAmplifierManuf = 0;
    this->audioAmplifierModel = 0;
    this->audioAmplifierSerialNum = 0;
}

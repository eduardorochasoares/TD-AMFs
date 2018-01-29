#ifndef AUDIOAMPLIFIERINFORMATION_H_INCLUDED
#define AUDIOAMPLIFIERINFORMATION_H_INCLUDED
#include <fstream>
using namespace std;
class AudioAmplifierInformation{
    private :
        short audioAmplifierManuf;
        short audioAmplifierModel;
        int audioAmplifierSerialNum;

    public :
        void setManuf(short manuf);
        void setModel(short model);
        void setSerialNum(int serialNum);

        short getManuf();
        short getModel();
        int getSerialNum();
        void writeAudioAmplifier(ofstream &xml);
        AudioAmplifierInformation();

};


#endif // AUDIOAMPLIFIERINFORMATION_H_INCLUDED

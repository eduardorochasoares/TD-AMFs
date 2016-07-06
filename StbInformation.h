#ifndef STBINFORMATION_H_INCLUDED
#define STBINFORMATION_H_INCLUDED
#include <string>
#include <fstream>
using namespace std;
class STBinformation{
    private : char stbManuf[6];
    private : string stbModel;
    private : string stbSerialNum;

    public : void setStbManuf(char stbManuf[]);
    public : void setStbModel(string stbModel);
    public : void setStbSerialNum(string stbSerialNum);

    public : char* getStbManuf();
    public : string getStbModel();
    public : string getStbSerial();

    public : void writeXML(ofstream &xml);
};

#endif // STBINFORMATION_H_INCLUDED

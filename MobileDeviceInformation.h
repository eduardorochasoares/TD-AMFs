#ifndef MOBILEDEVICEINFORMATION_H_INCLUDED
#define MOBILEDEVICEINFORMATION_H_INCLUDED
#include <string>
#include <fstream>
using namespace std;
class MobileDeviceInformation{
    private : char mobileDeviceManuf[6];
    private : string mobileDeviceModel;
    private : string mobileSerialNum;

    public : void setMobileDevManuf(char* mobileDev);
    public : void setMobileDevModel(string mobileDeviceModel);
    public : void setMobileSerialNum(string mobileSerialNum);

    public : char* getMobileDeviceManuf();
    public : string getMobileDeviceModel();
    public : string getMobileSerialNum();

    public : void writeXML(ofstream &xml);
    MobileDeviceInformation();

};


#endif // MOBILEDEVICEINFORMATION_H_INCLUDED

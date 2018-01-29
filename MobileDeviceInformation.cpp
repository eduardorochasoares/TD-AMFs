#include "MobileDeviceInformation.h"
#include "string.h"

void MobileDeviceInformation::setMobileDevManuf(char* mobileDev)
{
    char* p = strcpy(this->mobileDeviceManuf, mobileDev);
}

void MobileDeviceInformation::setMobileDevModel(string mobileDeviceModel)
{
    this->mobileDeviceModel = mobileDeviceModel;
}

void MobileDeviceInformation::setMobileSerialNum(string mobileSerialNum)
{
    this->mobileSerialNum = mobileSerialNum;
}

char* MobileDeviceInformation::getMobileDeviceManuf()
{
    return this->mobileDeviceManuf;
}

string MobileDeviceInformation::getMobileDeviceModel()
{
    return this->mobileDeviceModel;
}

string MobileDeviceInformation::getMobileSerialNum()
{
    return this->mobileSerialNum;
}

void MobileDeviceInformation::writeXML(ofstream& xml)
{
    xml<<"<MobilieDeviceInformation>"<<endl;
    xml<<"<MobileDeviceManuf>"<<this->getMobileDeviceManuf()<<"</MobileDeviceManuf>"<<endl;
    xml<<"<MobileDeviceModel>"<<this->getMobileDeviceModel()<<"</MobileDeviceModel>"<<endl;
    xml<<"<MobileDeviceSerialNum>"<<this->getMobileSerialNum()<<"</MobileDeviceSerialNum>"<<endl;
    xml<<"</MobileDeviceInformation>"<<endl;
}

MobileDeviceInformation::MobileDeviceInformation()
{

}



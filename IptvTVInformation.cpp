#include "IptvTVInformation.h"
#include "string.h"

void IptvTvInformation::setIpvtManuf(char* manuf)
{
    char* p = strcpy(this->iptvTVManuf, manuf);
}

void IptvTvInformation::setIptvModel(string model)
{
    this->iptvTVModel = model;
}

void IptvTvInformation::setIptvSerialNum(string serialNum)
{
    this->iptvSerialNum = serialNum;
}

char* IptvTvInformation::getIptvManuf()
{
    return this->iptvTVManuf;
}

string IptvTvInformation::getModel()
{
    return this->iptvTVModel;
}

string IptvTvInformation::getSerialNum()
{

}

void IptvTvInformation::writeXML(ofstream &xml)
{
    xml<<"<IPTVTVInformation>"<<endl;
    xml<<"<IPTVTVManuf>"<<this->getIptvManuf()<<"</IPTVTVManuf>"<<endl;
    xml<<"<IPTVTVModel>"<<this->getModel()<<"</IPTVTVModel>"<<endl;
    xml<<"<IPTVTVSerialNum>"<<this->getSerialNum()<<"</IPTVTVSerialNum>"<<endl;
    xml<<"</IPTVTVInformation>"<<endl;
}





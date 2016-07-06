#include "StbInformation.h"
#include "string.h"
void STBinformation::setStbManuf(char* stbManuf)
{
   char* p =  strcpy(this->stbManuf, stbManuf);

}

void STBinformation::setStbModel(string stbModel)
{
    this->stbModel = stbModel;
}

void STBinformation::setStbSerialNum(string stbSerialNum)
{
    this->stbSerialNum = stbSerialNum;
}

char* STBinformation::getStbManuf()
{
    return this->stbManuf;
}

string STBinformation::getStbModel()
{
    return this->stbModel;
}

string STBinformation::getStbSerial()
{
    return this->stbSerialNum;
}



void STBinformation::writeXML(ofstream &xml)
{
    xml<<"<STBInformation>"<<endl;
    xml<<"<STBManuf>"<<this->getStbManuf()<<"</STBManuf>"<<endl;
    xml<<"<STBModel>"<<this->getStbModel()<<"</STBModel>"<<endl;
    xml<<"<STBSerialNum>"<<this->getStbSerial()<<"</STBSerialNum>"<<endl;
    xml<<"</STBInformation>"<<endl;


}

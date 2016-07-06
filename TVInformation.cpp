#include "TVInformation.h"
void TVInformation::setTvManuf(short tvManuf)
{
    this->tvManuf = tvManuf;
}

void TVInformation::setTvModel(short tvModel)
{
    this->tvModel = tvModel;
}

void TVInformation::setTvSerialNum(int tvSerialNum)
{
    this->tvSerialNum = tvSerialNum;
}

short TVInformation::getTvManuf(){
    return this->tvManuf;
}
short TVInformation::getTvModel(){
    return this->tvModel;
}
int TVInformation::getTvSerialNum(){
    return this->tvSerialNum;
}

void TVInformation::writeTVInfo(ofstream &xml)
{
    xml<<"<TVInfomation>"<<endl;
    xml<<"<TVManuf>"<<this->getTvManuf()<<"</TVManuf>"<<endl;
    xml<<"<TVModel>"<<this->getTvModel()<<"</TVModel>"<<endl;
    xml<<"<TVSerialNum>"<<this->getTvSerialNum()<<"</TVSerialNum>"<<endl;
    xml<<"</TVInformation>"<<endl;

}

TVInformation::TVInformation()
{
    this->tvManuf = 0;
    this->tvModel = 0;
    this->tvSerialNum = 0;
}

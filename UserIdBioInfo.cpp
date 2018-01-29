#include "UserIdBioInfo.h"
void UserIdBioInfo::setUserID(std::string id)
{
    this->userID = id;
}

void UserIdBioInfo::setControlledUserInfoStrings(std::vector<ControlledUserInfoString*> s)
{
    this->controlledUserInfoStrings = s;
}

void UserIdBioInfo::setControlledUserInfoStrings(std::vector<ControlledUserInfoDate*> d)
{
    this->controlledUserInfoDates = d;
}

void UserIdBioInfo::setControlledUserInfoStrings(std::vector<ControlledUserInfoAddress*> a)
{
    this->controlledUserInfoAddresses = a;
}

std::vector<ControlledUserInfoString*>& UserIdBioInfo::getControlledUserInfoStrings()
{
    return this->controlledUserInfoStrings;
}

std::vector<ControlledUserInfoDate*>& UserIdBioInfo::getControlledUserInfoDate()
{
    return this->controlledUserInfoDates;
}

std::vector<ControlledUserInfoAddress*>& UserIdBioInfo::getControlledUserInfoAddresses()
{
    return this->controlledUserInfoAddresses;
}
std::string UserIdBioInfo::getUserID()
{
    return this->userID;
}



UserIdBioInfo::~UserIdBioInfo()
{
    for(int i = 0; i < this->controlledUserInfoAddresses.size(); i++)
        delete this->controlledUserInfoAddresses.at(i);

    for(int i = 0; i < this->controlledUserInfoDates.size(); i++)
        delete this->controlledUserInfoDates.at(i);

     for(int i = 0; i < this->controlledUserInfoStrings.size(); i++)
        delete this->controlledUserInfoStrings.at(i);

}


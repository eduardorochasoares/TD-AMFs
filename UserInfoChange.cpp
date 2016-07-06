#include "UserInfoChange.h"
void UserInfoChange::setAnnonUserID(unsigned annonUserId)
{
    this->annonUserID = annonUserId;
}

void UserInfoChange::setGenericUserInfos(std::vector<GenericUserInfos*> g)
{
    this->genericUserInfos = g;
}

std::vector<GenericUserInfos*>& UserInfoChange::getGenericUserInfo()
{
    return this->genericUserInfos;
}

unsigned UserInfoChange::getAnnonUserID()
{
    return this->annonUserID;
}
UserInfoChange::~UserInfoChange()
{
    for(int i = 0; i < this->genericUserInfos.size(); i++)
        delete this->genericUserInfos.at(i);
}
UserInfoChange::UserInfoChange()
{
    this->annonUserID = 0;

}

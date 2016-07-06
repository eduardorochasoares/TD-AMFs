#include "GenericUserInfo.h"

void GenericUserInfo::setUserIDGenericInfo(std::vector<UserIDGenericInfo*> u)
{
    this->userIDGenericInfo = u;
}

std::vector<UserIDGenericInfo*>& GenericUserInfo::getUserIdGenericInfo()
{
    return this->userIDGenericInfo;
}



GenericUserInfo::GenericUserInfo(std::vector<UserIDGenericInfo*> u)
{
    this->userIDGenericInfo = u;
}

GenericUserInfo::~GenericUserInfo()
{
    for(int i = 0; i < this->userIDGenericInfo.size(); i++)
        delete this->userIDGenericInfo.at(i);
}




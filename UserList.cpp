#include "UserList.h"
void UserList::setUserIdInfos(std::vector<UserIdInfo*> userIdInfo)
{
    this->userIdInfo = userIdInfo;
}

std::vector<UserIdInfo*>& UserList::getUserIdInfo()
{
    return this->userIdInfo;
}
UserList::~UserList()
{
    for(int i = 0; i < this->getUserIdInfo().size(); i++)
        delete this->getUserIdInfo().at(i);
}





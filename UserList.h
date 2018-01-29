#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED
#include "eventDefs.h"

class UserList{
    private:
            std::vector<UserIdInfo*> userIdInfo;
    public:
        void setUserIdInfos(std::vector<UserIdInfo*> userIdInfo);
        std::vector<UserIdInfo*>& getUserIdInfo();
        ~UserList();
};

#endif // USERLIST_H_INCLUDED

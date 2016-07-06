#ifndef USERINFOCHANGE_H_INCLUDED
#define USERINFOCHANGE_H_INCLUDED
#include "eventDefs.h"
#include "UserIdBioInfo.h"

class UserInfoChange : public UserIdBioInfo {
    private :
        unsigned annonUserID;
        std::vector<GenericUserInfos*> genericUserInfos;
    public:
        void setAnnonUserID(unsigned annonUserId);
        void setGenericUserInfos(std::vector<GenericUserInfos*> g);

        std::vector<GenericUserInfos*>& getGenericUserInfo();
        unsigned getAnnonUserID();
        ~UserInfoChange();
        UserInfoChange();
};

#endif // USERINFOCHANGE_H_INCLUDED

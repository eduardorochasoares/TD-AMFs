#ifndef GENERICUSERINFO_H_INCLUDED
#define GENERICUSERINFO_H_INCLUDED
#include "eventDefs.h"
class GenericUserInfo{
    private:
        std::vector<UserIDGenericInfo*> userIDGenericInfo;
    public:
        void setUserIDGenericInfo(std::vector<UserIDGenericInfo*> u);
        std::vector<UserIDGenericInfo*>& getUserIdGenericInfo();
        GenericUserInfo(std::vector<UserIDGenericInfo*> u);
        ~GenericUserInfo();
        GenericUserInfo();

};

#endif // GENERICUSERINFO_H_INCLUDED

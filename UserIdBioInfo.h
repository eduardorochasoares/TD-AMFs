#ifndef USERIDBIOINFO_H_INCLUDED
#define USERIDBIOINFO_H_INCLUDED
#include "eventDefs.h"
class UserIdBioInfo{
    private :
        std::string userID;
        std::vector<ControlledUserInfoString*> controlledUserInfoStrings;
        std::vector<ControlledUserInfoDate*> controlledUserInfoDates;
        std::vector<ControlledUserInfoAddress*> controlledUserInfoAddresses;
    public:
        void setUserID(std::string id);
        void setControlledUserInfoStrings(std::vector<ControlledUserInfoString*> s);
        void setControlledUserInfoStrings(std::vector<ControlledUserInfoDate*> d);
        void setControlledUserInfoStrings(std::vector<ControlledUserInfoAddress*> a);
        std::string getUserID();
        std::vector<ControlledUserInfoString*>& getControlledUserInfoStrings();
        std::vector<ControlledUserInfoDate*>& getControlledUserInfoDate();
        std::vector<ControlledUserInfoAddress*>& getControlledUserInfoAddresses();
        ~UserIdBioInfo();




};


#endif // USERIDBIOINFO_H_INCLUDED

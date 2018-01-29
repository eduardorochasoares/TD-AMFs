#ifndef EVENTDEFS_H_INCLUDED
#define EVENTDEFS_H_INCLUDED
#include <string>
#include <vector>

typedef struct timestamp{
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int seconds;
    int mseconds;
}TimeStamp;





typedef struct controlledUserInfoString{
    std::string controlledUserInfoTypeString;
    std::string controlledUserInfoValueString;
}ControlledUserInfoString;

typedef struct controlledUserInfoDate{
    std::string controlledUserInfoTypeDate;
    std::string controlledUserInfoTypeValue;
}ControlledUserInfoDate;

typedef struct controlledUserInfoAddress{
    std::string controlledUserInfoAddressType;
    std::string controlledUserInfoAddressValue;
}ControlledUserInfoAddress;

typedef struct tdLocation{
    float longitude;
    float latitude;
}TDLocalization;

typedef struct userIdInfo{
    unsigned annonUserID;
    std::string userID;
    std::string userIDMethod;
    float userIDConfidence;

}UserIdInfo;

typedef struct userPresent{
    std::string presenceMethod = "remotekeypush";
    TimeStamp *presenceTime;
    float presenceConfidence;
}UserPresent;

typedef struct genericUserInfos{
    std::string genericUserInfoType;
    std::string genericUserInfoValue;
}GenericUserInfos;

typedef struct userIDGenericInfo{
    unsigned annonUserID;
    std::string userID;
    std::vector<GenericUserInfos*> genericUserInfos;
}UserIDGenericInfo;

typedef struct contentClass{
    std::string contentClassDomain;
    std::vector<std::string>& contentClassID;
}ContentClass;

#endif // EVENTDEFS_H_INCLUDED


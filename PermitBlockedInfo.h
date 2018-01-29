#ifndef PERMITBLOCKEDINFO_H_INCLUDED
#define PERMITBLOCKEDINFO_H_INCLUDED
#include "ConfigPckgRequest.h"
#include "AllContentClassExceptList.h"

class PermitBlockedInfo{
    public:
        enum PermissionLevelFlag{
            Level0 = 0, Level1 = 1, Level2 = 2
        };

    private:
        PermissionLevelFlag permissionLevelFlag;
        ConfigPkgRequest::TerminalDeviceType terminalDeviceTypeFlag;
        bool channelFlag;
        AllContentClassExceptList *contentClassFlag;

    public:
        ~PermitBlockedInfo();
        void setPermissionLevelFlag(PermissionLevelFlag p);
        void setTerminalDeviceTypeFlag(ConfigPkgRequest::TerminalDeviceType t);
        void setChannelFlag(bool flag);
        void setContentClassFlag(AllContentClassExceptList *a);

        AllContentClassExceptList *getContentClassFlag();
        bool getChannelFlag();
        ConfigPkgRequest::TerminalDeviceType getTerminalDeviceTypeFlag();
        PermissionLevelFlag getPermissionLevelFlag();
        PermitBlockedInfo();
};

#endif // PERMITBLOCKEDINFO_H_INCLUDED

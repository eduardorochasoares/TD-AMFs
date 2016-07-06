#include "PermitBlockedInfo.h"

PermitBlockedInfo::~PermitBlockedInfo()
{
    delete this->contentClassFlag;
}

void PermitBlockedInfo::setPermissionLevelFlag(PermissionLevelFlag p)
{
    this->permissionLevelFlag = p;
}

void PermitBlockedInfo::setTerminalDeviceTypeFlag(ConfigPkgRequest::TerminalDeviceType t)
{
    this->terminalDeviceTypeFlag = t;
}

void PermitBlockedInfo::setChannelFlag(bool flag)
{
    this->channelFlag = flag;
}

void PermitBlockedInfo::setContentClassFlag(AllContentClassExceptList* a)
{
    this->contentClassFlag = a;
}

AllContentClassExceptList* PermitBlockedInfo::getContentClassFlag()
{
    return this->contentClassFlag;
}

bool PermitBlockedInfo::getChannelFlag()
{
    return this->channelFlag;
}

ConfigPkgRequest::TerminalDeviceType PermitBlockedInfo::getTerminalDeviceTypeFlag()
{
    return this->terminalDeviceTypeFlag;
}

PermitBlockedInfo::PermissionLevelFlag PermitBlockedInfo::getPermissionLevelFlag()
{
    return this->permissionLevelFlag;
}

PermitBlockedInfo::PermitBlockedInfo()
{
    this->channelFlag = false;
    this->contentClassFlag = NULL;
    this->permissionLevelFlag = PermitBlockedInfo::Level0;
    this->terminalDeviceTypeFlag = ConfigPkgRequest::Other;

}

#include "ServiceStartEvent.h"
ServiceStartEvent::ServiceStartEvent()
{

}

bool ServiceStartEvent::getStatus()
{
    return this->status;
}

void ServiceStartEvent::setStatus(bool on)
{
    this->status = on;
}

ServiceStartEvent::~ServiceStartEvent()
{

}

LinearChannelStart::LinearChannelStart()
{

}

LinearChannelStart::~LinearChannelStart()
{

}

InteractiveApplicationStart::InteractiveApplicationStart()
{

}

InteractiveApplicationStart::~InteractiveApplicationStart()
{

}

NativeApplicationStart::NativeApplicationStart()
{

}

NativeApplicationStart::~NativeApplicationStart()
{

}

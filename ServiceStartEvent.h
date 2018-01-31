#ifndef SERVICESTARTEVENT_H_INCLUDED
#define SERVICESTARTEVENT_H_INCLUDED

class ServiceStartEvent{

    private:
        bool status;

    public:
        ServiceStartEvent();
        bool getStatus();
        void setStatus(bool on);
        ~ServiceStartEvent();

};
class LinearChannelStart : public ServiceStartEvent{
    public:
        LinearChannelStart();
        ~LinearChannelStart();
};

class InteractiveApplicationStart : public ServiceStartEvent{
    public:
         InteractiveApplicationStart();
        ~InteractiveApplicationStart();
};

class NativeApplicationStart : public ServiceStartEvent{
    public:
        NativeApplicationStart();
        ~NativeApplicationStart();
};



#endif // SERVICESTARTEVENT_H_INCLUDED

#ifndef STORAGECONGESTIONIMPACTEDSERVICE_H_INCLUDED
#define STORAGECONGESTIONIMPACTEDSERVICE_H_INCLUDED

class StorageCongestionImpactedService{
    private:
        int impactedServiceID;
        bool serviceStopDropped;
    public:
        void setImpactedServiceID(int impactedServiceID);
        void setServiceStopDropped(bool s);

        int getImpactedServiceID();
        bool getServiceStopDropped();
        StorageCongestionImpactedService();
};

#endif // STORAGECONGESTIONIMPACTEDSERVICE_H_INCLUDED

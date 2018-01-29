#ifndef SERVICERUNNING_H_INCLUDED
#define SERVICERUNNING_H_INCLUDED

class ServiceRunning{
    private:
        std::string serviceName;
    public:
        ServiceRunning(std::string serviceName);
        ~ServiceRunning();

        void setServiceName(std::string serviceName);
        std::string getServiceName();
};

#endif // SERVICERUNNING_H_INCLUDED

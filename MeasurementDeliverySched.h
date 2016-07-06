#ifndef MEASUREMENTDELIVERYSCHED_H_INCLUDED
#define MEASUREMENTDELIVERYSCHED_H_INCLUDED
#include <vector>
#include "DeliveryWindow.h"
#include <string>
#include "XmlDomDocument.h"
class ImmediatePush{
    private:
        unsigned measurementReportNumbByPush;
        unsigned maxTimeBetweenDelivery;
    public:
        unsigned getMeasurementReportNumbByPush();
        unsigned getMaxTimeBetweenDelivery();

        void setMeasurementReportNumbByPush(unsigned num);
        void setMaxTimeBetweenDelivery(unsigned seconds);
        ImmediatePush();
        void parsingImmeadiatePush(DOMElement *raiz);

};

class DelayedDelivery{
    private:
        std::vector<DeliveryWindow*> deliveryWindow;
        bool hybrid;
    public:
        ~DelayedDelivery();
        std::vector<DeliveryWindow*>& getDeliveryWindow();
        bool getHybrid();
        void setHybrid(bool hybrid);
        void setDeliveryWindow(std::vector<DeliveryWindow*> deliveryWindow);
        DelayedDelivery();
        void parsingDelayedDelivery(DOMElement *raiz, bool hybrid);


};



class MeasurementDeliverySched{
    private:
        std::vector<std::string> deliveryAddress;
        unsigned retransmitNumb;
        short storeCongestPolicy;
        ImmediatePush *immediatePush;
        DelayedDelivery *delayedDelivery;
        DelayedDelivery *delayedPullandPush;
        bool pull;
    public:
        ~MeasurementDeliverySched();
        std::vector<std::string> getDeliveryAddress();
        unsigned getRetransmitNumb();
        short getStoreCongestPolicy();
        ImmediatePush *getImmediatePush();
        DelayedDelivery *getDelayedDelivery();
        DelayedDelivery *getDelayedPullandPush();
        bool getPull();
        MeasurementDeliverySched();

        void setDeliveryAddress(std::vector<std::string> deliveryAddress);
        void setRetransmitNumber(unsigned retransmit);
        void setStorageCongestPolicy(short policy);
        void setImmediatePush(ImmediatePush *immediate);
        void setDelayedDelivery(DelayedDelivery *delayedDelivery);
        void setPull(bool pull);
        void parsingDeliverySched(DOMElement *raiz);
        void setDelayedPullandPush(DelayedDelivery *pullandPush);


};


#endif // MEASUREMENTDELIVERYSCHED_H_INCLUDED

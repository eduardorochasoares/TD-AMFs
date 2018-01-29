#ifndef MEASUREMENTSET_H_INCLUDED
#define MEASUREMENTSET_H_INCLUDED
#include "AllContentClassExceptList.h"
#include "MeasurementPeriod.h"
#include "DeliveryWindow.h"
#include "MeasurementRequest.h"
#include "XmlDomDocument.h"

class MeasurementSet{
    private:
        AllContentClassExceptList *defaultContentClassExceptList;
        std::vector<MeasurementPeriod*> measurementPeriods;
        int defaultPeriodicity;
        short defaultNothingNewToReport;
        int defaultInterval;
        std::vector<std::string> defaultDeliveryAddress;
        int defaultRetransmitNumber;
        short defaultStorageCongestPolicy;
        int defaultMeasurementReportNumberByPush;
        int defaultMaxTimeBetweenDelivery;

        std::vector<DeliveryWindow*> deliveryWindow;
        std::vector<MeasurementRequest*> measurementRequests;

    public:
        AllContentClassExceptList *getAllContentClassExceptList();
        std::vector<MeasurementPeriod*>& getMeasurementPeriod();
        int getDefaultPeriodicity();
        short getDefaultNothingNewToReport();
        int getDefaultInterval();
        std::vector<std::string>& getDefaultDeliveryAddress();
        int getDefaultRetransmitNumber();
        short getDefaultStorageCongestPolicy();
        int getDefaultMeasurementReportNumberByPush();
        int getDefaultMaxTimeBetweenDelivery();
        std::vector<DeliveryWindow*>& getDeliveryWindow();
        std::vector<MeasurementRequest*>& getMeasurementRequests();

        ~MeasurementSet();
        MeasurementSet();

        void setAllContentClassExcpt(AllContentClassExceptList *a);
        void setMeasurementPeriod(std::vector<MeasurementPeriod*> mp);
        void setDefaultPeriodicity(int periodicity);
        void setDefaultNothingNewToReport(short n);
        void setDefaultInterval(int interval);
        void setDefaultAddress(std::vector<std::string> address);
        void setDefaultRetransmitNumber(int retransmit);
        void setDefaultStorageCongestPolicy(short policy);
        void setDefaultMeasurementReportNumberByPush(int n);
        void setDeliveryWindow(std::vector<DeliveryWindow*> d);
        void setMeasurementRequest(std::vector<MeasurementRequest*> mr);

        void parsingMeasurementSet(DOMElement *raiz);




};


#endif // MEASUREMENTSET_H_INCLUDED

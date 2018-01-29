#ifndef AMREPORTPACKAGE_H_INCLUDED
#define AMREPORTPACKAGE_H_INCLUDED
#include "MeasurementReport.h"
#include "StorageCongestionImpactedService.h"
#include <vector>
using namespace std;

class AMReportPackage{
    private:
        string subscriberID;
        string terminalDeviceID;
        vector<StorageCongestionImpactedService*> storageImpactedServID;
        vector<MeasurementReport*> measurementReports;

    public :
        void setSubscriberID(string subscriberID);
        void setTerminalDeviceID(string terminalDevID);
        void setMeasurementReports(vector<MeasurementReport*> m);
        void setStorageCongestionImpactedService(vector<StorageCongestionImpactedService*> s);
        string getSubscriberID();
        string getTerminalDevID();
        vector<StorageCongestionImpactedService*>& getStorageCongestionImpacted();
        vector<MeasurementReport*>& getMeasurementReports();
        ~AMReportPackage();
        AMReportPackage();

        void writeXML();
};

#endif // AMREPORTPACKAGE_H_INCLUDED

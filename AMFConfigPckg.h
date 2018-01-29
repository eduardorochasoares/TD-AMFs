#ifndef AMFCONFIGPCKG_H_INCLUDED
#define AMFCONFIGPCKG_H_INCLUDED
#include "MeasurementSet.h"
#include <ctime>
#include <vector>
#include "XmlDomDocument.h"



class AMFConfigPckg{
    private :
        int packageID;
        int packageVersion;
        struct tm *effectiveDateTime;
        std::vector<MeasurementSet*> measurementSet;
    public :
        int getPackageID();
        int getPackageVersion();
        struct tm *getEffectiveDateTime;
        std::vector<MeasurementSet*>& getMeasurementSet();

        void setPackageID(int id);
        void setPackageVersion(int id);
        void setEffectiveDateTime(struct tm *effectiveDateTime);
        void setMeasurementSet(std::vector<MeasurementSet*> measurementSet);

        void parsingAmfConfigPckg(DOMElement *raiz);
        ~AMFConfigPckg();
        AMFConfigPckg();


};

#endif // AMFCONFIGPCKG_H_INCLUDED

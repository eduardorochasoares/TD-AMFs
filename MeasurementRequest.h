#ifndef MEASUREMENTREQUEST_H_INCLUDED
#define MEASUREMENTREQUEST_H_INCLUDED
#include "LinearTVQualifier.h"
#include "MeasurementDeliverySched.h"
#include "MeasurementSchedule.h"
#include "XmlDomDocument.h"
#include "AllContentClassExceptList.h"
class MeasurementRequest{
    private:
        unsigned measurementRequestID;
        LinearTVQualififer *ltvq;
        std::vector<MeasurementSchedule*> measurementSched;
        MeasurementDeliverySched *deliverySched;
        AllContentClassExceptList *classExceptList;
    public:
        ~MeasurementRequest();
        MeasurementRequest();
        unsigned getMeasurementRequestID();
        LinearTVQualififer *getLinearTvQualifier();
        std::vector<MeasurementSchedule*>& getMeasurementSched();
        MeasurementDeliverySched *getMeasurementDeliverySched();
        AllContentClassExceptList *getClassExceptList();
        void setMeasurementID(unsigned id);
        void setLinearTvQualifier(LinearTVQualififer *ltq);
        void setMeasurementSched(std::vector<MeasurementSchedule*> ms);
        void setMeasurementDelivery(MeasurementDeliverySched *mds);
        void setClassExceptList(AllContentClassExceptList *all);
        void parsingMeasurementRequest(DOMElement *raiz);
};


#endif // MEASUREMENTREQUEST_H_INCLUDED

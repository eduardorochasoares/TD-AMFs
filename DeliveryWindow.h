#ifndef DELIVERYWINDOW_H_INCLUDED
#define DELIVERYWINDOW_H_INCLUDED
#include <ctime>
#include "XmlDomDocument.h"


class DeliveryWindow{
    private:
        struct tm *startTime;
        struct tm *endTime;
    public:

        struct tm *getStartTime();
        struct tm *getEndTime();
        void setStartTime(struct tm *s);
        void setEndTime(struct tm *e);
        ~DeliveryWindow();
        DeliveryWindow();
        void parsingDeliveryWindow(DOMElement *raiz, bool isDefault);
};


#endif // DELIVERYWINDOW_H_INCLUDED

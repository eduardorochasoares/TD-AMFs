#ifndef CONFIGURATIONPCKGREQUESTRESPONSE_H_INCLUDED
#define CONFIGURATIONPCKGREQUESTRESPONSE_H_INCLUDED
#include "Directive.h"
#include "XmlDomDocument.h"
class ConfigurationPckgRequestResponse{
    private:
        int configPckgCheckDelay;
        Directive *immediateMeasurement;
        Directive *futureMeasurement;
    public:
        Directive *getImmediateMeasurement();
        Directive *getFutureMeasurement();
        int getConfigPckgCheckDelay();
        void parsingConfigurationPckgRequestResponse(XmlDomDocument *doc);
        void setConfigPckgCheckDelay(int configCheckDelay);
        void setFutureMeasurement(Directive *f);
        void setImmeadiateMeasurement(Directive *i);
        ~ConfigurationPckgRequestResponse();
        ConfigurationPckgRequestResponse();

};


#endif // CONFIGURATIONPCKGREQUESTRESPONSE_H_INCLUDED

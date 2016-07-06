#ifndef LINEARTVQUALIFIER_H_INCLUDED
#define LINEARTVQUALIFIER_H_INCLUDED
#include <string>
#include <vector>
#include "XmlDomDocument.h"

class LinearTVQualififer{
    private:
        short navMethod;
        short controlDevice;
        short viewMode;
        short obscuration;
        std::vector<std::string> channelList;
        std::vector<std::string> allChannelsExceptList;

    public:
        short getNavMethod();
        short getControlDevice();
        short getViewMode();
        short getObscuration();
        std::vector<std::string>& getChannelList();
        std::vector<std::string>& getChannelExceptList();

        void setNavMethod(short navMethod);
        void setControlDevice(short controlDev);
        void setViewMode(short viewMode);
        void setObscuration(short obsc);
        LinearTVQualififer();
        void parsingLinearTVQualififer(DOMElement *raiz);
};

#endif // LINEARTVQUALIFIER_H_INCLUDED

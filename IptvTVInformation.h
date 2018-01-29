#ifndef IPTVTVINFORMATION_H_INCLUDED
#define IPTVTVINFORMATION_H_INCLUDED
#include <string>
#include <fstream>
using namespace std;
class IptvTvInformation{
    private : char iptvTVManuf[6];
    private : string iptvTVModel;
    private : string iptvSerialNum;

    public : void setIpvtManuf(char* manuf);
    public : void setIptvModel(string model);
    public : void setIptvSerialNum(string serialNum);

    public : char* getIptvManuf();
    public : string getModel();
    public : string getSerialNum();

    public: void writeXML(ofstream &xml);
    public: IptvTvInformation();
};


#endif // IPTVTVINFORMATION_H_INCLUDED

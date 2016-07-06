#ifndef PCINFORMATION_H_INCLUDED
#define PCINFORMATION_H_INCLUDED
#include <string>
#include <fstream>
using namespace std;
class PCInformation{
    private : char pcManuf[6];
    private : string pcModel;
    private : string pcSerialNum;

    public : void setPcManuf(char* pcManuf);
    public : void setPcModel(string pcModel);
    public : void setPcSerialNum(string pcSerialNum);

    public : char* getPcManuf();
    public : string getPcModel();
    public : string getPcSerialNum();
    public : void writeXML(ofstream &xml);

};

#endif // PCINFORMATION_H_INCLUDED

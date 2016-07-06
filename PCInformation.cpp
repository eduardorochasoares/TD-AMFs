#include "PCInformation.h"
#include <string.h>

void PCInformation::setPcManuf(char *pcManuf){
    strcpy(this->pcManuf,pcManuf);
}

void PCInformation::setPcModel(string pcModel){
    this->pcModel = pcModel;
}

void PCInformation::setPcSerialNum(string pcSerialNum){
    this->pcSerialNum = pcSerialNum;
}

char* PCInformation::getPcManuf(){
    return this->pcManuf;
}

string PCInformation::getPcModel(){
    return this->pcModel;
}
string PCInformation::getPcSerialNum(){
    return this->pcSerialNum;
}


void PCInformation::writeXML(ofstream &xml)
{
    xml<<"<PCInformation>"<<endl;
    xml<<"<PCManuf>"<<this->getPcManuf()<<"</PCManuf>";
    xml<<"<PCModel>"<<this->getPcModel()<<"</PCModel>"<<endl;
    xml<<"<PCSerialNum>"<<this->getPcSerialNum()<<"</PCSerialNum>"<<endl;
    xml<<"</PCInformation>"<<endl;
}

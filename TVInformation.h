#ifndef TVINFORMATION_H_INCLUDED
#define TVINFORMATION_H_INCLUDED
#include <fstream>
using namespace std;
class TVInformation{
    private :  short tvManuf;
    private : short tvModel;
    private : int tvSerialNum;

    public : void setTvManuf(short tvManuf);
    public : void setTvModel(short tvModel);
    public : void setTvSerialNum(int tvSerialNum);

    public : short getTvManuf();
    public : short getTvModel();
    public : int getTvSerialNum();
    public : void writeTVInfo(ofstream &xml);

    public : TVInformation();


};


#endif // TVINFORMATION_H_INCLUDED

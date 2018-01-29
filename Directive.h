#ifndef DIRECTIVE_H_INCLUDED
#define DIRECTIVE_H_INCLUDED
#include "AMFConfigPckg.h"
class Directive{
    private :
    int code;
    AMFConfigPckg *amfconfig;

    public :

        AMFConfigPckg *getAMFConfigPckg();
        int getCode();

        void setCode(int code);
        void setAMFConfigPckg(AMFConfigPckg *amf);
        Directive();
        ~Directive();
};

#endif // DIRECTIVE_H_INCLUDED

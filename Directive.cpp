#include "Directive.h"


AMFConfigPckg* Directive::getAMFConfigPckg()
{
    return this->amfconfig;
}

int Directive::getCode()
{
    return this->code;
}

void Directive::setCode(int code)
{
    this->code = code;
}

void Directive::setAMFConfigPckg(AMFConfigPckg* amf)
{
    this->amfconfig = amf;
}
Directive::~Directive()
{
    delete this->amfconfig;
}
Directive::Directive()
{
    this->amfconfig = NULL;
    this->code = 0;
}



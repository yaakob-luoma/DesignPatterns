#ifndef DEFAULT_HANDLER_H
#define DEFAULT_HANDLER_H

#include "AbstractInterfaceHandler.h"

class DefaultHandler : public AbstractInterfaceHandler
{
private:
    AbstractInterfaceHandler *nextHandler;

public:
    DefaultHandler();
    AbstractInterfaceHandler* setNext( AbstractInterfaceHandler *handler ) override;
    std::string handle( std::string request ) override;
};

#endif

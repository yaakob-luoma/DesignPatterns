#ifndef ABSTRACT_INTERFACE_HANDLER_H
#define ABSTRACT_INTERFACE_HANDLER_H

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif

class AbstractInterfaceHandler
{
public:
    virtual AbstractInterfaceHandler *setNext( AbstractInterfaceHandler *handler ) = 0;
    virtual std::string handle( std::string request ) = 0;
};

#endif

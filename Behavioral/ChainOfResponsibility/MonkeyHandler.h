#ifndef MONKEY_HANDLER_H
#define MONKEY_HANDLER_H

#include "DefaultHandler.h"

class MonkeyHandler : public DefaultHandler
{
public:
    std::string handle( std::string request ) override;
};

#endif

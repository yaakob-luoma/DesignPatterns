#ifndef SQUIRREL_HANDLER_H
#define SQUIRREL_HANDLER_H

#include "DefaultHandler.h"

class SquirrelHandler : public DefaultHandler
{
public:
    std::string handle( std::string request ) override;
};

#endif

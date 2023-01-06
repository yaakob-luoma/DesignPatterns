#ifndef DOG_HANDLER_H
#define DOG_HANDLER_H

#include "DefaultHandler.h"

class DogHandler : public DefaultHandler
{
public:
    std::string handle( std::string request ) override;
};

#endif

#include "DogHandler.h"

std::string DogHandler::handle( std::string request )
{
    if ( request == "MeatBall")
    {
        return "Dog: I'll eat the " + request + ".\n";
    }
    else
    {
        return DefaultHandler::handle(request);
    }
}

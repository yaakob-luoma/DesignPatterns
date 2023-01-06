#include "SquirrelHandler.h"

std::string SquirrelHandler::handle( std::string request ) override
{
    if( request == "Nut" )
    {
        return "Squirrel: I'll eat the " + request +".\n";
    }
    else
    {
        return DefaultHandler::handle(request);
    }
}

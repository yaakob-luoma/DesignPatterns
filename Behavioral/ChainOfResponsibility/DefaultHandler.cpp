#include "DefaultHandler.h"


DefaultHandler::DefaultHandler()
    : nextHandler( nullptr )
{}

AbstractInterfaceHandler* DefaultHandler::setNext( AbstractInterfaceHandler *handler )
{
    this->nextHandler = handler;
    return handler;
}

std::string DefaultHandler::handle( std::string request )
{
    if ( this->nextHandler )
    {
        return this->nextHandler->handle(request);
    }
    return {};
}

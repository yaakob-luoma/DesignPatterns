#ifndef ABSTRACT_OBSERVER_INTERFACE_H
#define ABSTRACT_OBSERVER_INTERFACE_H

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif

class ObserverInterface
{
public:
    virtual ~ObserverInterface(){};
    virtual void update( const std::string &message ) = 0;
};

#endif

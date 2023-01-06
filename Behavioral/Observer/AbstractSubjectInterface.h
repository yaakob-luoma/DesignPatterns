#ifndef ABSTRACT_SUBJECT_INTERFACE_H
#define ABSTRACT_SUBJECT_INTERFACE_H

#include "AbstractObserverInterface.h"

class SubjectInterface
{
public:
    virtual ~SubjectInterface(){};
    virtual void attach( ObserverInterface *observer ) = 0;
    virtual void detach( ObserverInterface *observer ) = 0;
    virtual void notify() = 0;
};

#endif

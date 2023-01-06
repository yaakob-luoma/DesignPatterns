#ifndef SUBJECT_H
#define SUBJECT_H

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#ifndef INCLUDE_LIST
#include <list>
#define INCLUDE_LIST
#endif

#include "AbstractSubjectInterface.h"

class Subject : public SubjectInterface
{
private:
    std::list<ObserverInterface *> observerList;
    std::string message;
public:
    virtual ~Subject();

    void attach( ObserverInterface * observer ) override;

    void detach( ObserverInterface *observer ) override;

    void notify() override;

    void createMessage( std::string message = "Empty" );

    void howManyObserver();

    void businessLogic();

};



#endif

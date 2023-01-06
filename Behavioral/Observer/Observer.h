#ifndef OBSERVER_H
#define OBSERVER_H

#include "AbstractObserverInterface.h"
#include "Subject.h"

class Observer : public ObserverInterface
{
private:
    std::string message;
    Subject &subject;
    static int staticNumber;
    int number;

public:
    Observer( Subject &subject );

    virtual ~Observer();

    void update( const std::string &message ) override;

    void removeMeFromTheList();

    void printInfo();

};




#endif

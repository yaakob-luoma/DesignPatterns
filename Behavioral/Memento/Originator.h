#ifndef ORIGINATOR_H
#define ORIGINATOR_H

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#include "AbstractMemento.h"
#include "ConcreteMemento.h"

class Originator
{
private:
    std::string state;
    std::string generateRandomString( int length = 10 );

public:
    Originator( std::string state );

    void doSomething();

    Memento* save();

    void restore( Memento *memento );
};

#endif

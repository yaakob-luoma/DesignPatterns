#ifndef INVOKER_H
#define INVOKER_H

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#include "AbstractInterfaceCommand.h"



class Invoker
{
private:
    AbstractInterfaceCommand *onStart;
    AbstractInterfaceCommand *onFinish;

public:
    ~Invoker();

    void setOnStart( AbstractInterfaceCommand *command );
    void setOnFinish( AbstractInterfaceCommand *command );
    void doSomethingImportant();
};

#endif

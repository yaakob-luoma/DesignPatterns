#ifndef COMPONENT_1_H
#define COMPONENT_1_H

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#include "BaseComponent.h"

class Component1 : public BaseComponent
{
public:
    void doA();

    void doB();
};

#endif

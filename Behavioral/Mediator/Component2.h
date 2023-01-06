#ifndef COMPONENT_2_H
#define COMPONENT_2_H

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#include "BaseComponent.h"

class Component2 : public BaseComponent
{
public:
    void doC();
    void doD();
};



#endif

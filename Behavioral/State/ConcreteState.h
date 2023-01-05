#ifndef CONCRETESTATE_H
#define CONCRETESTATE_H

#include "State.h"

class ConcreteState : public State
{
public:
    static State* Instance();
    ~ConcreteState();

    virtual void handle(Context* );
    virtual void handle1(Context* );
    virtual void handle2(Context* );
    virtual void handle3(Context* );

protected:
    ConcreteState();

private:
    static ConcreteState* _instance;
};

#endif // CONCRETESTATE_H

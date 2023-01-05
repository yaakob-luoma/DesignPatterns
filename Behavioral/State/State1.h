#ifndef STATE1_H
#define STATE1_H

#include "State.h"

class State1 : public State
{
public:
    static State* Instance();
    ~State1();

    virtual void handle(Context* );
    virtual void handle1(Context* );
    virtual void handle2(Context* );
    virtual void handle3(Context* );

protected:
    State1();

private:
    static State1* _instance;
};

#endif // STATE1_H

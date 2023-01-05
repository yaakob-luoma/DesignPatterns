#ifndef STATE2_H
#define STATE2_H

#include "State.h"

class State2 : public State
{
public:
    static State* Instance();
    ~State2();

    virtual void handle(Context* );
    virtual void handle1(Context* );
    virtual void handle2(Context* );
    virtual void handle3(Context* );

protected:
    State2();

private:
    static State2* _instance;
};

#endif // STATE2_H

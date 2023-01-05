#ifndef STATE3_H
#define STATE3_H

#include "State.h"

class State3 : public State
{
public:
    static State* Instance();
    ~State3();

    virtual void handle(Context* );
    virtual void handle1(Context* );
    virtual void handle2(Context* );
    virtual void handle3(Context* );

protected:
    State3();

private:
    static State3* _instance;
};

#endif // STATE3_H

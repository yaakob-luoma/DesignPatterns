#ifndef CONTEXT_H
#define CONTEXT_H

//#include "ConcreteState.h"
//#include "State1.h"
//#include "State2.h"
//#include "State3.h"

class State;
class ConcreteState;
class State1;
class State2;
class State3;

class Context
{
public:
    Context(State* state = nullptr);
    ~Context();

    void request();
    void request1();
    void request2();
    void request3();

private:
    friend class State;
    State* state;
    void changeState(State*);
};

#endif // CONTEXT_H

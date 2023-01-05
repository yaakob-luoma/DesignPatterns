#ifndef STATE_H
#define STATE_H

#include <QDebug>

#include "Context.h"

class State
{
public:
    State();
    ~State();

    virtual void handle(Context* );
    virtual void handle1(Context* );
    virtual void handle2(Context* );
    virtual void handle3(Context* );

protected:
    void changeState( Context*, State* );
};

#endif // STATE_H

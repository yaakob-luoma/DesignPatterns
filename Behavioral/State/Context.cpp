#include "Context.h"
#include "State.h"

Context::Context()
{
    state = ConcreteState::Instance();
}

Context::~Context()
{
    if ( state != nullptr )
    {
        delete state;
    }
}

void Context::changeState( State* s )
{
    state = s;
}

void Context::request()
{
    state->handle(this);
}

void Context::requestState1()
{
    state->handleState1(this);
}

void Context::requestState2()
{
    state->handleState2(this);
}

void Context::requestState3()
{
    state->handleState3(this);
}


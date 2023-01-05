#include "ConcreteState.h"
#include "State1.h"

ConcreteState* ConcreteState::_instance = nullptr;

ConcreteState::ConcreteState()
{

}

State* ConcreteState::Instance()
{
    if ( _instance == nullptr )
    {
        _instance = new ConcreteState;
    }
    return _instance;
}

ConcreteState::~ConcreteState()
{
    if ( _instance != nullptr )
    {
        delete _instance;
    }
}

void ConcreteState::handle(Context * c)
{
    // do process then move to next state
    qDebug() << "ConcreteState handle";
    c->changeState( State1::Instance() );
}

void ConcreteState::handle1(Context * c)
{
    // do process then move to next state
   qDebug() << "ConcreteState handle 1";
}

void ConcreteState::handle2(Context * c)
{
    // do process then move to next state
    qDebug() << "ConcreteState handle 2";
}

void ConcreteState::handle3(Context * c)
{
    // do process then move to next state
    qDebug() << "ConcreteState handle 3";
}


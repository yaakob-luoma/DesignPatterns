#include "State3.h"

State* State3::_instance = nullptr;

State3::State3()
{

}

State *State3::Instance()
{
    if ( _instance == nullptr )
    {
        _instance = new State3;
    }
    return _instance;
}

State3::~State3()
{
    if ( _instance != nullptr )
    {
        delete _instance;
    }
}

void State3::handle(Context * c)
{
    // do process then move to next state
    qDebug() << "State3 handle";
}

void State3::handle1(Context * c)
{
    // do process then move to next state
    qDebug() << "State3 handle 1";
}

void State3::handle2(Context * c)
{
    // do process then move to next state
    qDebug() << "State3 handle 2";

}

void State3::handle3(Context * c)
{
    // do process then move to next state
    qDebug() << "State3 handle 3";
    changeState(c, ConcreteState::Instance() );
}


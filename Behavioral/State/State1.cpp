#include "State1.h"

State* State1::_instance = nullptr;

State1::State1()
{

}

State *State1::Instance()
{
    if ( _instance == nullptr )
    {
        _instance = new State1;
    }
    return _instance;
}

State1::~State1()
{
    if ( _instance != nullptr )
    {
        delete _instance;
    }
}

void State1::handle(Context * c)
{
    // do process then move to next state
    qDebug() << "State1 handle";
}

void State1::handle1(Context * c)
{
    // do process then move to next state
    qDebug() << "State1 handle 1";
    changeState(c, State2::Instance() );
}

void State1::handle2(Context * c)
{
    // do process then move to next state
    qDebug() << "State1 handle 2";
}

void State1::handle3(Context * c)
{
    // do process then move to next state
    qDebug() << "State1 handle 3";
}

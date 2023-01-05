#include "State2.h"

State* State2::_instance = nullptr;

State2::State2()
{

}

State *State2::Instance()
{
    if ( _instance == nullptr )
    {
        _instance = new State2;
    }
    return _instance;
}

State2::~State2()
{
    if ( _instance != nullptr )
    {
        delete _instance;
    }
}

void State2::handle(Context * c)
{
    // do process then move to next state
    qDebug() << "State2 handle";
}

void State2::handle1(Context * c)
{
    // do process then move to next state
    qDebug() << "State2 handle 1";
}

void State2::handle2(Context * c)
{
    // do process then move to next state
    qDebug() << "State2 handle 2";
    c->changeState( State3::Instance() );
}

void State2::handle3(Context * c)
{
    // do process then move to next state
    qDebug() << "State2 handl 3";
}


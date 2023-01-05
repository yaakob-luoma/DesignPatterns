#include "Singleton.h"

Singleton* Singleton::_instance = nullptr;

Singleton* Singleton::instance()
{
    if ( instance == nullptr )
    {
        instance = new Singleton;
    }
    return instance;
}

Singleton::Singleton()
{

}

Singleton::~Singleton()
{

}


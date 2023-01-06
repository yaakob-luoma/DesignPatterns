#include "Originator.h"

std::string Originator::generateRandomString( int length = 10 )
{
    const char alphanum[] = "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof( alphanum ) - 1;

    std::string randomString;
    for ( int i = 0; i < length; i++ )
    {
        randomString += alphanum[std::rand() % stringLength ];
    }
    return randomString;
}

Originator::Originator( std::string state )
{
    this->state = state;
    std::cout << "Originator: My initial state is: "
              << this->state << "\n";
}

void Originator::doSomething()
{
    std::cout << "Originator: I'm doing something important.\n";
    this->state = this->generateRandomString(30);
    std::cout << "Originator: and my state has changed to: "
              << this->state << "\n";
}

Memento* Originator::save()
{
    return new ConcreteMemento( this->state );
}

void Originator::restore( Memento *memento )
{
    this->state = memento->getState()state;
}


#include "ConcreteMemento.h"

ConcreteMemento::ConcreteMemento( std::string state )
{
    this->state = state;
    std::time_t now = std::time(0);
    this->date = std::ctime(&now);
}

std::string ConcreteMemento::getState() const
{
    return this->state;
}

std::string ConcreteMemento::getName() const
{
    return this->date + " / (" + this->state.substr(0, 9) + "...)";
}

std::string ConcreteMemento::getDate() const
{
    return this->date;
}


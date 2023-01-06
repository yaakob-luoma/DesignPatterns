#include "Observer.h"

Observer::Observer( Subject &subject)
{
    /* TODO: check that subject is not null */
    this->subject = subject;
    this->subject.attach(this);
    std::cout << "Hi, I'm the Observer\"" << ++Observer::staticNumber
              << "\".\n";
    this->number = Observer::staticNumber;
}

Observer::~Observer()
{
    std::cout << "Goodbye, I was the Observer \"" << this->number
              << "\".\n";
}

void Observer::update( const std::string &message )
{
    this->message = message;
    printInfo();
}

void Observer::removeMeFromTheList()
{
    this->subject.detach(this);
    std::cout << "Observer \"" << this->number
              << "\" removed from the list.\n";
}

void Observer::printInfo()
{
    std::cout << "Observer \"" << this->number
              << "\": a new message is available --> "
              << this->message << "\n";
}

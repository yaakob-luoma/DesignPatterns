#include "Subject.h"


Subject::~Subject()
{
    std::cout << "Goodbye, I was the Subject.\n";
}

void Subject::attach( ObserverInterface * observer )
{
    observerList.push_back(observer );
}

void Subject::detach( ObserverInterface *observer )
{
    observerList.remove( observer );
}

void Subject::notify()
{
    std::list< ObserverInterface *>::iterator iterator = observerList.begin();
    howManyObserver();
    while( iterator != observerList.end() )
    {
        (*iterator)->update(message);
        ++iterator;
    }
}

void Subject::createMessage( std::string message )
{
    this->message = message;
    notify();
}

void Subject::howManyObserver()
{
    std::cout << "There are " << observerList.size() << " observers in the lsit.\n";
}

void Subject::businessLogic()
{
    this->message = "change message message";
    notify();
    std::cout << "I'm about to do some thing important.\n";
}

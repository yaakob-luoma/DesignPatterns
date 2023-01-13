#include "Observer.h"
#include "Subject.h"

int Observer::staticNumber = 0;

void clientCode()
{
    Subject *subject = new Subject;
    Observer *observer1 = new Observer(*subject);
    Observer *observer2 = new Observer(*subject);
    Observer *observer3 = new Observer(*subject);
    Observer *observer4;
    Observer *observer5;

    subject->createMessage("Hello World! :D");
    observer3->removeMeFromTheList();

    subject->createMessage("The weather is hot today!");
    observer4 = new Observer( *subject );

    observer2->removeMeFromTheList();
    observer5 = new Observer( *subject);

    subject->createMessage( "My new car is great");
    observer5->removeMeFromTheList();

    observer4->removeMeFromTheList();
    observer1->removeMeFromTheList();

    delete observer5;
    delete observer4;
    delete observer3;
    delete observer2;
    delete observer1;
}

int main()
{
    clientCode();
    return 0;
}

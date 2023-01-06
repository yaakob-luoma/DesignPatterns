
#include <iostream>
#include <list>
#include <string>

class ObserverInterface
{
public:
    virtual ~ObserverInterface(){};
    virtual void update( const std::string &message ) = 0;
};

class SubjectInterface
{
public:
    virtual ~SubjectInterface(){};
    virtual void attach( ObserverInterface *observer ) = 0;
    virtual void detach( ObserverInterface *observer ) = 0;
    virtual void notify() = 0;
};

class Subject : public SubjectInterface
{
private:
    std::list<ObserverInterface *> observerList;
    std::string message;
public:
    virtual ~Subject()
    {
        std::cout << "Goodbye, I was the Subject.\n";
    }
    void attach( ObserverInterface * observer ) override
    {
        observerList.push_back(observer );
    }

    void detach( ObserverInterface *observer ) override
    {
        observerList.remove( observer );
    }
    void notify() override
    {
        std::list< ObserverInterface *>::iterator iterator = observerList.begin();
        howManyObserver();
        while( iterator != observerList.end() )
        {
            (*iterator)->update(message);
            ++iterator;
        }
    }
    void createMessage(std::string message = "Empty")
    {
        this->message = message;
        notify();
    }
    void howManyObserver()
    {
        std::cout << "There are " << observerList.size() << " observers in the lsit.\n";
    }
    void businessLogic()
    {
        this->message = "change message message";
        notify();
        std::cout << "I'm about to do some thing important.\n";
    }
};

class Observer : public ObserverInterface
{
private:
    std::string message;
    Subject &subject;
    static int staticNumber;
    int number;

public:
    Observer( Subject &subject)
    {
        this->subject = subject;
        this->subject.attach(this);
        std::cout << "Hi, I'm the Observer\"" << ++Observer::staticNumber
                  << "\".\n";
        this->number = Observer::staticNumber;
    }
    virtual ~Observer()
    {
        std::cout << "Goodbye, I was the Observer \"" << this->number
                  << "\".\n";
    }

    void update( const std::string &message ) override
    {
        this->message = message;
        printInfo();
    }
    void removeMeFromTheList()
    {
        this->subject.detach(this);
        std::cout << "Observer \"" << this->number
                  << "\" removed from the list.\n";
    }
    void printInfor()
    {
        std::cout << "Observer \"" << this->number
                  << "\": a new message is available --> "
                  << this->message << "\n";
    }
};

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

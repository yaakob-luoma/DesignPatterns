
#include <iostream>
#include <typeinfo>


class Context;

class State
{
protected:
    Context *context_ptr;

public:
    virtual ~State() {}

    void setContext( Context *context )
    {
        this->context_ptr = context;
    }

    virtual void handle1() = 0;
    virtual void handle2() = 0;
};

class Context
{
private:
    State *state_ptr;

public:
    Context( State *state )
        : state_ptr( nullptr )
    {
        this->transitionTo(state);
    }
    ~Context()
    {
        delete state_ptr;
    }

    void transitionTo( State *state )
    {
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
        if ( this->state_ptr != nullptr )
        {
            delete this->state_ptr;
        }
        this->state_ptr = state;
        this->state_ptr->setContext( this );
    }

    void request1()
    {
        this->state_ptr->handle1();
    }
    void request2()
    {
        this->state_ptr->handle2();
    }
};

class ConcreteStateA : public State
{
public:
    void handle1() override
    {
        std::cout << "ConcreteStateA handles request1.\n";
        std::cout << "ConcreteStateA wants to change the state of the context.\n";
        this->context_ptr->transitionTo( new ConcreteStateB );
    }
    void handle2() override
    {
        std::cout << "ConcreteStateA handles request2.\n";
    }
};

class ConcreteStateB : public State
{
public:
    void handle1() override
    {
        std::cout << "ConcreteStateB handles request1.\n";
    }
    void handle2() override
    {
        std::cout << "ConcreteStateB handles request2.\n";
        std::cout << "ConcreteStateB wants to change the state of the context.\n";
        this->context_ptr->transitionTo( new ConcreteStateA );
    }
};



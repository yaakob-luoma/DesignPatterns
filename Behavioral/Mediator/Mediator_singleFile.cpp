
class BaseComponent;
class Mediator
{
public:
    virtual void notify( BaseComponent *sender, std::string event ) const = 0;
};

class BaseComponent
{
protected:
    Mediator *mediator_ptr;
public:
    BaseComponent( Mediator *mediator = nullptr ) : mediator_ptr(mediator){}
    void setMediator( Mediator *mediator )
    {
        mediator_ptr = mediator;
    }
};

class Component1 : public BaseComponent
{
public:
    void doA()
    {
        std::cout << "Component 1 does A.\n";
        mediator_ptr->notify(this, "A");
    }
    void doB()
    {
        std::cout << "Component 1 does B.\n";
        mediator_ptr->notify(this, "B");
    }
};

class Component2 : public BaseComponent
{
public:
    void doC()
    {
        std::cout << "Component 2 does C.\n";
        mediator_ptr->notify(this, "C");
    }
    void doD()
    {
        std::cout << "Component 2 does D.\n";
        mediator_ptr->notify( this, "D");
    }
};

class ConcreteMediator : public Mediator
{
private:
    Component1 *component1_ptr;
    Component2 *component2_ptr;

public:
    ConcreteMediator( Component1 *c1
                      , Component2 *c2 )
        : component1_ptr( c1 ), component2_ptr( c2 )
    {
        component1_ptr->setMediator( this );
        component2_ptr->setMediator( this );
    }
    void notify( BaseComponent *sender
                 , std::string event ) const override
    {
        if ( event == "A" )
        {
            std::cout << "Mediator reacts on A and triggers following operations:\n";
            component2_ptr->doC();
        }
        if ( event == "D" )
        {
            std::cout << "Mediator reacts on D and triggers following operations:\n";
            component1_ptr->doB();
            component2_ptr->doC();
        }
    }
};

void clientCode()
{
    Component1 *c1 = new Component1;
    Component2 *c2 = new Component2;
    ConcreteMediator *mediator = new ConcreteMediator( c1, c2);
    std::cout << "Client tiggers operation A.\n";
    c1->doA();
    std::cout << "\n";
    std::cout << "Client triggers operation B.\n";
    c2->doD();

    delete c1;
    delete c2;
    delete mediator;
}

int main()
{
    clientCode();
    return 0;
}

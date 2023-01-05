
#include <string>
#include <iostream>

class Handler
{
public:
    virtual Handler *setNext( Handler *handler ) = 0;
    virtual std::string handle( std::string request ) = 0;
};

class AbstractHandler : public Handler
{
private:
    Handler *nextHandler;

public:
    AbstractHandler() : nextHandler( nullptr ) {}
    Handler* setNext( Handler *handler ) override
    {
        this->nextHandler = handler;
        return handler;
    }
    std::string handle( std::string request ) override
    {
        if ( this->nextHandler )
        {
            return this->nextHandler->handle(request);
        }
        return {};
    }
};

class MonkeyHandler : public AbstractHandler
{
public:
    std::string handle( std::string request ) override
    {
        if ( request == "Banana")
        {
            return "Monkey: I'll eat the " + request +".\n";
        }
        else
        {
            return AbstractHandler::handle(request);
        }
    }
};

class SquirrelHandler : public AbstractHandler
{
public:
    std::string handle( std::string request ) override
    {
        if( request == "Nut" )
        {
            return "Squirrel: I'll eat the " + request +".\n";
        }
        else
        {
            return AbstractHandler::handle(request);
        }
    }
};

class DogHandler : public AbstractHandler
{
public:
    std::string handle( std::string request ) override
    {
        if ( request == "MeatBall")
        {
            return "Dog: I'll eat the " + request + ".\n";
        }
        else
        {
            return AbstractHandler::handle(request);
        }
    }
};

void clientCode( Handler &handler )
{
    std::vector<std::string> food = {"Nut", "Banna", "Cup of coffee"};
    for ( const std::string &f : food )
    {
        std::cout << "Client: Who wants a " << f << "?\n";
        const std::string result = handler.handle(f);
        if ( !result.empty() )
        {
            std::cout << " " << result;
        }
        else
        {
            std::cout << " " << f << " was left untoched.\n";
        }
    }
}

int main()
{
    MonkeyHandler *monkey = new MonkeyHandler();
    SquirrelHandler *squrrel = new SquirrelHandler();
    DogHandler *dog = new DogHandler();
    monkey->setNext( squrrel )->setNext( dog);

    std::cout << "Chain: Monkey > Squirrel > Dog\n\n";
    clientCode(*monkey);
    std::cout << "\n";
    std::cout << "Subchain: Squirrel > Dog\n\n";
    clientCode(*squrrel);

    delete monkey;
    delete squrrel;
    delete dog;

    return 0;
}

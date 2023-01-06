#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif

#ifndef INCLUDE_VECTOR
#include <vector>
#define INCLUDE_VECTOR
#endif

#include "AbstractInterfaceHandler.h"
#include "DogHandler.h"
#include "MonkeyHandler.h"
#include "SquirrelHandler.h"

void clientCode( AbstractInterfaceHandler &handler )
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

int main( int argc, char** argv )
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

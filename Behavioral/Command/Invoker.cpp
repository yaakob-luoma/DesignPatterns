#include "Invoker.h"


Invoker::~Invoker()
{
    delete onStart;
    delete onFinish;
}

void Invoker::setOnStart( AbstractInterfaceCommand *command )
{
    this->onStart = command;
}
void Invoker::setOnFinish( AbstractInterfaceCommand *command )
{
    this->onFinish = command;
}
void Invoker::doSomethingImportant()
{
    std::cout << "Invoker: Does anybody want something done before I begin?\n";
    if (this->onStart )
    {
        this->onStart->execute();
    }
    std::cout << "Invoker: ...doing something really important...\n";
    std::cout << "Invoker: Does anybody want something done after I finish?\n";
    if (this->onFinish )
    {
        this->onFinish->execute();
    }
}

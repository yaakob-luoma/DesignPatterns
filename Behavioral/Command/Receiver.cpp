#include "Receiver.h"

void Receiver::doSomething( const std::string &data)
{
    std::cout << "Receiver: Working on ("
              << data
              << ".)\n";
}
void Receiver::doSomethingElse( const std::string &data )
{
    std::cout << "Receiver: Also working on("
              << data
              << ".)\n";
}


#include "SimpleCommand.h"


SimpleCommand::SimpleCommand( std::string payLoad )
{
    this->payLoad = payLoad;
}

void SimpleCommand::execute() const
{
    std::cout << "SimpleCommand: See, I can do simple things like printing ("
              << this->payLoad
               << ")\n";
}


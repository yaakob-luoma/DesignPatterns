
#ifndef SIMPLE_COMMAND_H
#define SIMPLE_COMMAND_H

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#include "AbstractInterfaceCommand.h"

class SimpleCommand : public AbstractInterfaceCommand
{
private:
    std::string payLoad;

public:
    explicit SimpleCommand( std::string payLoad );
    void execute() const override;
};

#endif

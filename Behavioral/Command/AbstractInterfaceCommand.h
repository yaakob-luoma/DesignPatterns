#ifndef ABSTRACT_INTERFACE_COMMAND_H
#define ABSTRACT_INTERFACE_COMMAND_H

class AbstractInterfaceCommand
{
public:
    virtual ~AbstractInterfaceCommand(){};
    virtual void execute() const = 0;
};

#endif

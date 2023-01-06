#ifndef COMPLEX_COMMAND_H
#define COMPLEX_COMMAND_H

#include "AbstractInterfaceCommand.h"
#include "Receiver.h"

class ComplexCommand : public AbstractInterfaceCommand
{
private:
    Receiver *receiver_ptr;
    std::string dataA;
    std::string dataB;

public:
    ComplexCommand( Receiver *receiver
                    , std::string a
                    , std::string b);
    void execute() const override;
};



#endif

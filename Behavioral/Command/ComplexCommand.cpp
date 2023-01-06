#include "ComplexCommand.h"


ComplexCommand::ComplexCommand( Receiver *receiver
                , std::string a
                , std::string b)
    : receiver_ptr(receiver)
    , dataA(a)
    , dataB(b)
{

}
void ComplexCommand::execute() const
{
    std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
    this->receiver_ptr->doSomething(dataA);
    this->receiver_ptr->doSomethingElse(dataB);
}

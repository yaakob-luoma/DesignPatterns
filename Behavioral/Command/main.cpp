#include "ComplexCommand.h"
#include "Invoker.h"
#include "SimpleCommand.h"
#include "Receiver.h"

int main( int argc, char** argv)
{
    Invoker *invoker = new Invoker();
    invoker->setOnStart( new SimpleCommand( "Say Hi!" ) );
    Receiver *receiver = new Receiver();
    invoker->setOnFinish( new ComplexCommand( receiver, "Send email", "Save report" ) );
    invoker->doSomethingImportant();

    delete invoker;
    delete receiver;

    return 0;
}

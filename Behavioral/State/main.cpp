#include "Context.h"
#include "State1.h"

void clientCode()
{
    Context *context = new Context( State1::Instance() );
    context->request1();
    context->request2();
    delete context;
}

int main()
{
    clientCode();
    return 0;
}

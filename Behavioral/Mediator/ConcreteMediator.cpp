#include "ConcreteMediator.h"

ConcreteMediaotr::ConcreteMediator( Component1 *c1
                  , Component2 *c2 )
    : component1_ptr( c1 ), component2_ptr( c2 )
{
    component1_ptr->setMediator( this );
    component2_ptr->setMediator( this );
}

void ConcreteMediator::notify( BaseComponent *sender
             , std::string event ) const
{
    if ( event == "A" )
    {
        std::cout << "Mediator reacts on A and triggers following operations:\n";
        component2_ptr->doC();
    }
    if ( event == "D" )
    {
        std::cout << "Mediator reacts on D and triggers following operations:\n";
        component1_ptr->doB();
        component2_ptr->doC();
    }
}

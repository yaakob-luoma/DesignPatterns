#include "BaseComponent.h"


BaseComponent::BaseComponent( Mediator *mediator = nullptr )
    : mediator_ptr(mediator)
{}

void BaseComponent::setMediator( Mediator *mediator )
{
    mediator_ptr = mediator;
}

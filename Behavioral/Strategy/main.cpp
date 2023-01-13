

void clientCode()
{
    Context *context = new Context( new ConcreteStrategyA );
    std::cout << "Client: Strategy is set to normal sorting.\n";
    context->businessLogic();
    std::cout << "\n";
    std::cout << "Client: Strategy is set to reverse sorting.\n";
    context->setStrategy( new ConcreteStrategyB );
    context->businessLogic();

    delete context;
}

int main()
{
    clientCode();
    return 0;
}
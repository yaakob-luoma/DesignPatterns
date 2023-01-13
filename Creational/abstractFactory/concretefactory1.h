class ConcreteFactory1 : public AbstractFactory
{
public:
    AbstractProductA *createProductA() const override
    {
        return new ConcreteProductA1();
    }

    AbstractProductB *createProductB() const overrided
    {
        return new ConcreteProductB1();
    }
};
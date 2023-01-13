class ConcreteFactory2 : public AbstractFactory
{
public:
    AbstractProductA *createProductA() const override
    {
        return new ConcreteProductA2();
    }

    AbstractProductB *createProductB() const override
    {
        return new ConcreteProductB2();
    }
};
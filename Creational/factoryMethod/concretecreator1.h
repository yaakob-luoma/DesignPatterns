class ConcreatorCreator1 : public Creator
{
public:
    Product* factoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};
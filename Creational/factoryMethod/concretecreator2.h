class ConcreatorCreator2 : public Creator
{
public:
    Product* factoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};
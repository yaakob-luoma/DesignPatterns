class ConcreteProductB1 : public AbstractProductB
{
public:
    std::string usefulFunctionB() const override
    {
        return "The result of the product B1.";
    }

    std::string anotherUsefulFunctionB( const AbstractProductA &collaborator) const override
    {
        const std::string result = collaborator.usefulFunctionA();
        return "The result of the B1 collaborating with( " + result + " )";
    }
};
class ConcreteProductA1 : public AbstractProductA
{
public:
    std::string usefulFunctionA() const override
    {
        return "The result of the product A1.";
    }
};
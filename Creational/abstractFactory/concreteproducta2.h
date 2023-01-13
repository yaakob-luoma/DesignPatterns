class ConcreteProductA2 : public AbstractProductA
{
public:
    std::string usefulFunctionA() const override
    {
        return "The result of the product A2";
    }
};
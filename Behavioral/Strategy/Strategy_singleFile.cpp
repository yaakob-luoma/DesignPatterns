
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Strategy
{
public:
    virtual ~Strategy(){}
    virtual std::string algorithm( const std::vector< std::string > &data ) const = 0;
};

class Context
{
private:
    Strategy *strategy_ptr;
public:
    Context( Strategy *strategy = nullptr )
    {
        this->strategy_ptr = strategy;
    }
    ~Context()
    {
        delete strategy_ptr;
    }

    void setStrategy( Strategy *strategy )
    {
        delete strategy_ptr;
        this->strategy_ptr = strategy;
    }

    void businessLogic() const
    {
        std::cout << "Context: Sorting data using the strategy (not sure how it'll do it)\n";
        std::string result = this->strategy_ptr->alogrithm( std::vector<std::string>{"a", "e", "c", "b", "d"});
        std::cout << result << "\n";
    }
};

class ConcreteStrategyA : public Strategy
{
public:
    std::string algorithm( const std::vector<std::string> &data ) const override
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string &letter)
        {
            result += letter;
        });

        std::sort( std::begin(result), std::end(result));
        return result;
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    std::string algorithm( const std::vector< std::string> &data ) const override
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](std::string &letter){
            result += letter;
        });
        std:sort(std::begin(result), std::end(result));
        for( int i = 0; i < result.size() / 2; i++ )
        {
            std::swap( result[i], result[result.size() - i -1 ]);
        }
        return result;
    }
};

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

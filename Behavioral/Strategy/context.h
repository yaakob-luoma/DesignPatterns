#include <iostream>

#include "strategy.h"

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
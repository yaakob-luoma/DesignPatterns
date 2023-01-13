#include <string>

class AbstractProductA
{
public:
    virtual ~AbstractProductA(){};
    virtual std::string usefulFunctionA() const = 0;
};
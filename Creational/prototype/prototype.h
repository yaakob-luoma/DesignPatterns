
#include <string>

class Prototype
{
protected:
    std::string name;
    float field;

public:
    Prototype(){}
    Prototype( std::string name )
    {
        this->name = name;
    }
    virtual ~Prototype(){}
    virtual Prototype* clone() const = 0;
    virtual void method( float field )
    {
        this->field = field;
        std::cout << "Call Method from "
                  << name
                  << " with field : "
                  << this->field
                  << std::endl;
    }
};
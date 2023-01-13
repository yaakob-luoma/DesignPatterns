#include <iostream>

class AbstractClass
{
public:
    void templateMethod() const
    {
        this->baseOperation1();
        this->requiredOperation1();
        this->baseOperation2();
        this->hook1();
        this->requiredOperation2();
        this->baseOperation3();
        this->hook2();
    }

protected:
    void baseOperation1() const
    {
        std::cout << "AbstractClass says: I am doing the bulk of the work.\n";
    }
    void baseOperation2() const
    {
        std::cout << "AbstractClass says: But I let subclasses override some operations.\n";
    }
    void baseOperation3() const
    {
        std::cout << "AbstractClass says: I am doing the bulk of the work anyway.\n";
    }
    virtual void requiredOperation1() const = 0;
    virtual void requiredOperation2() const = 0;

    virtual void hook1() const{};
    virtual void hook2() const{};
};
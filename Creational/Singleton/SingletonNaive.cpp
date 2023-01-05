
#include <string>
#include <iostream>

class Singleton
{
protected:
    static Singleton *singleton_ptr;
    std::string value;

    Singleton( const std::string value )
    {
        this->value = value;
    }
public:
    Singleton( Singleton &other ) = delete;
    void operator=( const Singleton &) = delete;
    static Singleton* getInstance( const std::string &value );
    void someBusinessLogic()
    {

    }
    std::string value() const
    {
        return value;
    }
};

Singleton* Singleton::singleton_ptr = nullptr;

Singleton* Singleton::getInstance(const std::string &value)
{
    if ( singleton_ptr == nullptr )
    {
        singleton_ptr = new Singleton( value );
    }
    return singleton_ptr;
}

void threadFoo()
{
    std::this_thread::sleep_for( std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::getInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void threadBar()
{
    std::this_thread::sleep_for( std::chrono::milliseconds(1000));
    Singleton *singleton = Singleton::getInstance("BAR");
    std::cout << singleton->value() << "\n";
}

int main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!)\n"
              << "If you see different values, then 2 singeltons were created (boo!)\n\n"
              << RESULTS:\n";
    std::thread t1(threadFoo);
    std::thread t2(threadBar);
    t1.join();
    t2.joint();
    return 0;
}

/*
 * EXPECTED OUTPUT:
 * If you see the same value, then singleton was reused(yay!)
 * If you see different values, then 2 singletons were created (boo!)
 *
 * RESULT:
 * BAR
 * FOO
 */

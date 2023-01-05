
#include <mutex>
#include <string>

class Singleton
{
private:
    static Singleton *instance_ptr;
    static std::mutex mutex;
protected:
    Singleton( const std::string value )
    {
        this->value = value;
    }
    ~Singleton(){}
    std::string value;
public:
    Singleton( Singleton &other ) = delete;
    void operator=( const Singelton & ) = delete;
    static Singleton* getInstance( const std::string &value );
    void someBusinessLogic()
    {

    }
    std::string value() const
    {
        return value;
    }
};

Singleton* Singleton::instance_ptr{nullptr};
std::mutex Singleton::mutex;

Singleton* Singleton::getInstance(const std::string &value)
{
    std::lock_guard<std::mutex> lock(mutex);
    if ( instance_ptr == nullptr )
    {
        instance_ptr = new Singleton( value );
    }
    return instance_ptr;
}

void threadFoo()
{
    std::this_thread::sleep_for( std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void threadBar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("BAR");
    std::cout << singleton->value() << "\n";
}

int main()
{
    std::cout << "If you see the same value, then singleton was reused (yay!)\n"
              << "If you see different values, then 2 singletons were created(boo!)\n"
              << "RESULT:\n";
    std::thread t1(threadFoo);
    std::thread t2(threadBar);
    t1.join();
    t2.join();

    return 0;
}

/*
 * EXPECTED OUTPUT:
 * If you see the same value, then singleton was reused (yay!)
 * If you see different values, then 2 singletons were created (boo!)
 *
 * Result:
 * FOO
 * FOO
 */

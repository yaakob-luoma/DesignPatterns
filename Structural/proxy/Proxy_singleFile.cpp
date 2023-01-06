
#include <iostream>

class Subject
{
public:
    virtual void request() const = 0;
};

class RealSubject : public Subject
{
public:
    void request() const override
    {
        std::cout << "RealSubject: Handling request.\n";
    }
};

class Proxy : public Subject
{
private:
    RealSubject *realSubject_ptr;

    bool checkAccess() const
    {
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }
    void logAccess() const
    {
        std::cout << "Proxy: Logging the time of request.\n";
    }
public:
    Proxy( RealSubject *realSubject ) : realSubject_ptr( new RealSubject(*realSubject ) ){}
    ~Proxy()
    {
        delete realSubject_ptr;
    }

    void request() const override
    {
        if ( this->checkAccess() )
        {
            this->realSubject_ptr->request();
            this->logAccess();
        }
    }
};

void clientCode( const Subject &subject )
{
    subject.request();
}

int main()
{
    std::cout << "Client: Executing the client code with a real subject:\n";
    RealSubject *realSubject = new RealSubject();
    clientCode( *realSubject );
    std::cout << "\n";
    std::cout << "Client: Executing the same client code with a proxy:\n";
    Proxy *proxy = new Proxy( realSubject );
    clientCode( *proxy );

    delete realSubject;
    delete proxy;
    return 0;
}

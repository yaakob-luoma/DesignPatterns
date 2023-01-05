#ifndef SINGLETON_H
#define SINGLETON_H


class Singleton
{
public:
    static Singleton* instance();

    //Singleton();
    ~Singleton();

protected:
    Singelton();

private:
    static Singleton* _instance;

};

#endif // SINGLETON_H

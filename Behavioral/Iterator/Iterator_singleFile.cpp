#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif

#ifndef INCLUDE_VECTOR
#include <vector>
#define INCLUDE_VECTOR
#endif

template< typename T, typename U>
class Iterator
{
public:
    typedef typename std::vector<T>::iterator iter_type;
    Iterator(U *data_ptr, bool reverse = false)
    {
        this->data_ptr = data_ptr;
        itr = data_ptr->data.begin();
    }
    void first()
    {
        itr = data_ptr->data.begin();
    }
    void next()
    {
        itr++;
    }
    bool isDone()
    {
        return ( itr == data_ptr->data.end());
    }
    iter_type current()
    {
        return itr;
    }

private:
    U *data_ptr;
    iter_type itr;
};

template< class T>
class Container
{
    friend class Iterator<T, Container>;
private:
    std::vector<T> data;
public:
    void add(T a)
    {
        data.push_back(a);
    }
    Iterator<T, Container>* createIterator()
    {
        return new Iterator<T, Container>(this);
    }
};

class Data
{
private:
    int data;
public:
    Data( int a = 0 ) : data(a){}
    void setData(int a )
    {
        data = a;
    }
    int getData()
    {
        return data;
    }
};

void clientCode()
{
    std::cout << "__________________Iterator with int____________________";
    Container<int> container;

    for ( int i = 0; i < 10; i++ )
    {
        container.add(i);
    }

    Iterator<int, Container<int>> *it = container.createInterator();
    for ( it->first(); !it->isDone(); it->next() )
    {
        std::cout << *it->current() << std::endl;
    }

    std::cout << "______________Iterator with custom class_________________";

    Container<Data> container2;
    Data a(100), b(1000), c(10000);
    container2.add( a );
    container2.add( b );
    container2.add( c );

    Iterator<Data, Container<Data>> *it2 = container2.createIterator();
    for ( it2->first(); !it2->isDone(); it2->next() )
    {
        std::cout << *it2->current() << std::endl;
    }

    delete it;
    delete it2;
}

int main()
{
    clientCode();
    return 0;
}

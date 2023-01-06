#ifndef CONTAINER_H
#define CONTAINER_H


#ifndef INCLUDE_VECTOR
#include <vector>
#define INCLUDE_VECTOR
#endif

#include "Iterator.h"

template< class T >
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

#endif

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#include "Container.h"
#include "Data.h"
#include "Iterator.h"


void clientCode()
{
    std::cout << "__________________Iterator with int____________________";
    Container<int> container;

    for ( int i = 0; i < 10; i++ )
    {
        container.add(i);
    }

    Iterator<int, Container<int>> *it = container.createIterator();
    for ( it->first(); !it->isDone(); it->next() )
    {
        std::cout << *it->current() << std::endl;
    }

    std::cout << "______________Iterator with custom class_________________";

    Container< Data > container2;
    Data a( 100 ), b( 1000 ), c( 10000 );
    container2.add( a );
    container2.add( b );
    container2.add( c );

    Iterator< Data, Container<Data> > *it2 = container2.createIterator();
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

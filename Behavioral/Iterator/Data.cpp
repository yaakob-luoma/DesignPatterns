#include "Data.h"


Data::Data( int a = 0 )
    : data(a)
{}

void Data::setData(int a )
{
    data = a;
}

int Data::getData()
{
    return data;
}

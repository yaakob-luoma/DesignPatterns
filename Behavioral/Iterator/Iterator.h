#ifndef ITERATOR_H
#define ITERATOR_H

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

#endif

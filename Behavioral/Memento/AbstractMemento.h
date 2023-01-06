#ifndef ABSTRACT_MEMENTO_H
#define ABSTRACT_MEMENTO_H

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif

class Memento
{
public:
    virtual std::string getName() const = 0;
    virtual std::string getDate() const = 0;
    virtual std::string getState() const = 0;
};

#endif

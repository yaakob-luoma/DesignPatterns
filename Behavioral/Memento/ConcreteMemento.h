#ifndef CONCRETE_MEMENTO_H
#define CONCRETE_MEMENTO_H

#ifndef INCLUDE_CTIME
#include <ctime>
#define INCLUDE_CTIME
#endif

#include "AbstractMemento.h"

class ConcreteMemento : public Memento
{
private:
    std::string state;
    std::string date;

public:
    ConcreteMemento( std::string state );

    std::string getState() const override;

    std::string getName() const override;

    std::string getDate() const override;

};

#endif

#ifndef CARETAKER_H
#define CARETAKER_H

#ifndef INCLUDE_VECTOR
#include <vector>
#define INCLUDE_VECTOR
#endif

#include "AbstractMemento.h"
#include "Originator.h"

class Caretaker
{
private:
    std::vector<Memento *> mementos;

    Originator *originator;

public:
    Caretaker( Originator *o );

    void backUp();

    void undo();

    void showHistory() const;

};

#endif

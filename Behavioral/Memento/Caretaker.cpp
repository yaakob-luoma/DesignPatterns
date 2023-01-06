#include "Caretaker.h"

Caretaker::Caretaker( Originator *o )
{
    this->originator = o;
}

void Caretaker::backUp()
{
    std::cout << "\nCaretaker: Saving Originator's state...\n";
    this->mementos.push_back(this->originator->save() );
}

void Caretaker::undo()
{
    if ( !this->mementos.size() )
    {
        return;
    }
    Memento *memento = this->mementos.back();
    this->mementos.pop_back();
    std::cout << "Caretaker: Restoring state to: " << memento->getName() << "\n";
    try
    {
        this->originator->restore( memento );
    }
    catch (...)
    {
        this->undo();
    }
}

void Caretaker::showHistory() const
{
    std::cout << "Caretaker: Here's the list of mementos:\n";
    for( Memento *memento : this->mementos )
    {
        std::cout << memento->getName() << "\n";
    }
}

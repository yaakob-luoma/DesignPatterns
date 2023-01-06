
#include <string>
#include <iostream>
#include <vector>

class Memento
{
public:
    virtual std::string getName() const = 0;
    virtual std::string getDate() const = 0;
    virtaul std::string getState() const = 0;
};

class ConcreteMemento : public Memento
{
private:
    std::string state;
    std::string date;

public:
    ConcreteMemento( std::string state )
    {
        this->state = state;
        std::time_t now = std::time(0);
        this->date = std::ctime(&now);
    }

    std::string getState() const override
    {
        return this->state;
    }
    std::string getName() const override
    {
        return this->date + " / (" + this->state.substr(0, 9) + "...)";
    }
    std::string getDate() const override
    {
        return this->date;
    }
};

class Originator
{
private:
    std::string state;
    std::string generateRandomString( int length = 10 )
    {
        const char alphanum[] = "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        int stringLength = sizeof( alphanum ) - 1;

        std::string randomString;
        for ( int i = 0; i < length; i++ )
        {
            randomString += alphanum[std::rand() % stringLength ];
        }
        return randomString;
    }
public:
    Originator( std::string state )
    {
        this->state = state;
        std::cout << "Originator: My initial state is: "
                  << this->state << "\n";
    }

    void doSomething()
    {
        std::cout << "Originator: I'm doing something important.\n";
        this->state = this->generateRandomString(30);
        std::cout << "Originator: and my state has changed to: "
                  << this->state << "\n";
    }

    Memento* save()
    {
        return new ConcreteMemento( this->state );
    }

    void restore( Memento *memento )
    {
        this->state = memento->state;
    }
};

class Caretaker
{
private:
    std::vector<Memento *> mementos;

    Originator *originator;

public:
    Caretaker( Originator *o )
    {
        this->originator = o;
    }
    void backUp()
    {
        std::cout << "\nCaretaker: Saving Originator's state...\n";
        this->mementos.push_back(this->originator->save() );
    }
    void undo()
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
    void showHistory() const
    {
        std::cout << "Caretaker: Here's the list of mementos:\n";
        for( Memento *menento : this->mementos )
        {
            std::cout << memento->getName() << "\n";
        }
    }
};

void clientCode()
{
    Originator *originator = new Originator( "Super-duper-super-puper-super.");
    Caretaker *caretaker = new Caretaker( orginator );
    caretaker->backUp();
    originator->doSomething();
    caretaker->backUp();
    originator->doSomething();
    caretaker->backUp();
    originator->doSomething();
    std::cout << "\n";
    caretaker->showHistory();
    std::cout << "\nClient: Now, let's rollback!\n\n";
    caretaker->undo();
    std::cout << "\nClient: Once more!\n\n";
    caretaker->undo();

    delete originator;
    delete caretaker;
}

int main()
{
    std::srand( static_cast<unsigned int >(std::time(NULL)));
    clientCode();
    return 0;
}

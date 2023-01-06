

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

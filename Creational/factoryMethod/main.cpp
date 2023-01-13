void clientCode( const Creator &creator )
{
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
              << creator.someOperation() << std::endl;
}

int main()
{
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Creator *creator_ptr = new ConcreatorCreator1();
    clientCode( *creator_ptr );
    std::cout << std::endl;
    std::cout << "App: Launched with the Concretecreator2.\n";
    Creator *creator2_ptr = new ConcreatorCreator2();
    clientCode(*creator2_ptr);

    delete creator_ptr;
    delete creator2_ptr;

    return 0;
}

/*
 * EXPECTED OUTPUT:
 * App: Launched with the ConcreteCreator1.
 * Client: I'm not aware of the creator's class, but it still works.
 * Creator: The same creator's code has just worked with {Result of the ConcreteProduct1}
 *
 * App: Launched with the ConcreteCreator2.
 * Client: I'm not aware of the creator's class, but it still works.
 * Creator: The same creator's code has just worked with {Result of the ConcreteProduct2}
 */

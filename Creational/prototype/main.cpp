
#include <iostream>

void client( PrototypeFactory &prototypeFactory)
{
    std::cout << "Let's create a Prototype 1\n";
    Prototype *prototype_ptr = prototypeFactory.createPrototype(Type::PROTOTYPE_1);
    prototype_ptr->method(90);
    delete prototype_ptr;

    std::cout << "\n";

    std::cout << "Let's create a Prototype 2\n";

    prototype_ptr = prototypeFactory.createPrototype(Type::PROTOTYPE_2);
    prototype_ptr->method(10);
    delete prototype_ptr;
}

int main()
{
    PrototypeFactory *prototypeFactory_ptr = new PrototypeFactory();
    client(*prototypeFactory_ptr);
    delete prototypeFactory_ptr;

    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Let's create a Prototype 1
 * Call Method from Prototype1 with field : 90
 *
 * Let's create a Prototype 2
 * Call Method from Prototype2 with field : 10
 */

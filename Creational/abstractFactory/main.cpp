#include <iostream>

#include "abstractproducta.h"
#include "abstractproductb.h"


void clientCode( const AbstractFactory &factory )
{
    const AbstractProductA *productA_ptr = factory.createProductA();
    const AbstractProductB *productB_ptr = factory.createProductB();
    std::cout << productB_ptr->usefulFunctionB() << "\n";
    std::cout << productB_ptr->anotherUsefulFunctionB(productA_ptr) << "\n";
    delete productA_ptr;
    delete productB_ptr;
}

int main()
{
    std::cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1 *f1_ptr = new ConcreteFactory1();
    clientCode(*f1_ptr);
    delete f1;
    std::cout << std::endl;
    std::cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2 *f2_ptr = new ConcreteFactory2();
    clientCode(*f2_ptr);
    delete f2;
    return 0;
}

/*
 * EXPECTED OUTPUT:
 * Client: Testing client code with the first factory type:
 * The result of the product B1.
 * The result of the B1 collaborating with the (The result of the product A1.)
 *
 * Client: Testing the same client code with the second factory type:
 * The result of the product B2.
 * The result of the B2 collaborating with the (The result of the product A2.)
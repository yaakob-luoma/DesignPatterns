
void clientCode(Director &director)
{
    ConcreteBuilder1 *builder_ptr = new ConcreteBuilder1();
    director.setBuilder(builder_ptr);
    std::cout << "Standard basic product:\n";
    director.buildMinimalViableProduct();

    Product1 *product_ptr = builder_ptr->getProduct();
    product_ptr->listParts();
    delete product_ptr;

    std::cout << "Standard full featured product:\n";
    director.buildFullFeaturedProduct();

    product_ptr = builder_ptr->getProduct();
    product_ptr->listParts();
    delete product_ptr;

    std::cout << "Custom product:\n";
    builder_ptr->productPartA();
    builder_ptr->productPartC();
    product_ptr = builder_ptr->getProduct();
    product_ptr->listParts();
    delete  product_ptr;

    delete builder_ptr;
}

int main()
{
    Director *director_ptr = new Director();
    clientCode( *director_ptr );
    delete director_ptr;
    return 0;
}

/*
 *EXPECTED OUTPUT:
 *Standard basic product:
 *Product parts: PartA1
 *
 *Standard full featured product:
 *Product parts: PartA1, PartB1, PartC1
 *
 *Custom product:
 *Product parts: PartA1, PartC1
 *
 */
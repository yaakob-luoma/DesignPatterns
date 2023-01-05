
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Product1
{
public:
    std::vector< std::string > parts;
    void listParts() const
    {
        std::cout << "Product parts: ";
        for ( size_t i = 0; i < parts.size(); i++ )
        {
            if ( parts[i] == parts.back() )
            {
                std::cout << parts[i];
            }
            else
            {
                std::cout << parts[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};

class Builder
{
public:
    virtual ~Builder() {}
    virtual void productPartA() const = 0;
    virtual void productPartB() const = 0;
    virtual void productPartC() const = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
    Product1 *product_ptr;
public:
    ConcreteBuilder1()
    {
        reset();
    }
    ~ConcreteBuilder1()
    {
        delete product_ptr;
    }

    void reset()
    {
        product_ptr = new Product1();
    }
    void productPartA() const override
    {
        product_ptr->push_back("PartA1");
    }
    void productPartB() const override
    {
        product_ptr->push_back("PartB1");
    }
    void productPartC() const override
    {
        product_ptr->push_back("PartC1");
    }

    Product1 *getProduct()
    {
        Product1 *result_ptr = product_ptr;
        reset();
        return result_ptr;
    }
};

class Director
{
private:
    Builder *builder_ptr;
public:
    void setBuilder(Builder *builder)
    {
        builder_ptr = builder;
    }
    void buildMinimalViableProduct()
    {
        builder_ptr->productPartA();
    }

    void buildFullFeaturedProduct()
    {
        builder_ptr->productPartA();
        builder_ptr->productPartB();
        builder_ptr->productPartC();
    }
};

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

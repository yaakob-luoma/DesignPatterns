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
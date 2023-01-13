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
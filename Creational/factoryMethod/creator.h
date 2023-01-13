class Creator
{
public:
    virtual ~Creator(){}
    virtual Product* factoryMethod() const = 0;

    std::string someOperation() const
    {
        Product *product_ptr = factoryMethod();
        std::string result = "Creator: The same creator's code has just worked with "
                + product_ptr->operation();
        delete product_ptr;
        return  result;
    }
};
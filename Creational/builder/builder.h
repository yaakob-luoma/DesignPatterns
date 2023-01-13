class Builder
{
public:
    virtual ~Builder() {}
    virtual void productPartA() const = 0;
    virtual void productPartB() const = 0;
    virtual void productPartC() const = 0;
};
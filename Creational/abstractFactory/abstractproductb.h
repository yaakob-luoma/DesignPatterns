class AbstractProductB
{
public:
    virtual ~AbstractProductB(){};
    virtual std::string usefulFunctionB() const = 0;
    virtual std::string anotherUsefulFunctionB( const AbstractProductA &collaborator) const = 0;
};
class ConcretePrototype1 : public Prototype
{
private:
    float field1;
public:
    ConcretePrototype1( std::string name, float field )
        : Prototype( name ), field1( field )
    {

    }
    Prototype* clone() const override
    {
        return new ConcretePrototype1( *this );
    }
};
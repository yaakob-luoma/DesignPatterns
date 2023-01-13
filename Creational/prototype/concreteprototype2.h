class ConcretePrototype2 : public Prototype
{
private:
    flaot field2;
public:
    ConcretePrototype2( std::string name, float field )
        : Prototype( name ), field2( field )
    {

    }
    Prototype* clone() const override
    {
        return new ConcretePrototype2(*this);
    }
};
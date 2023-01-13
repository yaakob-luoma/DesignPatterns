enum Type
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class PrototypeFactory
{
private:
    std::unordered_map<Type, Prototype *, std::hash<int>> prototypes;

public:
    PrototypeFactory()
    {
        prototypes[Type::PROTOTYPE_1] = new ConcretePrototype1( "Prototype1 ", 50.f);
        prototypes[Type::PROTOTYPE_2] = new ConcretePrototype2( "Prototype2 ", 60.f);
    }
    ~PrototypeFactory()
    {
        delete prototypes[Type::PROTOTYPE_1];
        delete prototypes[Type::PROTOTYPE_2];
    }
    Prototype* createPrototype( Type type )
    {
        return prototypes[type].clone();
    }
};

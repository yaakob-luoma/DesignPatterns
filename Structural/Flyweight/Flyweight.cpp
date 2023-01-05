
#include <string>
#include <iostream>

struct SharedState
{
    std::string brand;
    std::string model;
    std::string color;

    SharedState( const std::string &brand
                 , const std::string &model
                 , const std::string &color)
    {
        this->brand = brand;
        this->model = model;
        this->color = color;
    }

    friend std::ostream& operator<<( std::ostream &os
                                     , const SharedState &ss)
    {
        return os << "[ " << ss.brand << " , "
                  << ss.model << " , "
                  << ss.color << " ]";
    }
};

struct UniqueState
{
    std::string owner;
    std::string plates;
    UniqueState( const std::string &owner
                 , const std::string &plates )
    {
        this->owner = owner;
        this->plates = plates;
    }
    friend std::ostream& operator<<(std::ostream &os
                                    , const UniqueState &us)
    {
        return os << "[ " << us.owner << " , " << us.plates << " ]";
    }
};

class Flyweight
{
private:
    SharedState *sharedState_ptr;

public:
    Flyweight( const SharedState *sharedState)
        : sharedState_ptr( new SharedState( *sharedState ) )
    {

    }
    Flyweight( const Flyweight &other )
        : sharedState_ptr( new SharedState( *other.sharedState_ptr))
    {

    }
    ~Flyweight()
    {
        delete sharedState_ptr;
    }
    SharedState* sharedState() const
    {
        return sharedState_ptr;
    }
    void operation( const UniqueState &uniqueState ) const
    {
        std::cout << "Flyweight: Displaying shared ("
                  << *sharedState_ptr
                  << " ) and unique ( "
                  << uniqueState
                  << ") state.\n";
    }
};

class FlyweightFactory
{
private:
    std::unordered_map<std::string, Flyweight> flyweigths;
    std::string getKey( const SharedState &ss ) const
    {
        return ss.brand + "_" + ss.model + "_" + ss.color;
    }
public:
    FlyweightFactory( std::initializer_list<SharedState> shareState)
    {
        for( const SharedState &ss : shareState )
        {
            this->flyweigths.insert(std::make_pair<std::string
                                    , Flyweight>(this->getKey(ss), Flyweight(&ss)));
        }
    }
    Flyweight getFlyweight( const SharedState &sharedState )
    {
        std::string key = this->getKey(sharedState);
        if ( this->flyweigths.find( key ) == this->flyweigths.end() )
        {
            std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
            this->flyweigths.insert( std::make_pair( key, Flyweight( &sharedState)));
        }
        else
        {
            std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
        }
        return this->flyweigths.at(key);
    }
    void listFlyweights() const
    {
        size_t count = this->flyweigths.size();
        std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
        for ( std::pair<std::string, Flyweight> pair : this->flyweights )
        {
            std::cout << pair.first << "\n";
        }
    }
};

void addCarToPoliceDatabase( FlyweightFactory &ff
                             , const std::string &plates
                             , const std::string &owner
                             , const std::string &brand
                             , const std::string &model
                             , const std::string &color )
{
    std::cout << "\nClient: Adding a car to database.\n";
    const Flyweight &flyweight = ff.getFlyweight( {brand, model, color});

    flyweight.operation( {owner, plates});
}

int main()
{
    FlyweightFactory *factory_ptr = new FlyweightFactory( {"Chevrolet", "Camaro2018", "black"}
                                                          , {"Mercedes Benz", "C300", "white"}
                                                          , {"Mercedes Benz", "C500", "red"}
                                                          , {"BMW", "M5", "red"}
                                                          , {"BMW", "X6", "white"});
    factory_ptr->listFlyweights();

    addCarToPoliceDatabase( *factory_ptr
                            , "CL234IR"
                            , "John Doe"
                            , "BMW"
                            , "M5"
                            , "red");
    addCarToPoliceDatabase( *factory_ptr
                            , "CL234IR"
                            , "John Doe"
                            , "BMW"
                            , "X1"
                            , "red");
    factory_ptr->listFlyweights();
    delete factory_ptr;
    return 0;
}

/*
 * EXPECTED OUTPUT:
 *
 */

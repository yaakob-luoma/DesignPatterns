
#include <string>
#include <list>
#include <algorithm>
#include <iostream>

class Componenet
{
protected:
    Componenet *parent_ptr;
public:
    virtual ~Componenet(){}
    void setParent( Componenet *parent )
    {
        parent_ptr = parent;
    }
    Componenet* getParent() const
    {
        return parent_ptr;
    }
    virtual void add( Componenet *component ){}
    virtual void remove( Componenet *component ){}
    virtual bool isComposite() const
    {
        return false;
    }
    virtual std::string operation() const = 0;
};

class Leaf : public Componenet
{
public:
    std::string operation() const override
    {
        return "Leaf";
    }
};

class Composite : public Componenet
{
protected:
    std::list< Componenet * > childern;
public:
    void add( Componenet *component ) override
    {
        childern.push_back(component);
        component->setParent( this );
    }
    void remove( Componenet *componenet ) override
    {
        childern.remove(componenet );
        componenet->setParent( nullptr );
    }
    bool isComposite() const override
    {
        return true;
    }
    std::string operation() const override
    {
        std::string result;
        for ( const Componenet *c : childern )
        {
            if ( c == childern.back() )
            {
                result += c->operation();
            }
            else
            {
                result += c->operation() + "+";
            }
        }
        return "Branch(" + result + ")";
    }
};

void clientCode( Componenet *componenet )
{
    std::cout << "RESULT: " << componenet->operation();
}

void clientCode2( Componenet *componenet1, Componenet *componenet2 )
{
    if ( componenet1->isComposite() )
    {
        componenet1->add( componenet2 );
    }
    std::string << "RESULT: " << componenet1->operation();
}

int main()
{
    Componenet *simple_ptr = new Leaf();
    std::cout << "Client: I've got a simple component:\n";
    clientCode( simple_ptr );
    std::cout << "\n\n";

    Componenet *tree = new Composite();
    Componenet *branch1 = new Composite();
    Componenet *leaf1 = new Leaf();
    Componenet *leaf2 = new Leaf();
    Componenet *leaf3 = new Leaf();
    branch1->add( leaf1 );
    branch1->add( leaf2 );
    Componenet *branch2 = new Composite;
    branch2->add( leaf3 );
    tree->add( branch1 );
    tree->add( branch2 );
    std::cout << "Client: Now I've got a composite tree:\n";
    clientCode( tree );
    std::cout << "\n\n";

    std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
    clientCode2( tree, simple );
    std::cout << "\n";

    delete simple_ptr;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf1;
    delete leaf2;
    delete leaf3;

    return 0;

}

/*
 * EXPECTED OUTPUT:
 * Client: I've got a simple component:
 * RESULT: Leaf
 *
 * Client: Now I've got a composite tree:
 * RESULT: Branch(Branch(Leaf+Leaf)+Branch(Leaf))
 *
 * Client: I don't need to check the components classes even when managing the tree:
 * RESULT: Branch(Branch(Leaf+Leaf)+Branch(Leaf)+Leaf)
 */

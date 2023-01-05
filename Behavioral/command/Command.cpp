
class Command
{
public:
    virtual ~Command(){};
    virtual void execute() const = 0;
};

class SimpleCommand : public Command
{
private:
    std::string payLoad;

public:
    explicit SimpleCommand( std::string payLoad )
    {
        this->payLoad = payLoad;
    }
    void execute() const override
    {
        std::cout << "SimpleCommand: See, I can do simple things like printing ("
                  << this->payLoad
                  << ")\n";
    }
};

class Receiver
{
public:
    void doSomething( const std::string &data)
    {
        std::cout << "Receiver: Working on ("
                  << data
                  << ".)\n";
    }
    void doSomethingElse( const std::string &data )
    {
        std::cout << "Receiver: Also working on("
                  << data
                  << ".)\n";
    }
};

class ComplexCommand : public Command
{
private:
    Receiver *receiver_ptr;
    std::string dataA;
    std::string dataB;

public:
    ComplexCommand( Receiver *receiver
                    , std::string a
                    , std::string b)
        : receiver_ptr(receiver)
        , dataA(a)
        , dataB(b)
    {

    }
    void execute() const override
    {
        std::cout << "ComplexCommand: Complex stuff should be done by a receiver object.\n";
        this->receiver_ptr->doSomething(dataA);
        this->receiver_ptr->doSomethingElse(dataB);
    }
};

class Invoker
{
private:
    Command *onStart;
    Command *onFinish;

public:
    ~Invoker()
    {
        delete onStart;
        delete onFinish;
    }

    void setOnStart( Command *command )
    {
        this->onStart = command;
    }
    void setOnFinish( Command *command )
    {
        this->onFinish = command;
    }
    void doSomethingImportant()
    {
        std::cout << "Invoker: Does anybody want something done before I begin?\n";
        if (this->onStart )
        {
            this->onStart->execute();
        }
        std::cout << "Invoker: ...doing something really important...\n";
        std::cout << "Invoker: Does anybody want something done after I finish?\n";
        if (this->onFinish )
        {
            this->onFinish->execute();
        }
    }
};

int main()
{
    Invoker *invoker = new Invoker();
    invoker->setOnStart( new SimpleCommand("Say Hi!"));
    Receiver *receiver = new Receiver();
    invoker->setOnFinish(new ComplexCommand(receiver, "Send email", "Save report"));
    invoker->doSomethingImportant();

    delete invoker;
    delete receiver;
}

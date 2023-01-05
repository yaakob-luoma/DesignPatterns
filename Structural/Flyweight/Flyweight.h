#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H


class Flyweight
{
public:
    Flyweight();
    virtual ~Flyweight();

    virtual void action();

protected:
    Flyweight();
};

#endif // FLYWEIGHT_H

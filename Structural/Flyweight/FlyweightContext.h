#ifndef FLYWEIGHTCONTEXT_H
#define FLYWEIGHTCONTEXT_H


class FlyweightContext
{
public:
    FlyweightContext();
    virtual ~FlyweightContext();

    virtual void next();
    virtual void insert();

private:
    int _index;

};

#endif // FLYWEIGHTCONTEXT_H

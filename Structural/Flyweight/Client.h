#ifndef CLIENT_H
#define CLIENT_H

#include "FlyweightFactory.h"

class Client
{
public:
    Client();
    ~Client();

private:
    FlyweightFactory factory;

};

#endif // CLIENT_H

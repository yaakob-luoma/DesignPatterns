#ifndef RECEIVER_H
#define RECEIVER_H

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif


class Receiver
{
public:
    void doSomething( const std::string &data );
    void doSomethingElse( const std::string &data );
};

#endif

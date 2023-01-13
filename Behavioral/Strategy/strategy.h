#include <string>
#include <vector>

class Strategy
{
public:
    virtual ~Strategy(){}
    virtual std::string algorithm( const std::vector< std::string > &data ) const = 0;
};
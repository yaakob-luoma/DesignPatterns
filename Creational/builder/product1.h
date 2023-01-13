#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Product1
{
public:
    std::vector< std::string > parts;
    void listParts() const
    {
        std::cout << "Product parts: ";
        for ( size_t i = 0; i < parts.size(); i++ )
        {
            if ( parts[i] == parts.back() )
            {
                std::cout << parts[i];
            }
            else
            {
                std::cout << parts[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};

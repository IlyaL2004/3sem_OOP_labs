#pragma onces

#include <string>
#include <iostream>
using namespace std;

class Decimal
{ 
public:    
    Decimal();
    Decimal(const size_t & n, unsigned char t = 0);
    Decimal(const std::initializer_list< unsigned char> &t);
    Decimal(const std::string &t);
    Decimal(const Decimal& other);
    Decimal(Decimal&& other) noexcept;

    Decimal add(const Decimal& other);
    Decimal remove(const Decimal& other);
    bool equal(const Decimal& other) const;
    bool big(const Decimal &other) const;
    bool small(const Decimal &other) const;
    std::ostream& print(std::ostream& os);

    virtual ~Decimal() noexcept;
private:
    size_t _size;
    unsigned char *_array;

};

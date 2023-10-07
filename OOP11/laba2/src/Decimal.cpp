#include "Decimal.h"


static size_t number(const unsigned char t){
    if(t<='9' and t>='0') return t-'0';
    return 10;
}

static unsigned char chr(size_t t){
    return t+'0';
}

Decimal::Decimal() : _size(0), _array{nullptr}{}

Decimal::Decimal(const size_t &n, unsigned char t)
{
    if(n == 0) throw logic_error("no number was given");
    if(not(t<='9' and t>='0'))throw logic_error("decimal number");
    _array = new unsigned char[n];
    for (size_t i = 0; i < n; ++i)
        _array[i] = t;
    _size = n;
}

Decimal::Decimal(const initializer_list<unsigned char> &t)
{   
    if(t.size() == 0) throw logic_error("no number was given");
    _array = new unsigned char[t.size()];
    size_t i{t.size()-1};
    for (auto c : t)
        if((c<='9' and c>='0')) _array[i--] = c;
        else throw logic_error("decimal number");
    _size = t.size();

    for(size_t i = _size - 1; _array[i] == '0' and i > 0; --i){
        _size--;
    }
}

Decimal::Decimal(const string &t)
{
    if(t.size() == 0) throw logic_error("no number was given");
    else{
        _array = new unsigned char[t.size()];
        _size  = t.size();

        for(size_t i{0}; i < _size; ++i){
            if(t[_size - 1 - i]<='9' and t[_size - 1 - i]>='0')_array[i] = t[_size - 1 - i];
            else throw logic_error("decimal number");
        }

        for(size_t i = _size - 1; _array[i] == '0' and i > 0; --i){
            _size--;
    }
    }
}

Decimal::Decimal(const Decimal &other)
{
    _size  = other._size;
    _array = new unsigned char[_size];

    for(size_t i{0};i<_size;++i) _array[i] = other._array[i];
}

Decimal::Decimal(Decimal &&other) noexcept
{
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Decimal::~Decimal() noexcept
{
    if (_size > 0)
    {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

bool Decimal::equal(const Decimal &other) const
{
    size_t equal_size;
    if(_size==other._size){
        equal_size = _size;
        while(equal_size != 0){
            if(!(number(_array[equal_size-1]) == number(other._array[equal_size-1])))
                return false;
            equal_size--;
        }
    }
    return true;
}

bool Decimal::big(const Decimal &other) const
{   
    size_t maxim_size;
    if(this->_size > other._size)
        return true;
    else if(this->equal(other) || this->_size < other._size)
        return false;
    else{
        maxim_size = _size;
        while(maxim_size != 0){
            if (number(this->_array[maxim_size-1]) < number(other._array[maxim_size-1]))
            return false;
            maxim_size--;
        }
        return true;
    }
}

bool Decimal::small(const Decimal &other) const
{
    return !(this->equal(other) || this->big(other));
}



Decimal Decimal::add(const Decimal &other)
{   
    size_t maxim_size, minim_size;
    size_t sum_numbers = 0, move_up_rank = 0;
    size_t i = 0;
    string the_big_mass = "";

    if(this->big(other)){
        maxim_size = _size;
        minim_size = other._size;
        the_big_mass = "first";
    }
    else if(this->small(other)){
        maxim_size = other._size;
        minim_size = _size;
        the_big_mass = "second";
    }
    else{
        maxim_size = _size;
        minim_size = _size;
        the_big_mass = "equal";
    }

    Decimal sum(maxim_size+1, '0'); 
    
    while(i < maxim_size){
        if(i < minim_size){
            sum_numbers = move_up_rank + number(_array[i]) + number(other._array[i]);
            move_up_rank = sum_numbers / 10;
            sum._array[i] = chr(sum_numbers % 10);
        }
        else{
            if(the_big_mass == "first" || the_big_mass == "equal")
                sum_numbers = move_up_rank + number(_array[i]);
            else if(the_big_mass == "second")
                sum_numbers = move_up_rank + number(other._array[i]);
            move_up_rank = sum_numbers / 10;
            sum._array[i] = chr(sum_numbers % 10);
        }
        i++;
    }

    if(move_up_rank != 0){
        sum._array[maxim_size] = move_up_rank;
    }
    else{
        --sum._size;
    }
    
    this->_size = sum._size;

    i = 0;

    while(i < sum._size){
        this->_array[i] = sum._array[i];
        i++;
    }
   
    return *this;
}

Decimal Decimal::remove(const Decimal &other)
{
    if(this->small(other)){
        throw logic_error("Результат не может быть отрицательным");
    }
    else{
        size_t remove_numbers = 0, move_down_rank = 0;
        size_t i = 0;
        size_t minim_size = other._size;
        while(i < minim_size){
            remove_numbers = number(_array[i]) - number(other._array[i]) - move_down_rank;
            if(remove_numbers < 0){
                move_down_rank = 1;
                remove_numbers = 10 + remove_numbers;
            }else{
                move_down_rank = 0;
            }
            _array[i] = chr(remove_numbers);
            i++;
        }
        
        i = other._size;
        while(move_down_rank !=0){
            remove_numbers = number(_array[i]) - move_down_rank;
            if(remove_numbers < 0){
                move_down_rank = 1;
                remove_numbers = 10 + move_down_rank;
            }else{
                move_down_rank = 0;
            }
            _array[i] = chr(remove_numbers); 
            ++i;
        }

        i = _size - 1;

        while(_array[i] == '0' && i>0){
            --_size;
            --i;
        }
    }
    return *this;
}

std::ostream &Decimal::print(std::ostream &os)
{   
    for (size_t i = 1; i <= _size; ++i)
        os << _array[_size - i];
    return os;
}
